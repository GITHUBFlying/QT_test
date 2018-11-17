#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   /* QPushButton hello("quit",0);
    hello.resize(100,30);
    QObject::connect(&hello,SIGNAL(clicked()),&a,SLOT(quit()));
    a.setActiveWindow(&hello);
    hello.show();*/
    return a.exec();
}
