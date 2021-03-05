/*
Service-ul de la ProductStore, creeaza obiecte,le valideaza si dupa le paseaza la repo 

*/
#pragma once

#include "ProductRepository.h"
#include "ProductValidator.h"
#include "Product.h"
#include "undo.h"
#include "ShoppingCart.h"

#include <functional>
#include <vector>
#include <iterator>
#include <memory>

using namespace std;




class ProductStore{
	ProductRepository& repo;
	ProductValidator& valid;
	vector<unique_ptr<undoAction>> undoActions;
	ShoppingCart shoppingcart;
	
public:
	
	ShoppingCart& getCart() {
		return shoppingcart;
	}
	ProductStore(ProductRepository& r, ProductValidator& v /*, ShoppingCart& s*/) noexcept :repo{ r }, valid{ v }/*, shoppingcart{s}*/{};
	
	//Function that create an product and validate it.
	void addProduct(const string n, int p, const string t, const string pro);

	const vector <Product>& getAll()const;

	vector <int> getAllPrice();

	void modifyProduct(const string n, int p, const string t, const string pro);
	
	void deleteProduct(const string n);

	const Product searchByName(const string n)const;

	const Product searchByType(const string t)const;

	const Product searchByProducer(const string p)const;

	vector <Product> sorting(int choice);

	vector <Product> filterName(const string name);

	vector <Product> filterPrice(int price);

	vector <Product> filterProducer(const string producer);

	void storeUndo();

	const vector <Product>& addToCartS(string n);

	const vector <Product>& fillRandom(int dimension);

	const vector <Product>& clearCartS();

	const vector <Product>& getAllfromCart();

	void notifyy() {
		this->shoppingcart.notify();
	}




	//~ProductStore();
};

