#include "buildcomputer.h"
#include <QString>
buildcomputer::~buildcomputer()
{
    for (auto pair : idCompMap) {
        delete pair.second;
    }
}

long buildcomputer::getUniqueId() {
    return nextUniqueId++;
}

QString buildcomputer::getTotalPrice() {
    //QString string = QString::number(totalPrice);
    //return string;
}

void buildcomputer::setTotalPrice(QString price) {
    this->totalPrice = price.toInt();
}
