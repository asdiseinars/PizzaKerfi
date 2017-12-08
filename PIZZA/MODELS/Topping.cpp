#include <fstream>
#include "Topping.h"

Topping::Topping() {
    name = "";
    price = 0;
}

Topping::Topping(string name, double price) {
    this->name = name;
    this->price = price;
}

string Topping::getName() {
    return name;
}
double Topping::getPrice() {
    return price;
}

void Topping::setName(string name) {
    this->name = name;
}

void Topping::setPrice(double price) {
    this->price = price;
}


ifstream& operator >> (ifstream& fin, Topping& topping) {
    fin >> topping.name;
    fin >> topping.price;
    return fin;
}

ofstream& operator << (ofstream& fout, Topping& topping) {
    fout << topping.name << endl;
    fout << topping.price << endl;
    return fout;
}
