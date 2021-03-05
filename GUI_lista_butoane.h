#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QVBoxLayout>
#include <vector>
#include "ProductStore.h"
using namespace std;

class GUI_lista_butoane:public QWidget{
	Q_OBJECT
private:
	ProductStore& store;
	//vector <QListWidgetItem*> lista_item;
	//vector <QPushButton*> lista_butoane;
	vector <string> lista_name;
	vector <int> lista_price;
	int dimensiune;
	void initGUIComp();
	void connectSlotSignal();
	void refreshList();
	void populare_liste();
	void addButon(QPushButton* btn);
	void uiDeleteName(string n);
public:
	GUI_lista_butoane(ProductStore& st) :store{st} {
		this->dimensiune = 0;
		populare_liste();
		initGUIComp();
		connectSlotSignal();
		refreshList();
	}


	~GUI_lista_butoane();
};

