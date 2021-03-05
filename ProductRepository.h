#pragma once

#include "Product.h"
#include <vector>
#include <functional>
#include <fstream>


class ProductRepository
{
	vector <Product> store;

public:
	 ProductRepository();

	//verify if that an object exist in collection or not
	bool exist(const Product p) const;
	
	//Function that return the position of the object with name n or the -1 if the object doesn't exist
	int findPositionByName(const string n)const;

	int findPositionByType(const string t)const;

	int findPositionByProducer(const string p)const;

	//add an object to store
	virtual void addRepo(const Product p);

	//Function that modify an product 
	virtual void modifyRepo(const Product p);


	virtual void deleteR(int iterator);

	//return the store
	const vector <Product>& getAllR() const noexcept;

	const Product findProductByPosition(int iterator);


	 virtual ~ProductRepository();
};


class RepositoryExceptions {
	string mesage;
public:

	RepositoryExceptions(string msg) : mesage{ msg } {}

	friend ostream& operator<<(ostream& out, const RepositoryExceptions& ex);

	string getMsg() { return this->mesage; }

};
ostream& operator<<(ostream& out, const RepositoryExceptions& ex);



class ProductRepositoryFile :public ProductRepository {
	void loadfromfile();
	void savetofile();
	string fName;
	void clearFile() {
		ofstream f(fName, ios::trunc);
		f.close();
	}

public:
	ProductRepositoryFile(string n) :ProductRepository(), fName{ n }{
		//this->clearFile();
		loadfromfile();
	}



	

	void addRepo(const Product p)override {
		ProductRepository::addRepo(p);
		savetofile();
	}

	void modifyRepo(const Product p)override {
		ProductRepository::modifyRepo(p);
		savetofile();
	}


	void deleteR(int iterator)override{
		ProductRepository::deleteR(iterator);
		savetofile();
	}
	~ProductRepositoryFile()override {
		//this->clearFile();

	}
};
