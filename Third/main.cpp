#include <QApplication>
#include <QWidget>
#include "mywindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    //QPushButton *but = new QPushButton("qwerty");
    //but->show();


    MyWindow *window = new MyWindow();
    window->Show();

    return app.exec();
}
