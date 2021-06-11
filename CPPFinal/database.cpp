#include "database.h"
#include "buildcomputer.h"
#include <QSqlQuery>
#include <QString>
#include <string>
#include <iostream>

//cout << query.value(0).toInt() << endl;

Database::Database() {
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qWarning() << "ERROR: driver not available";
    }
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(":memory:");
    if(!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
    rebuildTestDatabase();
}

void Database::open() {
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("bank.sqlite");
    if(!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
}

void Database::close() {
    db.close();
    QSqlDatabase::removeDatabase(DRIVER);
}

QString Database::getCpuPrice(QString cpuName) {
    QSqlQuery query;

    cpuName.toStdString();
    query.prepare("SELECT price FROM cpuTable WHERE name = :cpuName");
    query.bindValue(":cpuName", cpuName);
    query.exec();
    query.first();

    return query.value(0).toString();

}

QString Database::getGpuPrice(QString gpuName) {
    QSqlQuery query;

    gpuName.toStdString();
    query.prepare("SELECT price FROM gpuTable WHERE name = :gpuName");
    query.bindValue(":gpuName", gpuName);
    query.exec();
    query.first();
    return query.value(0).toString();

}

QString Database::getRamPrice(QString ramName) {
    QSqlQuery query;

    ramName.toStdString();
    query.prepare("SELECT price FROM ramTable WHERE name = :ramName");
    query.bindValue(":ramName", ramName);
    query.exec();
    query.first();
    return query.value(0).toString();

}

QString Database::getPowSupplyPrice(QString powerSupplyName) {
    QSqlQuery query;

    powerSupplyName.toStdString();
    query.prepare("SELECT price FROM powerSupplyTable WHERE name = :powerSupplyName");
    query.bindValue(":powerSupplyName", powerSupplyName);
    query.exec();
    query.first();
    return query.value(0).toString();

}

QString Database::getCasePrice(QString caseName) {
    QSqlQuery query;

    caseName.toStdString();
    query.prepare("SELECT price FROM caseTable WHERE name = :caseName");
    query.bindValue(":caseName", caseName);
    query.exec();
    query.first();
    return query.value(0).toString();

}

void Database::rebuildTestDatabase() {
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS gpuTable");
    query.exec("DROP TABLE IF EXISTS cpuTable");
    query.exec("DROP TABLE IF EXISTS ramTable");
    query.exec("DROP TABLE IF EXISTS powerSupplyTable");
    query.exec("DROP TABLE IF EXISTS caseTable");

    query.exec("CREATE TABLE gpuTable (name STRING PRIMARY KEY, brand TEXT, memCapacity INTEGER, price INTEGER)");
    query.exec("CREATE TABLE cpuTable (name STRING PRIMARY KEY, brand TEXT, numCores INTEGER, numThreads, price INTEGER)");
    query.exec("CREATE TABLE ramTable (name STRING PRIMARY KEY, memCap INTEGER, price INTEGER)");
    query.exec("CREATE TABLE powerSupplyTable (name STRING PRIMARY KEY, wattage INTEGER, price INTEGER)");
    query.exec("CREATE TABLE caseTable (name STRING PRIMARY KEY, fans INTEGER, price INTEGER)");

    QSqlQuery insertCPU;
    insertCPU.prepare("INSERT INTO cpuTable (name, brand, numCores, numThreads, price) VALUES (:name, :brand, :numCores, :numThreads, :price)");

    insertCPU.bindValue(":name", "i7-8700k");
    insertCPU.bindValue(":brand", "Intel");
    insertCPU.bindValue(":numCores", 6);
    insertCPU.bindValue(":numThreads", 12);
    insertCPU.bindValue(":price", 300);
    insertCPU.exec();

    insertCPU.bindValue(":name", "Ryzen5800x");
    insertCPU.bindValue(":brand", "Ryzen");
    insertCPU.bindValue(":numCores", 8);
    insertCPU.bindValue(":numThreads", 16);
    insertCPU.bindValue(":price", 450);
    insertCPU.exec();

    QSqlQuery insertGPU;
    insertCPU.prepare("INSERT INTO gpuTable (name, brand, memCapacity, price) VALUES (:name, :brand, :memCapacity, :price)");

    insertCPU.bindValue(":name", "RTX3070");
    insertCPU.bindValue(":brand", "Nvidia");
    insertCPU.bindValue(":videoMem", 8);
    insertCPU.bindValue(":price", 500);
    insertCPU.exec();

    insertCPU.bindValue(":name", "RTX2070");
    insertCPU.bindValue(":brand", "Nvidia");
    insertCPU.bindValue(":videoMem", 8);
    insertCPU.bindValue(":price", 400);
    insertCPU.exec();

    insertCPU.bindValue(":name", "RX5600-XT");
    insertCPU.bindValue(":brand", "Ryzen");
    insertCPU.bindValue(":videoMem", 6);
    insertCPU.bindValue(":price", 300);
    insertCPU.exec();

    QSqlQuery insertRAM;
    insertRAM.prepare("INSERT INTO ramTable (name, memCap, price) VALUES (:name, :memCap, :price)");

    insertRAM.bindValue(":name", "16GB");
    insertRAM.bindValue(":memCap", 16);
    insertRAM.bindValue(":price", 60);
    insertRAM.exec();

    insertRAM.bindValue(":name", "32GB");
    insertRAM.bindValue(":memCap", 32);
    insertRAM.bindValue(":price", 100);
    insertRAM.exec();

    QSqlQuery insertPowerSupply;
    insertPowerSupply.prepare("INSERT INTO powerSupplyTable (name, wattage, price) VALUES (:name, :wattage, :price)");

    insertPowerSupply.bindValue(":name", "450 Watts");
    insertPowerSupply.bindValue(":wattage", 450);
    insertPowerSupply.bindValue(":price", 45);
    insertPowerSupply.exec();

    insertPowerSupply.bindValue(":name", "550 Watts");
    insertPowerSupply.bindValue(":wattage", 550);
    insertPowerSupply.bindValue(":price", 50);
    insertPowerSupply.exec();

    insertPowerSupply.bindValue(":name", "600 Watts");
    insertPowerSupply.bindValue(":wattage", 600);
    insertPowerSupply.bindValue(":price", 60);
    insertPowerSupply.exec();

    insertPowerSupply.bindValue(":name", "800 Watts");
    insertPowerSupply.bindValue(":wattage", 800);
    insertPowerSupply.bindValue(":price", 100);
    insertPowerSupply.exec();

    QSqlQuery insertCase;
    insertCase.prepare("INSERT INTO caseTable (name, fans, price) VALUES (:name, :fans, :price)");

    insertCase.bindValue(":name", "Low Range");
    insertCase.bindValue(":fans", 16);
    insertCase.bindValue(":price", 50);
    insertCase.exec();

    insertCase.bindValue(":name", "Mid Range");
    insertCase.bindValue(":fans", 32);
    insertCase.bindValue(":price", 60);
    insertCase.exec();

    insertCase.bindValue(":name", "High Range");
    insertCase.bindValue(":fans", 32);
    insertCase.bindValue(":price", 100);
    insertCase.exec();
}
