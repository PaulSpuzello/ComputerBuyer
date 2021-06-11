#ifndef CPU_H
#define CPU_H

#include <iostream>
using namespace std;

class cpu
{
private:
    string name;
    string brand;
    int numCores;
    int numThreads;
    int price;

public:
    cpu();
    cpu(string name, string brand, int numCorees, int numThreads, int price);
    string getName() const { return name; }
    string getBrand() const { return brand; }
    int getNumCores() const { return numCores; }
    int getNumThreads() const { return numThreads; }
    int getPrice() const { return price; }

    void setName(string name) { this->name = name; }
    void setBrand(string brand) { this->name = name; }
    void setnumCores(int numCores) { this->name = name; }
    void setnumThreads(int numThreads) { this->name = name; }
    void setprice(int price) { this->name = name; }
};

#endif // CPU_H
