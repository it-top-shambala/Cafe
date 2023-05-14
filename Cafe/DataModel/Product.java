package Cafe.DataModel;

abstract public class Product {

    final private int price;
    final private String name;

    public Product(int price, String name) {
        this.price = price;
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return  "Наименование - " + name +
                ", цена - " + price;
    }
}
