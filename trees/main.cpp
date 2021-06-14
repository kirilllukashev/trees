#include "mainwindow.h"

#include <QApplication>

MainWindow *ui;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ui = &w;
    w.show();
    return a.exec();
}
