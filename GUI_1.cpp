#include "GUI_1.h"
#include <QLABEL>


void GUI_1::initGUICmps(){
	//The main window is partitioned in horizontal box
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	this->setLayout(mainLayout);
	//The left window is a vertical box and contain the list with items an under it  the sort buttons
	QWidget* leftWid = new QWidget;
	QVBoxLayout* verticalLeftLayout = new QVBoxLayout(leftWid);
	leftWid->setLayout(verticalLeftLayout);
	lst = new QListWidget;
	verticalLeftLayout->addWidget(lst);

	QWidget* leftWidButtons = new QWidget;
	QHBoxLayout* hboxl = new QHBoxLayout(leftWidButtons);
	leftWidButtons->setLayout(hboxl);
	lbutton1 = new QPushButton("SORT by Name");
	lbutton2 = new QPushButton("SORT by Price");
	lbutton3 = new QPushButton("SORT by Name and Producer");
	hboxl->addWidget(lbutton1);
	hboxl->addWidget(lbutton2);
	hboxl->addWidget(lbutton3);
	verticalLeftLayout->addWidget(leftWidButtons);

	QWidget* leftWidButtons2 = new QWidget;
	QHBoxLayout* hboxl2 = new QHBoxLayout(leftWidButtons2);
	leftWidButtons2->setLayout(hboxl2);
	lbutton4 = new QPushButton("FILTER by Name");
	lbutton5 = new QPushButton("FILTER by Price");
	lbutton6 = new QPushButton("FILTER by Producer");
	hboxl2->addWidget(lbutton4);
	hboxl2->addWidget(lbutton5);
	hboxl2->addWidget(lbutton6);
	verticalLeftLayout->addWidget(leftWidButtons2);


	QWidget* widSaveToCSV = new QWidget;
	QHBoxLayout* boxSaveCSVLayout = new QHBoxLayout(widSaveToCSV);
	widSaveToCSV->setLayout(boxSaveCSVLayout);
	QLabel* enterFileCSV = new QLabel("Enter file name:");
	txtsaveCSV = new QLineEdit;
	lbutton7 = new QPushButton("Save to .CSV");
	boxSaveCSVLayout->addWidget(enterFileCSV);
	boxSaveCSVLayout->addWidget(txtsaveCSV);
	boxSaveCSVLayout->addWidget(lbutton7);
	verticalLeftLayout->addWidget(widSaveToCSV);

	QWidget* widSaveToHTML = new QWidget;
	QHBoxLayout* boxSaveToHTML = new QHBoxLayout(widSaveToHTML);
	widSaveToHTML->setLayout(boxSaveToHTML);

	QLabel* enterFileHTML = new QLabel("Enter file name:");
	txtsaveHTML = new QLineEdit;
	lbutton8 = new QPushButton("Save to .HTML");
	boxSaveToHTML->addWidget(enterFileHTML);
	boxSaveToHTML->addWidget(txtsaveHTML);
	boxSaveToHTML->addWidget(lbutton8);
	verticalLeftLayout->addWidget(widSaveToHTML);

	verticalLeftLayout->addStretch();
	mainLayout->addWidget(leftWid);//----------added in the main window the left pannel


	//The right window is a vertical box and contain the details and under them the add, update, delete buttons + other buttons
	QWidget* rightWid = new QWidget;
	QVBoxLayout* verticalRightLayout = new QVBoxLayout(rightWid);

	QWidget* widDetalii = new QWidget;
	QLabel* LName = new QLabel("Name:");
	QFormLayout* details = new QFormLayout(widDetalii);
	txtname = new QLineEdit;
	details->addRow(LName, txtname);
	QLabel* LPrice = new QLabel("Price:");
	txtprice = new QLineEdit;
	details->addRow(LPrice, txtprice);
	QLabel* LType = new QLabel("Type:");
	txttype = new QLineEdit;
	details->addRow(LType, txttype);
	QLabel* LProducer = new QLabel("Producer:");
	txtproducer = new QLineEdit;
	details->addRow(LProducer, txtproducer);
	verticalRightLayout->addWidget(widDetalii);//added the details 
	//Now, we create and add the buttons


	QWidget* widRightUnderDetails = new QWidget;
	QHBoxLayout* bHLayUnderDetails = new QHBoxLayout(widRightUnderDetails);
	widRightUnderDetails->setLayout(bHLayUnderDetails);

	button0 = new QPushButton("REFRESH");

	QWidget* widRightRefreshLeft = new QWidget;
	QVBoxLayout* bVLayR1 = new QVBoxLayout(widRightRefreshLeft);
	widRightRefreshLeft->setLayout(bVLayR1);

	QWidget* widRightRefreshRight = new QWidget;
	QVBoxLayout* bVLayR2 = new QVBoxLayout(widRightRefreshRight);
	widRightRefreshRight->setLayout(bVLayR2);

	bHLayUnderDetails->addWidget(widRightRefreshLeft);
	bHLayUnderDetails->addWidget(button0);
	bHLayUnderDetails->addWidget(widRightRefreshRight);

	verticalRightLayout->addWidget(widRightUnderDetails);

	add = new QPushButton("&ADD");
	remove = new QPushButton("&REMOVE");
	update = new QPushButton("&UPDATE");
	
	QWidget* widButtons = new QWidget;
	QHBoxLayout* hBLay = new QHBoxLayout(widButtons);
	widButtons->setLayout(hBLay);
	hBLay->addWidget(add);
	hBLay->addWidget(remove);
	hBLay->addWidget(update);
	verticalRightLayout->addWidget(widButtons);

	QWidget* widButtons2 = new QWidget;
	QHBoxLayout* hBLay2 = new QHBoxLayout(widButtons2);
	widButtons2->setLayout(hBLay2);
	button1 = new QPushButton("UNDO");
	button2 = new QPushButton("Cos de CUMPARATURI");
	button3 = new QPushButton("Button&3");
	hBLay2->addWidget(button1);
	hBLay2->addWidget(button2);
	hBLay2->addWidget(button3);
	QWidget* widButtons3 = new QWidget;
	QHBoxLayout* hBLay3 = new QHBoxLayout(widButtons3);
	widButtons3->setLayout(hBLay3);
	button6 = new QPushButton("SEARCH by Producer");
	button5 = new QPushButton("SEARCH by Type");
	button4 = new QPushButton("SEARCH by Name");
	hBLay3->addWidget(button4);
	hBLay3->addWidget(button5);
	hBLay3->addWidget(button6);

	verticalRightLayout->addWidget(widButtons2);
	verticalRightLayout->addWidget(widButtons3);
	verticalRightLayout->addStretch();


	mainLayout->addWidget(rightWid);//---------added in the main window the right pannel

	this->show();


}

