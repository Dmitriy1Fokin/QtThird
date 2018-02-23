#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QDialog(parent)
{
    label = new QLabel("Enter");
    editLine = new QLineEdit;

    checkUppercase = new QCheckBox("Uppercase");
    checkInversion = new QCheckBox("Inversion");

    butStart = new QPushButton("Start");
    butExit = new QPushButton("Exit");

    QHBoxLayout *layoutIn = new QHBoxLayout;
    layoutIn->addWidget(label);
    layoutIn->addWidget(editLine);

    QVBoxLayout *layoutRight = new QVBoxLayout;
    layoutRight->addLayout(layoutIn);
    layoutRight->addWidget(checkUppercase);
    layoutRight->addWidget(checkInversion);

    QVBoxLayout *layoutLeft = new QVBoxLayout;
    layoutLeft->addWidget(butStart);
    layoutLeft->addWidget(butExit);

    layoutWithAll = new QHBoxLayout;
    layoutWithAll->addLayout(layoutRight);
    layoutWithAll->addLayout(layoutLeft);

    //setLayout(layoutWithAll);
    //QWidget *windowMain = new QWidget();
    //windowMain->setLayout(layoutWithAll);
    //windowMain->show();
}

MyWindow::Show()
{
    QWidget *windowMain = new QWidget();
    windowMain->setLayout(this->layoutWithAll);
    windowMain->show();
}

