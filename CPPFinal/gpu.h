#ifndef GPU_H
#define GPU_H

#include <iostream>
using namespace std;

class gpu
{
private:
    string name;
    string brand;
    int vmc;
    int price;

public:
    gpu();
    gpu(string name, string brand, int vmc, int price);
    string getName() { return name; }
    string getBrand() const { return brand; }
    int getPrice() const { return price; }

    void setName(string name) { this->name = name; }
    void setBrand(string brand) { this->brand = brand; }
    void setnumCores(int vmc) { this->vmc = vmc; }
    void setprice(int price) { this->price = price; }
};

#endif // GPU_H
