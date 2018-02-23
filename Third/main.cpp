#include <QApplication>
#include "mywindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWindow *window = new MyWindow();
    window->Show();



    return app.exec();
}
