#pragma once
#include "Product.h"
#include "ProductRepository.h"
#include <vector>
#include <functional>
#include <fstream>

class undoAction {
public:
	virtual void doUndo() = 0;
	virtual ~undoAction() = default;
};

class undoRemove :public undoAction {
	Product productToAdd;
	ProductRepository& repo;
public:
	undoRemove(const Product p, ProductRepository& r) : productToAdd{ p }, repo{ r } {}
	void doUndo()override {
		repo.addRepo(productToAdd);
	}
};

class undoAdd :public undoAction {
	Product productToRemove;
	ProductRepository& repo;
public:
	undoAdd(const Product p, ProductRepository& r) : productToRemove{ p }, repo{ r }{}
	void doUndo() override {
		repo.deleteR(repo.findPositionByName(productToRemove.getName()));
	}
};

class undoModifyBack :public undoAction {
	Product productToModifyBack;
	ProductRepository& repo;
public:
	undoModifyBack(const Product p, ProductRepository& r) :productToModifyBack{ p }, repo{ r }{}
	void doUndo()override {
		repo.deleteR(repo.findPositionByName(productToModifyBack.getName()));
		repo.addRepo(productToModifyBack);
	}

};