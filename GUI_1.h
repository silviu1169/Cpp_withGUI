#pragma once

#include <QtWidgets/QMainWindow>
#include <qpushbutton.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/QListWidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <stdbool.h>
#include <vector>
#include "Product.h"
#include "ProductStore.h"
#include "ui_GUI_1.h"
#include "Tests.h"
#include "Export.h"
#include "CosGUI1.h"
#include "GUI_lista_butoane.h"

class GUI_1 : public QWidget{
	Q_OBJECT
private:
	GUI_lista_butoane* widList = new GUI_lista_butoane{ this->storeService };

	ProductStore& storeService;
	QListWidget* lst;
	QPushButton* add;
	QPushButton* remove;
	QPushButton* update;
	QPushButton* button0;
	QPushButton* button1;//
	QPushButton* button2;//
	QPushButton* button3;//
	QPushButton* button4;
	QPushButton* button5;
	QPushButton* button6;
	QPushButton* lbutton1;//
	QPushButton* lbutton2;//
	QPushButton* lbutton3;//
	QPushButton* lbutton4;//
	QPushButton* lbutton5;//
	QPushButton* lbutton6;//
	QPushButton* lbutton7;//
	QPushButton* lbutton8;//
	QLineEdit* txtsaveCSV;
	QLineEdit* txtsaveHTML;
	QLineEdit* txtname;
	QLineEdit* txtprice;
	QLineEdit* txttype;
	QLineEdit* txtproducer;
	void initGUICmps();
	void connectSignalSlots();
	void reloadList(const std::vector<Product>& all);
	void addGUI();
	void removeGUI();
	void updateGUI();
	void refreshGUI();
	void searchNameGUI();
	void searchTypeGUI();
	void searchProducerGUI();
	void sortNameGUI();
	void sortPriceGUI();
	void sortNameTypeGUI();
	void filterNameGUI();
	void filterPriceGUI();
	void filterProducerGUI();
	void undoGUI();
	void saveToCSVGUI();
	void saveToHTMLGUI();
	void uiCos();
	

public:
	GUI_1(ProductStore& s) :storeService{ s } {
		initGUICmps();
		connectSignalSlots();
		reloadList(storeService.getAll());
	};



};
