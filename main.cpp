#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
#include "Print.h"
#include "Calculate.h"
using namespace std;



void ChooseProduct(vector<Product>& product) {
    int code = InputCode();
    int count = InputQuantity();

    switch (code) {
        case 1:
            product.push_back({1, "Пицца Маргарита", 10.0, count});
            break;
        case 2:
            product.push_back({2, "Пицца Пепперони", 12.0, count});
            break;
        case 3:
            product.push_back({3, "Пицца Гавайская", 13.0, count});
            break;
        case 4:
            product.push_back({4, "Пицца Мексиканская", 15.0, count});
            break;
        case 5:
            product.push_back({5, "Напиток Кола", 1.5, count});
            break;
        case 6:
            product.push_back({6, "Напиток Фанта", 1.5, count});
            break;
        case 7:
            product.push_back({7, "Напиток Сок", 2.0, count});
            break;
        default:
            cout << "Товар с таким кодом отсутствует в меню.\n";
            break;
    }
}


void DisplayMenu() {
    cout << "Меню:\n";
    cout << "1. Пицца Маргарита - 10.0 руб.\n";
    cout << "2. Пицца Пепперони - 12.0 руб.\n";
    cout << "3. Пицца Гавайская - 13.0 руб.\n";
    cout << "4. Пицца Мексиканская - 15.0 руб.\n";
    cout << "5. Напиток Кола - 1.5 руб.\n";
    cout << "6. Напиток Фанта - 1.5 руб.\n";
    cout << "7. Напиток Сок - 2.0 руб.\n";
}


void MakeOrder() {
    vector<Product*> products;


    DisplayMenu();


    while (true) {
        ChooseProduct(products);


        char chose;
        do {
            cout << "Продолжить добавление товаров? (Y/Да, N/н): ";
            cin >> chose;
        } while (chose != 'Y' && chose != 'y' && chose != 'N' && chose != 'n');

        if (chose == 'N' || chose == 'n') {
            break;
        }
    }


    double totalPrice = CalculateTotalPrice(products);


    PrintReceipt(products, totalPrice);
}



int main() {
    Product product;
    InputCode ();
    InputQuantity ();
    MakeOrder();



    return 0;
}
