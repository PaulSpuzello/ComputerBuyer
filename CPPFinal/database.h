#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <memory>
#include "buildcomputer.h"
using namespace std;

class Database {
private:
    QSqlDatabase db;
    long getLatestRowId();
    QString DRIVER;
public:
    Database();
    void open();
    void rebuildTestDatabase();
    void close();

    QString getCpuPrice(QString name);
    QString getGpuPrice(QString name);
    QString getRamPrice(QString name);
    QString getPowSupplyPrice(QString name);
    QString getCasePrice(QString name);
};

#endif // DATABASE_H
