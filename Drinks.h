#pragma once

#include <vector>
#include <string>

using namespace std;

struct Drink {
	int code;
	string name;
	double price;
	bool discount;
};

using Drinks = vector<Drink>;