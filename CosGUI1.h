#pragma once
#include <qwidget.h>
#include <qtimer.h>
#include <QtWidgets/QHBoxLayout>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qtablewidget.h>
#include <qstring.h>
#include <qlabel.h>
#include <vector>
#include "ShoppingCart.h"
#include "observer.h"
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>

class CosGUICuLista :public QWidget, public Observer {
private:
	ProductStore& store;
	ShoppingCart& cos;
	QListWidget* lst;
	QPushButton* btn;
	QPushButton* btnRandom;
	QPushButton* btnAdd;
	QLineEdit* name;
	QLineEdit* nr_products;
	void loadList(const std::vector<Product>& Products) {
		lst->clear();
		for (auto& p : Products) {
			lst->addItem(QString::fromStdString(p.getName()));
		}
	}
	void initGUI() {		
		QHBoxLayout* ly = new QHBoxLayout;
		lst = new QListWidget;
		ly->addWidget(lst);
		
		QWidget* firstCol = new QWidget;
		QVBoxLayout* boxFirstCol = new QVBoxLayout(firstCol);
		firstCol->setLayout(boxFirstCol);

		btn = new QPushButton("Clear cos");
		boxFirstCol->addWidget(btn);

		QWidget* secondRow = new QWidget;
		QHBoxLayout* boxSecondRow = new QHBoxLayout(secondRow);
		secondRow->setLayout(boxSecondRow);
		QLabel* enterName = new QLabel("Name:");
		name = new QLineEdit;
		btnAdd = new QPushButton("Add Product");
		boxSecondRow->addWidget(enterName);
		boxSecondRow->addWidget(name);
		boxSecondRow->addWidget(btnAdd);

		boxFirstCol->addWidget(secondRow);
		boxFirstCol->addStretch();
		ly->addWidget(firstCol);

		QWidget* secondRowR = new QWidget;
		QHBoxLayout* boxSecondRowR = new QHBoxLayout(secondRowR);
		secondRowR->setLayout(boxSecondRowR);

		QLabel* nrProd = new QLabel("Enter no. prod.:");
		nr_products = new QLineEdit;
		btnRandom = new QPushButton("Add random");
		boxSecondRowR->addWidget(nrProd);
		boxSecondRowR->addWidget(nr_products);
		boxSecondRowR->addWidget(btnRandom);
		ly->addWidget(secondRowR);

		setLayout(ly);

	}
	void connectSignals() {
		cos.addObserver(this);

		QObject::connect(btnAdd, &QPushButton::clicked, this, [&]() {
			
			try {

				cos.addCart(store.searchByName(name->text().toStdString()));
				loadList(cos.getAllCart());
				cos.notify();
			}
			catch (RepositoryExceptions& ex) {
				QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
			}
			catch (ValidationExceptions& ex) {
				QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
			}
			
		});

		QObject::connect(btn, &QPushButton::clicked, [&]() {
			

			try {
				cos.clearCart();
				loadList(cos.getAllCart());

				cos.notify();
			}
			catch (RepositoryExceptions& ex) {
				QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
			}
			catch (ValidationExceptions& ex) {
				QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
			}
			
			
		});
		QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
			

			try {

				cos.fillCart(nr_products->text().toInt(), store.getAll());
				loadList(cos.getAllCart());

				cos.notify();
			}
			catch (RepositoryExceptions& ex) {
				QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
			}
			catch (ValidationExceptions& ex) {
				QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
			}

			
		});				
	}
public:
	CosGUICuLista(ProductStore& st, ShoppingCart& cos) :cos{ cos }, store{ st } {
		initGUI();
		connectSignals();
		cos.addObserver(this);
		loadList(cos.getAllCart());
	}
	
	void update() override {
		loadList(cos.getAllCart());
	}

	~CosGUICuLista() {
		cos.removeObserver(this);
	}
	
	
};

class CosGUILabel :public QLabel,public Observer {	
	ShoppingCart& cos;
public:
	CosGUILabel(ShoppingCart& cos) :cos{ cos } {
		setFont(QFont{ "arial",24 });
		setAttribute(Qt::WA_DeleteOnClose); //daca vreau sa se distruga fereastra imediat dupa inchidere
		cos.addObserver(this);
		update();
	}

	void update() override {
		setText("Cosul contine:" + QString::number(cos.getAllCart().size()));
	}
	~CosGUILabel() {
		cos.removeObserver(this);
	}
};

class CosGUICuTabel : public QWidget, public Observer{
private:
	ProductStore& store;
	ShoppingCart& cos;
	QTableWidget* lst;
	QPushButton* btn;	
	QPushButton* btnRandom;

	void loadTable(const std::vector<Product>& Products) {
		lst->clear();
		lst->setRowCount(Products.size());
		lst->setColumnCount(3);
		for (int i = 0; i < Products.size(); i++) {
			lst->setItem(i, 0,new QTableWidgetItem(Products[i].getName().c_str()));
			lst->setItem(i, 1, new QTableWidgetItem(Products[i].getType().c_str()));
			lst->setItem(i, 2, new QTableWidgetItem(QString::number(Products[i].getPrice())));
		}
	}

	void initGUI() {		
		QHBoxLayout* ly = new QHBoxLayout;
		lst = new QTableWidget;
		ly->addWidget(lst);
		btn = new QPushButton("Clear cos");
		ly->addWidget(btn);

		btnRandom = new QPushButton("Add random 4");
		ly->addWidget(btnRandom);
		setLayout(ly);
	}
	void connectSignals() {
		cos.addObserver(this);
		QObject::connect(btn, &QPushButton::clicked, [&]() {
			cos.clearCart();
			loadTable(cos.getAllCart());

			cos.notify();
		});
		QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
			cos.fillCart(4, store.getAll());
			loadTable(cos.getAllCart());

			cos.notify();
		});

	}

	void update()override {
		loadTable(cos.getAllCart());
	}

public:
	CosGUICuTabel(ProductStore& st, ShoppingCart& cos) :cos{ cos }, store{st} {
		initGUI();
		connectSignals();
		cos.addObserver(this);
		loadTable(cos.getAllCart());

	}
	
	
	
	~CosGUICuTabel() {
		cos.removeObserver(this);
	}
	
};
