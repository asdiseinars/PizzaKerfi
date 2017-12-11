#include "Crust.h"

Crust::Crust() {
    name = "";
    price = 0;
}

Crust::Crust(string name, double price) {
    this->name = name;
    this->price = price;
}

string Crust::getName() {
    return name;
}
double Crust::getPrice() {
    return price;
}

void Crust::setName(string name) {
    this->name = name;
}

void Crust::setPrice(double price) {
    this->price = price;
}

ifstream& operator >> (ifstream& fin, Crust& crust) {
    fin >> crust.name;
    fin >> crust.price;
    return fin;
}

ofstream& operator << (ofstream& fout, Crust& crust) {
    fout << crust.name << endl;
    fout << crust.price << endl;
    return fout;
}
