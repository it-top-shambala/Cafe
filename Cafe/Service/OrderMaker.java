package Cafe.Service;

import Cafe.DataModel.CartItem;
import Cafe.DataModel.Product;
import java.util.ArrayList;
import java.util.Scanner;


public class OrderMaker {

    public void makeOrder() {
        Menu menu = new Menu();
        ArrayList<Product> menuList = menu.menuList;
        ArrayList<CartItem> cart = new ArrayList<>();

        Scanner keyboardScanner = new Scanner(System.in);

        int code;

        while(true){
            System.out.println("\n-1. Выход");
            System.out.println("0. Получить чек");
            for(int productCode = 1;productCode <= menuList.size();productCode++){
                Product menuItem = menuList.get(productCode - 1);
                System.out.println(productCode + ". " + menuItem);
            }

            System.out.print("Выберите номер продукта - ");
            code = keyboardScanner.nextInt();

            if(code == -1) {
                break;
            }

            if(code == 0){
                System.out.println("\nВаш чек:");
                CheckGenerator checkGenerator = new CheckGenerator(cart);
                double checkPrice = checkGenerator.getCheckPrice();
                cart.forEach(System.out::println);
                System.out.println("\nИтого к оплате - " + checkPrice);
                cart.clear();
                continue;
            }

            if(code > 0 && code <= menuList.size() + 1) {
                Product currentMenuItem = menuList.get(code - 1);

                System.out.print("Введите количество - ");
                int amount = keyboardScanner.nextInt();

                if(amount < 0){
                    System.out.println("Нельзя вводить отрицательные числа");
                } else {

                    CartItem existingCartItem = cart.stream().filter(cartItem -> {
                        Product currentCartProduct = cartItem.getProduct();
                        return currentCartProduct.equals(currentMenuItem);
                    }).findFirst().orElse(null);

                    if(existingCartItem != null) {
                        int existingAmount = existingCartItem.getAmount();
                        existingCartItem.setAmount(existingAmount + amount);
                    } else {
                        CartItem cartItem = new CartItem(amount, currentMenuItem);
                        cart.add(cartItem);
                    }

                }

            } else {
                System.out.println("Такого продукта нет");
            }
        }
    }

}
