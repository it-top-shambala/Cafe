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

	cout << "����� ���������� � ��� pizza shop!" << endl;

	string userName;
	cout << "���������� ������� ���� ���: ";
	cin >> userName;
	cout << "������������, " << userName << "!" << endl;

	PrintMenu();

	do {
		GetProductAndQuantity(choice, quantity);
		AddToOrder(order, choice, quantity);

		cout << "������ ��������� �����? (y/n) ";
		cin >> choice;
	} while (choice == 'y');

	ProcessOrder(order, quantity);

	PrintCheck(order);

	cout << "������� �� ��� �����, " << userName << "!" << endl;

	return 0;
}