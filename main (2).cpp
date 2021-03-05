#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "UI.h"
#include "ProductRepository.h"
#include "ProductValidator.h"
#include "ProductStore.h"
#include "Tests.h"
#include "Product.h"
#include "ShoppingCart.h"
#include <iostream>
#include <fstream>

using namespace std;

void clearfile() {

	ofstream f ("Product.txt", ios::trunc);
	f.close();

}

int main1() {
	{
		TestAll();//I can made a private method that clear the file at every time 
		//cout << "All tests done";

		//ProductRepository pr;
		ProductRepositoryFile prf{ "Product.txt" };
		ProductValidator pv;
		//ShoppingCart ss;
		ProductStore sto{ prf,pv };//, ss };
		UI ui{ sto };
		ui.start();
	}
	//_CrtDumpMemoryLeaks();
	return 0;
}