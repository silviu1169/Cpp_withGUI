#pragma once
#include <vector>

#include "Product.h"

using namespace std;

class ProductValidator{
public:
	void validation(const Product& p);
};

class ValidationExceptions {
	vector <string> mesage;
public:
	ValidationExceptions(vector<string> msg) : mesage{ msg } {}
	friend ostream& operator<<(ostream& out, const ValidationExceptions& ex);

	vector <string> getMsg(){return mesage;}
};

ostream& operator<<(ostream& out, const ValidationExceptions& ex);

