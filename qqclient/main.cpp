#include "mainwindow.h"
#include"denglu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    denglu d;
    d.show();
    return a.exec();
}
