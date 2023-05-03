
#ifndef CAFE_CALCULATE_H
#define CAFE_CALCULATE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;


double CalculateDrinkDiscount(double price, int quantity) {
    if (price > 2.0 && quantity > 3) {
        return 0.15 * price * quantity;
    }
    return 0.0;
}


double CalculateTotalPrice(vector<Product>& products) {
    double totalPrice = 0.0;
    int pizzaQuantity = 0;

    for (Product& product : products) {
        totalPrice += product.price * product.quantity;
        if (product.name.find("Пицца") != string::npos) { // Если товар - пицца
            pizzaQuantity += product.quantity;
        }
    }


    int freePizzaCount = pizzaQuantity / 5;
    totalPrice -= freePizzaCount * products[0].price;


    for (Product& product : products) {
        if (product.name.find("Напиток") != string::npos) { // Если товар - напиток
            double drinkDiscount = CalculateDrinkDiscount(product.price, product.quantity);
            totalPrice -= drinkDiscount;
        }
    }


    if (totalPrice > 50.0) {
        totalPrice *= 0.8;
    }

    return totalPrice;
}



#endif //CAFE_CALCULATE_H