void GUI_1::connectSignalSlots() {

	QObject::connect(button2, &QPushButton::clicked, this, [&]() {
		uiCos();
	});

	QObject::connect(button1, &QPushButton::clicked, this, [&]() {
		undoGUI();
	});

	QObject::connect(lbutton4, &QPushButton::clicked, this, [&]() {
		filterNameGUI();
	});

	QObject::connect(lbutton5, &QPushButton::clicked, this, [&]() {
		filterPriceGUI();
	});

	QObject::connect(lbutton6, &QPushButton::clicked, this, [&]() {
		filterProducerGUI();
	});

	QObject::connect(lbutton7, &QPushButton::clicked, this, [&]() {
		saveToCSVGUI();
	});

	QObject::connect(lbutton8, &QPushButton::clicked, this, [&]() {
		saveToHTMLGUI();
	});

	QObject::connect(lbutton1, &QPushButton::clicked, this, [&]() {
		sortNameGUI();
	});

	QObject::connect(lbutton2, &QPushButton::clicked, this, [&]() {
		sortPriceGUI();
	});

	QObject::connect(lbutton3, &QPushButton::clicked, this, [&]() {
		sortNameTypeGUI();
	});

	QObject::connect(add, &QPushButton::clicked, this, &GUI_1::addGUI);

	QObject::connect(remove, &QPushButton::clicked, this, [&]() {
		removeGUI();
	});
	QObject::connect(update, &QPushButton::clicked, this, [&]() {
		updateGUI();
	});
	QObject::connect(lst, &QListWidget::itemSelectionChanged, [&]() {
		if (this->lst->selectedItems().isEmpty()) {
			//nu este nimic selectat (golesc detaliile)
			txtname->setText("");
			txtprice->setText("");
			txttype->setText("");
			txtproducer->setText("");
			return;
		}
		QListWidgetItem* selItem = lst->selectedItems().at(0);
		QString name1 = selItem->text();
		txtname->setText(name1);
		QString type = selItem->data(Qt::UserRole).toString();
		txttype->setText(type);
		try {
			//cautam Product
			Product p = storeService.searchByName(name1.toStdString());
			txtprice->setText(QString::number(p.getPrice()));
			txtproducer->setText(QString::fromStdString(p.getProducer()));
		}
		catch (RepositoryExceptions& ex) {
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(ex.getMsg()));
		}
	});

	QObject::connect(button4, &QPushButton::clicked, this,[&]() {
		searchNameGUI();
	});

	QObject::connect(button5, &QPushButton::clicked, this, [&]() {
		searchTypeGUI();
	});

	QObject::connect(button6, &QPushButton::clicked, this, [&]() {
		searchProducerGUI();
	});

	QObject::connect(button0, &QPushButton::clicked, this, [&]() {
		refreshGUI();
	});
}

