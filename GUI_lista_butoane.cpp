#include "GUI_lista_butoane.h"



void GUI_lista_butoane::initGUIComp(){

	QListWidget* list = new QListWidget;
	QListWidgetItem* item;
	item = new QListWidgetItem(list);
	list->addItem(item);
	QPushButton* button = new QPushButton("hey");
	item->setSizeHint(button->minimumSizeHint());
	list->setItemWidget(item, button);


	//list->addItem("bar");
	for (auto el = 0;el <  dimensiune; el++) {
		//lista_item[el] = new QListWidgetItem(list);
		//list->addItem(lista_item[el]);
		//trebuie sa transform din string in char;
		//qDebug << "asdasd";
		//char* chr = const_cast<char*>(lista_name[el].c_str());
		//lista_butoane[el] = new QPushButton(chr);
		//lista_item[el]->setSizeHint(lista_butoane[el]->minimumSizeHint());
		//list->setItemWidget(lista_item[el], lista_butoane[el]);
		
		QListWidgetItem* item;
		item = new QListWidgetItem(list);
		list->addItem(item);
		QPushButton* button = new QPushButton(""+ lista_price[el] );/*chr*/
		QObject::connect(button, &QPushButton::clicked, this, [&]() {
			uiDeleteName(lista_name[el]); 
		});
		//lista_butoane.push_back(button);
		item->setSizeHint(button->minimumSizeHint());
		list->setItemWidget(item, button);

	}




	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(list);

	this->setLayout(layout);


	this->show();
}




void GUI_lista_butoane::connectSlotSignal(){
	for (auto el = 0; el < lista_name.size(); el++) {
		//QObject::connect(lista_butoane[el], &QPushButton::clicked, this, [&]() {
		//	uiDeleteName(lista_name[el]);
		//});
	}
}

void GUI_lista_butoane::refreshList(){


}

void GUI_lista_butoane::populare_liste(){
	//const vector <Product>& all = this->store.getAll();
	//ector <int> allp = store.getAllPrice();
	

	//for ( auto el : all ) {
	//	this->dimensiune++;
	//	lista_name.push_back(element.getName());
	//	lista_price.push_back(element.getPrice());
	//}


}

void GUI_lista_butoane::addButon(QPushButton * btn){
	//this->lista_butoane.push_back(btn);
}

void GUI_lista_butoane::uiDeleteName(string n){
	this->store.deleteProduct(n);

}

GUI_lista_butoane::~GUI_lista_butoane(){


}
