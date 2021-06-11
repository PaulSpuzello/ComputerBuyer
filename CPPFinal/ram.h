#ifndef RAM_H
#define RAM_H
#include <iostream>
using namespace std;

class ram
{
private:
    string name;
    int memCap;
    int price;

public:
    ram();
    ram(string name, int memCap, int price);

    string getName() const { return name; }
    int getMemCap() const { return memCap; }
    int getPrice() const { return price; }

    void setName(string name) { this->name = name; }
    void setMemCap(int memCap) { this->memCap = memCap; }
    void setprice(int price) { this->price = price; }
};

#endif // RAM_H