void GUI_1::reloadList(const std::vector<Product>& all){
	this->lst->clear();
	for (const auto& product : all) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(product.getName()),lst);
		item->setData(Qt::UserRole, QString::fromStdString(product.getType()));//adaug in lista (invizibil) si type 
		if (product.getPrice() < 10) {
			item->setBackground(Qt::red);

		}
	}
	this->txtname->setText("");
	this->txtprice->setText("");
	this->txttype->setText("");
	this->txtproducer->setText("");
}

void GUI_1::addGUI(){
	try {
		this->storeService.addProduct(txtname->text().toStdString(), txtprice->text().toInt(), txttype->text().toStdString(), txtproducer->text().toStdString());
		reloadList(this->storeService.getAll());
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}

}

void GUI_1::removeGUI(){
	try {
		this->storeService.deleteProduct(txtname->text().toStdString());
		reloadList(this->storeService.getAll());
		this->storeService.notifyy();
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
	}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}
}

void GUI_1::updateGUI(){
	try {
		this->storeService.modifyProduct(txtname->text().toStdString(), txtprice->text().toInt(), txttype->text().toStdString(), txtproducer->text().toStdString());
		reloadList(this->storeService.getAll());
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
	}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}
	

}

void GUI_1::refreshGUI(){
	reloadList(this->storeService.getAll());
}

void GUI_1::searchNameGUI(){
	string nameSearched = txtname->text().toStdString();
	bool found = false;
	for (const auto& element : this->storeService.getAll()) {
		if (element.getName() == nameSearched) {
			found = true;
			txtprice->setText(QString::number(element.getPrice()));
			txttype->setText(QString::fromStdString(element.getType()));
			txtproducer->setText(QString::fromStdString(element.getProducer()));
		}
	}
	if (! found) {
		QMessageBox::warning(nullptr, "Warning", QString::fromStdString("There is no product with this name!"));
	}
}

void GUI_1::searchTypeGUI(){
	string typeSearched = txttype->text().toStdString();
	bool found = false;
	for (const auto& element : this->storeService.getAll()) {
		if (element.getType() == typeSearched) {
			found = true;
			txtprice->setText(QString::number(element.getPrice()));
			txtname->setText(QString::fromStdString(element.getName()));
			txtproducer->setText(QString::fromStdString(element.getProducer()));
		}
	}
	if (!found) {
		QMessageBox::warning(nullptr, "Warning", QString::fromStdString("There is no product with this type!"));
	}

}

void GUI_1::searchProducerGUI(){
	string producerSearched = txtproducer->text().toStdString();
	bool found = false;
	for (const auto& element : this->storeService.getAll()) {
		if (element.getProducer() == producerSearched) {
			found = true;
			txtprice->setText(QString::number(element.getPrice()));
			txttype->setText(QString::fromStdString(element.getType()));
			txtname->setText(QString::fromStdString(element.getName()));
		}
	}
	if (!found) {
		QMessageBox::warning(nullptr, "Warning", QString::fromStdString("There is no product with this producer!"));
	}


}

void GUI_1::sortNameGUI(){
	this->reloadList(this->storeService.sorting(1));
}

void GUI_1::sortPriceGUI(){
	this->reloadList(this->storeService.sorting(2));
}

void GUI_1::sortNameTypeGUI(){
	this->reloadList(this->storeService.sorting(3));

}

void GUI_1::filterNameGUI(){

	this->reloadList(this->storeService.filterName(txtname->text().toStdString()));
}

void GUI_1::filterPriceGUI(){

	this->reloadList(this->storeService.filterPrice(txtprice->text().toInt()));
}

void GUI_1::filterProducerGUI(){
	this->reloadList(this->storeService.filterProducer(txtproducer->text().toStdString()));
}

void GUI_1::undoGUI(){
	try {
		this->storeService.storeUndo();
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
	}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}
	
	this->reloadList(this->storeService.getAll());
}

void GUI_1::saveToCSVGUI(){
	try {
		exportToCSV(txtsaveCSV->text().toStdString(),this->storeService.getAll());
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
	}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}
}

void GUI_1::saveToHTMLGUI(){
	try {
		exportToHTLM(txtsaveHTML->text().toStdString(), this->storeService.getAll());
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
	}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}

}

void GUI_1::uiCos(){


	try {
		qDebug("cos creat\n");
		CosGUICuLista* cosGUI = new CosGUICuLista{ this->storeService, this->storeService.getCart() };
		cosGUI->show();
	}
	catch (RepositoryExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()));
	}
	catch (ValidationExceptions& ex) {
		QMessageBox::warning(this, "warning!", QString::fromStdString(ex.getMsg()[0]));
	}

}
