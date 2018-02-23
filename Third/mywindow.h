#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MyWindow : QDialog
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = 0);
    Show();
private:
    QLabel *label;
    QLineEdit *editLine;
    QCheckBox *checkUppercase;
    QCheckBox *checkInversion;
    QPushButton *butStart;
    QPushButton *butExit;
    QHBoxLayout *layoutWithAll;
};

#endif //MYWINDOW_H
