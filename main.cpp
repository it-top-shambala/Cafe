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

	char choice;
	int quantity;

	cout << "Добро пожаловать в Наш pizza shop!" << endl;

	string userName;
	cout << "Пожалуйста введите Ваше имя: ";
	cin >> userName;
	cout << "Здравствуйте, " << userName << "!" << endl;

	PrintMenu();

	do {
		GetProductAndQuantity(choice, quantity);
		AddToOrder(order, choice, quantity);

		cout << "Хотите продожить заказ? (y/n) ";
		cin >> choice;
	} while (choice == 'y');

	ProcessOrder(order, quantity);

	PrintCheck(order);

	cout << "Спасибо за Ваш заказ, " << userName << "!" << endl;

	return 0;
}