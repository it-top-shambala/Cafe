#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Order.h"
#include "Menu.h"

using namespace std;

void PrintMenu() {
    cout << "����: " << endl;
    for (Pizza pizza : pizzas) {
        cout << pizza.code << ". " << pizza.name << " - " << pizza.price << endl;
    }
    for (Drink drink : drinks) {
        cout << drink.code << ". " << drink.name << " - " << drink.price << endl;
    }
}

void GetProductAndQuantity(char& choice, int& quantity) {
    cout << "������� ��� �������� � �����������: " << endl;
    cin >> choice >> quantity;
}

void PrintCheck(Order& order) {
    cout << "���:" << endl;
    for (int i = 0; i < order.pizzaCount; i++) {
        cout << pizzas[order.pizzas[i].code - 1].name << " - " << order.pizzas[i].price << endl;
    }
    for (int i = 0; i < order.drinkCount; i++) {
        cout << drinks[order.drinks[i].code - 5].name << " - " << order.drinks[i].price << endl;
    }
    cout << "�����: " << order.total << endl;
}

