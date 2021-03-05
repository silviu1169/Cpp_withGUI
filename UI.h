#pragma once
#include <iostream>

#include "ProductStore.h"
#include "Export.h"


using namespace std;

class UI{

	ProductStore& st;

	//This function reads an int if the input is an string or char
	int readInt();

	string readStr(string msg);

	//Function reads from keyboard the input, verify his type and send it to ProductStore
	void uiAdd();
	
	void uiPrint(const vector <Product>& store1);
	
	void uiModify();

	void uiDelete();

	void uiSearch();

	void uiSort();

	void uiFilter();

	void uiUndo();
public:

	UI(ProductStore& s) :st{ s } {}
	//~UI();

	void start();
};

