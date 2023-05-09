#include <string>
#include <iostream>
#include <vector>

#include "Order.h"
#include "Menu.h"
#include "ConsoleOut.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	Order order;
	order.total = 0;
	order.pizzaCount = 0;
	order.drinkCount = 0;

	PrintMenu();

	char choice;
	int quantity;

	do {
		cout << "Введите код продукта и колличество: " << endl;
		cin >> choice >> quantity;
		if (choice >= pizzas[0].code && choice <= pizzas[1].code) {
			order.pizzas[order.pizzaCount].code = choice;
			order.pizzas[order.pizzaCount].price = pizzas[choice - 1].price;
			order.pizzaCount++;
			order.total += quantity * pizzas[choice - 1].price;
		}
		else if (choice >= drinks[0].code && choice <= drinks[1].code) {
			order.drinks[order.drinkCount].code = choice;
			order.drinks[order.drinkCount].price = drinks[choice - 101].price;
			order.drinkCount++;
			order.total += quantity * drinks[choice - 101].price;
		}

		cout << "Хотите продолжить заказ? (y/n) ";
		cin >> choice;
	} while (choice == 'y');

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
			order.total -= (order.drinks[i].price - drinks[order.drinks[i].code - 101].price) * quantity;
		}
	}

	cout << "Заказ: " << endl;
	for (int i = 0; i < order.pizzaCount; i++) {
		cout << order.pizzas[i].name << " - " << order.pizzas[i].price << endl;
	}

	for (int i = 0; i < order.drinkCount; i++) {
		cout << order.drinks[i].name << " - " << order.drinks[i].price << endl;
	}

	cout << "Итого: " << order.total << endl;

	cout << "Спасибо за ваш заказ!";

	return 0;
}