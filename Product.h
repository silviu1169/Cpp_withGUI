//Domain

#pragma once
#include<string>

using namespace std;

class Product {
	string name;
	int price;
	string type, producer;
public:
	Product(const string n, int p, const string t, const string pro) : name{ n }, price{ p }, type{ t }, producer{ pro }{}

	string getName() const {
		return this->name;
	}
	int getPrice() const noexcept {
		return this->price;
	}

	string getType() const {
		return this->type;
	}

	string getProducer() const {
		return this->producer;
	}

	void setName(const string n) {
		this->name = n;
	}
	void setPrice(int p) {
		this->price = p;
	}

	void setType(const string t) {
		this->type = t;
	}
	void setProducer(const string pro) {
		this->producer = pro;
	}
};

