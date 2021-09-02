#include "initwindow.h"
#include "gamewindow.h"
#include "windowcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    InitWindow w;
//    w.show();
    WindowController wc;
//    QApplication::setQuitOnLastWindowClosed(false); //没用
    return a.exec();
    exit(0);
}
