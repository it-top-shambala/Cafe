#pragma once

#include <string>

#include "Pizzas.h"
#include "Drinks.h"

using namespace std;

struct Order {
	Pizzas pizzas;
	int pizzaCount;
	Drinks drinks;
	int drinkCount;
	double total;
};