#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database database;

    MainWindow w(database);
    w.show();



    return a.exec();
}
