#include <QApplication>
#include "mainscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainScreen* _mainScreen = new MainScreen();
    _mainScreen->show();

    return a.exec();
}
