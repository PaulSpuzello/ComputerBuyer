#ifndef COMPUTERCASE_H
#define COMPUTERCASE_H
#include <iostream>
using namespace std;

class computercase
{
private:
    string name;
    int fans;
    int price;
public:
    computercase();
    computercase(string name, int fans, int price);

    string getName() { return name; }
    int getFans() const { return fans; }
    int getPrice() const { return price; }

    void setName(string name) { this->name = name; }
    void setFans(int fans) { this->fans = fans; }
    void setprice(int price) { this->price = price; }
};

#endif // COMPUTERCASE_H
