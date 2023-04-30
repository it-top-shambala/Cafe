#ifndef CAFE_PRODUCT_H
#define CAFE_PRODUCT_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Product {
    int code;
    string name;
    double price;
    int quantity;
};


int InputCode() {
    int code;
    cout << "Введите код товара: ";
    cin >> code;
    return code;
}


int InputQuantity() {
    int quantity;
    cout << "Введите количество единиц товара: ";
    cin >> quantity;
    return quantity;
}





#endif //CAFE_PRODUCT_H
