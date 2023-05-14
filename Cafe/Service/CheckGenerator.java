package Cafe.Service;

import Cafe.DataModel.CartItem;
import Cafe.DataModel.Drink;
import Cafe.DataModel.Pizza;
import Cafe.DataModel.Product;

import java.util.ArrayList;

public class CheckGenerator {

    private double checkPrice;

    public double getCheckPrice() {
        return checkPrice;
    }

    public CheckGenerator(ArrayList<CartItem> cart){
        double pizzaPrice = 0;
        double drinkPrice = 0;

        int pizzaCounter = 0;
        int drinkCounter = 0;

        for (CartItem cartItem : cart) {
            Class<? extends Product> productClass = cartItem.getProduct().getClass();

            Product product = cartItem.getProduct();
            int price = product.getPrice();
            int amount = cartItem.getAmount();

            if (productClass == Pizza.class) {
                for(int pizzaIndex = 0;pizzaIndex < amount;pizzaIndex++) {
                    pizzaCounter++;

                    if (pizzaCounter == 5) {
                        pizzaCounter = 0;
                    } else {
                        pizzaPrice += price;
                    }
                }
            } else {
                drinkPrice += price * amount;

                if(price > 2){
                    drinkCounter+=amount;
                }
            }
        }

        checkPrice = drinkPrice + pizzaPrice;



        double multiplier = 1;

        if(checkPrice > 50) {
            multiplier = 0.8;
        }

        for (CartItem cartItem : cart) {
            int amount = cartItem.getAmount();
            int price = cartItem.getProduct().getPrice();
            cartItem.setPrice(amount * price * multiplier);
        }

        checkPrice *= multiplier;

        if(drinkCounter > 2){

            cart.stream().filter(cartItem -> {
                Product product = cartItem.getProduct();
                Class<? extends Product> productClass = product.getClass();
                int price = product.getPrice();
                return productClass == Drink.class && price > 2;
            }).forEach(cartItem -> {
                double price = cartItem.getPrice();
                double newPrice = price * 0.85;
                cartItem.setPrice(newPrice);
                checkPrice -= price - newPrice;
            });

        }

    }

}
