#include <fstream>
#include "Soda.h"

Soda::Soda() {
    name = "";
    price = 0;
}

Soda::Soda(string name, double price) {
    this->name = name;
    this->price = price;
}

string Soda::getName() {
    return name;
}

double Soda::getPrice() {
    return price;
}

void Soda::setName(string name) {
    this->name = name;
}

void Soda::setPrice(double price) {
    this->price = price;
}


istream& operator >> (istream& in, Soda& soda) {
    in >> soda.name;
    in >> soda.price;

    return in;
}

ostream& operator << (ostream& out, Soda& soda) {
    out << soda.name << endl;
    out << soda.price << endl;

    return out;
}
