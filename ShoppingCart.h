#pragma once

#include "Product.h"
#include "observer.h"
#include <vector>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock



using std::vector;
using std::shuffle;

class ShoppingCart:public Observable {
	vector <Product> cart;

public:
	ShoppingCart();

	void addCart(const Product& p) {
		this->cart.push_back(p);
	}

	void clearCart() {
		this->cart.clear();
	}

	void fillCart(size_t dimension, vector<Product> all) {
		vector<Product> all1;
		std::shuffle(all.begin(), all.end(), std::default_random_engine(std::random_device{}()));
		while ((this->cart.size() < dimension) && (all.size() > 0)) {
			this->cart.push_back(all.back());
			all1.push_back(all.back());
			all.pop_back();
			if (all.size() == 0 && cart.size() < dimension) {
				all = all1;
				all1.clear();
				std::shuffle(all.begin(), all.end(), std::default_random_engine(std::random_device{}()));
			}
		}
	}

	const vector <Product>& getAllCart() {
		return this->cart;
	}



	~ShoppingCart() {};
};

