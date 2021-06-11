#include "cpu.h"

cpu::cpu(string name, string brand, int numCores, int numThreads, int price) {
    this->name = name;
    this->brand = brand;
    this->numCores = numCores;
    this->numThreads = numThreads;
    this->price = price;
}
