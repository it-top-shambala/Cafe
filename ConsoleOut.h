#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Order.h"
#include "Menu.h"

using namespace std;

void PrintMenu() {
	cout << "Menu: " << endl;
	for (Pizza pizza : pizzas) {
		cout << pizza.code << ". " << pizza.name << " - " << pizza.price << endl;
	}
	for (Drink drink : drinks) {
		cout << drink.code << ". " << drink.name << " - " << drink.price << endl;
	}
}