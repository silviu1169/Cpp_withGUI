#include "GUI_1.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>
#include <QFormLayout>


int main(int argc, char *argv[]){
	
	QApplication app(argc, argv);
	ProductRepositoryFile r{"Products"};
	ProductValidator v;
	ProductStore st(r,v);


	GUI_1 mygui(st);
	return app.exec();
}
