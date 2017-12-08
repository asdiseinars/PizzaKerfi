#include "Breadsticks.h"
#include <fstream>

Breadsticks::Breadsticks() {
    name = "";
    price = 0;
}

Breadsticks::Breadsticks(string name, double price) {
    this->name = name;
    this->price = price;
}

string Breadsticks::getName() {
    return name;
}
double Breadsticks::getPrice() {
    return price;
}

void Breadsticks::setName(string name) {
    this->name = name;
}

void Breadsticks::setPrice(double price) {
    this->price = price;
}


ifstream& operator >> (ifstream& fin, Breadsticks& breadsticks) {
    fin >> breadsticks.name;
    fin >> breadsticks.price;

    return fin;
}

ofstream& operator << (ofstream& fout, Breadsticks& breadsticks) {
    fout << breadsticks.name << endl;
    fout << breadsticks.price << endl;

    return fout;
}

