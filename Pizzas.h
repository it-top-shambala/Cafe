#pragma once

#include <string>
#include <vector>

using namespace std;

struct Pizza {
	int code;
	string name;
	double price;
};

using Pizzas = vector<Pizza>;