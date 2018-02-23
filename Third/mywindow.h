#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

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
private slots:
    void TextChanged(QString str);
    void ButStartClicked();
signals:
    void SignalUppercase(QString str);
    void SignalInversion(QString str);
    void SignalNoChecked(QString str);
};

class rowAndString : public QObject
{
    Q_OBJECT
public slots:
    void SignalNoChecked(QString str)
    {
        QMessageBox msg;
        msg.setText(str);
        msg.exec();
    }
};

#endif //MYWINDOW_H
