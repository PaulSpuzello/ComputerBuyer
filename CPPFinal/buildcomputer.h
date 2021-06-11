#ifndef BUILDCOMPUTER_H
#define BUILDCOMPUTER_H
#include "database.h"
#include <map>
#include <string>
using namespace std;

class buildcomputer
{
private:
    int totalPrice;
    long nextUniqueId = 1;
    map<long, buildcomputer*> idCompMap;
public:

    ~buildcomputer();

    long getUniqueId();
    QString getTotalPrice();
    void setTotalPrice(QString input);
};

#endif // BUILDCOMPUTER_H
