#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PetStoreObserverGit.h"

class PetStoreObserverGit : public QMainWindow
{
	Q_OBJECT

public:
	PetStoreObserverGit(QWidget *parent = Q_NULLPTR);

private:
	Ui::PetStoreObserverGitClass ui;
};
