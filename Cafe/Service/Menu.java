package Cafe.Service;

import Cafe.DataModel.Drink;
import Cafe.DataModel.Pizza;
import Cafe.DataModel.Product;

import java.util.ArrayList;
import java.util.Collections;

public class Menu {

    public ArrayList<Product> menuList = new ArrayList<>();

    public Menu() {
        Pizza pepperoni = new Pizza(4, "Пепперони");
        Pizza fourCheeses = new Pizza(3, "Четыре сыра");
        Pizza barbeque = new Pizza(5, "Барбекю");
        Pizza pesto = new Pizza(3, "Песто");
        Drink lemonade = new Drink(1, "Лимонад");
        Drink cola = new Drink(2, "Кола");
        Drink mojito = new Drink(3, "Мохито");

        Collections.addAll(menuList, pepperoni, fourCheeses, barbeque, pesto, lemonade, cola, mojito);
    }

}
