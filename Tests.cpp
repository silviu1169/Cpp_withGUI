#include "Tests.h"
#include "Product.h"
#include "ProductValidator.h"
#include "ProductStore.h"
#include "ProductRepository.h"
#include "ShoppingCart.h"

#include <cassert>
#include <iostream>
#include <fstream>

void TestStore() {
	//Tests for undo.h


	ProductRepository r;
	ProductRepositoryFile rf{"Product.txt"};
	ProductValidator v;
	//ShoppingCart ss;
	ProductStore s(r, v/*, ss*/);
	ProductStore sfile(rf, v/*, ss*/);
	
	RepositoryExceptions e("asdasdsdasd");
	

	//------------------store file
	try {
		ProductRepositoryFile repofile{ "asdasd/sadasd.txt" };
		assert(false);
	}
	catch (RepositoryExceptions&) { assert(true); }

	//rf.clearFile();//inca mai raman date in fisier, trebuie golit inainte
	try {
		sfile.addProduct("a", 1, "a", "a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		sfile.modifyProduct("a", 1, "a", "a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		sfile.deleteProduct("a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }

	try {
		sfile.addProduct("a", 1, "a", "a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }
	/*
	try {
		sfile.deleteProduct("a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }
	*/

	try {
		ProductRepositoryFile repofile{ "Product.txt" };
		assert(true);
	}
	catch (RepositoryExceptions&) { assert(false); }

	//sfile.getRepo().clearFile();//inca mai raman date in fisier, trebuie golit inainte

	//--------------------------

	try {
		s.storeUndo();
		assert(false);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }

	//add
	try {
		s.addProduct("", -1, "", "");
		assert(false);
	}
	catch (ValidationExceptions& ve) { cout << ve << endl; assert(true); }

	try {
		s.addProduct("a", 1, "a", "a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }
	try {
		s.addProduct("a1", 1, "a1", "a1");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		s.storeUndo();
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		 Product p = r.findProductByPosition(0);
		assert (true);
	}
	catch (RepositoryExceptions&) { assert(false); }

	try {
		Product p = r.findProductByPosition(10);
		assert(false);
	}
	catch (RepositoryExceptions&) { assert(true); }


	try {
		s.addProduct("a", 1, "a", "a");
		assert(false);
	}
	catch (ValidationExceptions& ve) { cout << ve << endl; assert (true); }
	catch (RepositoryExceptions& re) { cout << re << endl; assert(true); }
	
	//modify
	try {
		s.modifyProduct("a", 1, "a", "a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }
	
	try {
		s.modifyProduct("n", 1, "a", "a");
		assert(false);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }
	try {
		s.addProduct("b", 1, "b", "b");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	//delete
	try {
		s.deleteProduct("a");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		s.deleteProduct("hh");
		assert(false);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }

	//searchByName
	try {
		Product p = s.searchByName("b");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		Product p = s.searchByName("a");
		assert(false);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }

	//searchByType
	try {
		Product p = s.searchByType("b");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		Product p = s.searchByType("a");
		assert(false);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }

	//searchByProducer
	try {
		Product p = s.searchByProducer("b");
		assert(true);
	}
	catch (ValidationExceptions&) { assert(false); }
	catch (RepositoryExceptions&) { assert(false); }

	try {
		Product p = s.searchByProducer("a");
		assert(false);
	}
	catch (ValidationExceptions&) { assert(true); }
	catch (RepositoryExceptions&) { assert(true); }
	
	const vector<Product> vv1 = s.getAll();
	s.addProduct("a", 1, "a", "a");
	s.addProduct("bb", 1, "b", "b");
	s.addProduct("c", 1, "c", "c");
	s.addProduct("d", 1, "d", "d");
	s.addProduct("e", 1, "e", "e");
	s.addProduct("f", 1, "f", "f");
	vector<Product> v1 = s.sorting(1);
	vector<Product> v2 = s.sorting(2);
	vector<Product> v3 = s.sorting(3);
	Product pp1{ "a",1,"a","a" };
	Product pp2{ "a",1,"a","a" };
	vector<Product> v4 = s.filterName("a");
	vector<Product> v5 = s.filterPrice(1);
	vector<Product> v6 = s.filterProducer("a");

	
}

void TestAll() {
	TestStore();
}