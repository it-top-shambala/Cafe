

#ifndef CAFE_PRINT_H
#define CAFE_PRINT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;



void PrintReceipt(vector<Product>& products, double totalPrice) {
    cout << "Чек:\n";
    cout << "--------------------------------------------------\n";
    cout << "Код  Название товара    Цена                Кол-во\n";
    cout << "--------------------------------------------------\n";
    for (const auto& product : products) {
        cout << product.code <<"\t "
             << product.name<< "  "
             << product.price <<"\t\t"
             << product.quantity <<"\n";
    }
    cout << "--------------------------------------------------\n";
    cout << "Общая стоимость: "  << totalPrice << " рублей\n";
    cout << "--------------------------------------------------\n";
}








#endif //CAFE_PRINT_H
