#include "ProductStore.h"
#include <algorithm>
#include <iostream>
void ProductStore::addProduct(const string n, int p, const string t, const string pro){
	Product pr{ n, p, t, pro };
	valid.validation(pr);
	repo.addRepo(pr);
	undoActions.push_back(std::make_unique<undoAdd>(pr, this->repo));



}

const vector<Product>& ProductStore::getAll() const
{
	return repo.getAllR();
}

vector<int> ProductStore::getAllPrice()
{
	vector <int> allPrice;
	for (const auto& el : repo.getAllR()) {
		allPrice.push_back(el.getPrice());
	}

	return allPrice;
}

void ProductStore::modifyProduct(const string n, int p, const string t, const string pro)
{
	Product pr{ n, p, t, pro };
	std::cout << pr.getName();
	valid.validation(pr);
	repo.modifyRepo(pr);
	undoActions.push_back(std::make_unique<undoModifyBack>(pr, this->repo));
	
}

void ProductStore::deleteProduct(const string n){
	
	int iterator = repo.findPositionByName(n);
	Product pr = repo.findProductByPosition(iterator);

	repo.deleteR(iterator);
	undoActions.push_back(std::make_unique<undoRemove>(pr, this->repo));

}

const Product ProductStore::searchByName(const string n) const
{
	return repo.getAllR()[repo.findPositionByName(n)];
}

const Product ProductStore::searchByType(const string t) const
{
	return repo.getAllR()[repo.findPositionByType(t)];
}

const Product ProductStore::searchByProducer(const string p) const
{
	return repo.getAllR()[repo.findPositionByProducer(p)];
}


bool cmpName(const Product& p1, const Product& p2) {
	return p1.getName() < p2.getName();
}
bool cmpPrice(const Product& p1, const Product& p2) {
	return p1.getPrice() < p2.getPrice();
}
bool cmpNameType(const Product& p1, const Product& p2) {
	if(p1.getName() != p2.getName())
		return p1.getName() < p2.getName();
	return p1.getType() < p2.getType();
}

vector<Product> ProductStore::sorting(int choice){	
	
	 vector<Product> all = repo.getAllR();
	
	bool(*functionCmp)(const Product& p1, const Product& p2) { cmpName };

	switch (choice) {
	case 1:
		functionCmp = cmpName;
		break;
	case 2:
		functionCmp = cmpPrice;
		break;
	case 3:
		functionCmp = cmpNameType;
		break;
	}
	for (int i = 0; i < (int)all.size() - 1; i++)
	{
		for (int j = i + 1; j < (int)all.size(); j++)
		{
			if (functionCmp(all[i], all[j]) == false)
			{
				auto aux = all[i];
				all[i] = all[j];
				all[j] = aux;
			}
		}
	}
	return all;
}

vector<Product> ProductStore::filterName(const string name){
	vector <Product> newAll;
	vector <Product> all = repo.getAllR();
	for (auto e : all) {
		if (e.getName() == name) {
			newAll.push_back(e);
		}
	}

	return newAll;
}

vector<Product> ProductStore::filterPrice(int price)
{
	vector <Product> newAll;
	vector <Product> all = repo.getAllR();
	for (auto e : all) {
		if (e.getPrice() >= price) {
			newAll.push_back(e);
		}
	}

	return newAll;
}

vector<Product> ProductStore::filterProducer(const string producer){
	vector <Product> newAll;
	vector <Product> all = repo.getAllR();
	for (auto e : all) {
		if (e.getProducer() == producer) {
			newAll.push_back(e);
		}
	}

	return newAll;
}



void ProductStore::storeUndo()
{

	if (undoActions.empty()) {
		throw RepositoryExceptions{"No more undo action to do!\n"};
	}
	undoActions.back()->doUndo();
	undoActions.pop_back();
	
	


}


const vector<Product>& ProductStore::addToCartS(const string n){	
	int iterator = this->repo.findPositionByName(n);
	const Product productToAdd = this->repo.findProductByPosition(iterator);
	this->shoppingcart.addCart(productToAdd);
	return this->shoppingcart.getAllCart();

}

const vector<Product>& ProductStore::fillRandom(int dimension){
	this->shoppingcart.fillCart(dimension, this->repo.getAllR());
	return this->shoppingcart.getAllCart();
}

const vector<Product>& ProductStore::clearCartS(){
	this->shoppingcart.clearCart();
	return this->shoppingcart.getAllCart();
}

const vector<Product>& ProductStore::getAllfromCart(){
	return this->shoppingcart.getAllCart();
}


