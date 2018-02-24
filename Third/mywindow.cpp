#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QDialog(parent)
{
    label = new QLabel("Enter");
    editLine = new QLineEdit;

    checkUppercase = new QCheckBox("Uppercase");
    checkInversion = new QCheckBox("Inversion");

    butStart = new QPushButton("Start");
    butStart->setDefault(true);
    butStart->setEnabled(false);
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

    connect(editLine, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
    connect(butExit, SIGNAL(clicked()), this, SLOT(close()));
    connect(butStart, SIGNAL(clicked()), this, SLOT(ButStartClicked()));
    connect(this, SIGNAL(SignalNoChecked(QString)), this, SLOT(SlotNoChecked(QString)));
}

MyWindow::Show()
{
    QWidget *windowMain = new QWidget();
    windowMain->setLayout(this->layoutWithAll);
    windowMain->show();
}

void MyWindow::TextChanged(QString str)
{
    butStart->setEnabled(!str.isEmpty());
}

void MyWindow::ButStartClicked()
{
    if(!checkUppercase->isChecked() && !checkInversion->isChecked())
        emit SignalNoChecked(editLine->text());
    if(checkUppercase->isChecked())
        emit SignalUppercase(editLine->text());
    if(checkInversion->isChecked())
        emit SignalInversion(editLine->text());
}

void MyWindow::SlotNoChecked(QString str)
{
    QMessageBox msg;
    msg.setText(str);
    msg.exec();
}
