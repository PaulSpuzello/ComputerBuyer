#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H
#include <iostream>
using namespace std;

class powersupply
{
private:
    string name;
    int watts;
    int price;

public:
    powersupply();
    powersupply(string name, int watts, int price);

    string getName() const { return name; }
    int getWatts() const { return watts; }
    int getPrice() const { return price; }

    void setName(string name) { this->name = name; }
    void setWatts(int watts) { this->watts = watts; }
    void setprice(int price) { this->price = price; }
};

#endif // POWERSUPPLY_H
