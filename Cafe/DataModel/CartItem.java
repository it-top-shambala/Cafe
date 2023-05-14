package Cafe.DataModel;

public class CartItem {

    private int amount;
    private double price;
    private Product product;

    public CartItem(int amount, Product product){
        this.amount = amount;
        this.product = product;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public Product getProduct() {
        return product;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return  "Наименование - " + product.getName() +
                ", количество - " + amount +
                ", цена - " + price;
    }


}
