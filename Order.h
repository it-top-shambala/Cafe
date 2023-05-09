#pragma once

#include <string>

#include "Menu.h"
#include "Pizzas.h"
#include "Drinks.h"
#include "ConsoleOut.h"

using namespace std;

struct Order {
    Pizzas pizzas;
    int pizzaCount;
    Drinks drinks;
    int drinkCount;
    double total;
};

void AddToOrder(Order& order, char choice, int quantity) {
    if (choice >= pizzas[0].code && choice <= pizzas[4].code) {
        order.pizzas[order.pizzaCount].code = choice;
        order.pizzas[order.pizzaCount].price = pizzas[choice - 1].price;
        order.pizzaCount++;
        order.total += quantity * pizzas[choice - 1].price;
    }
    else if (choice >= drinks[0].code && choice <= drinks[2].code) {
        order.drinks[order.drinkCount].code = choice;
        order.drinks[order.drinkCount].price = drinks[choice - 5].price;
        order.drinkCount++;
        order.total += quantity * drinks[choice - 5].price;
    }
}

void ProcessOrder(Order& order, int& quantity) {

    if (order.pizzaCount >= 5) {
        order.pizzas[order.pizzaCount].price = 0;
        order.pizzaCount++;
        order.total -= pizzas[0].price;
    }

    if (order.total > 50) {
        order.total *= 0.8;
    }

    for (int i = 0; i < order.drinkCount; i++) {
        if (order.drinks[i].price > 2 && quantity > 3) {
            order.drinks[i].price *= 0.85;
            order.total -= (order.drinks[i].price - drinks[order.drinks[i].code - 5].price) * quantity;
        }
    }
}