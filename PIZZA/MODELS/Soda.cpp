#include <fstream>
#include "Soda.h"

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

void Soda::setVerbose(bool verbose){
    this->verbose = verbose;
}

istream& operator >> (istream& in, Soda& soda) {
    if(soda.verbose)
        cout << "Soda name: ";
    in >> ws;
    getline(in, soda.name);

    if(soda.verbose)
        cout << "Soda price: ";
    in >> soda.price;

    return in;
}

ostream& operator << (ostream& out, Soda& soda) {
    if(soda.verbose)
        out << "Soda: ";
    out << soda.name << endl;

    if(soda.verbose)
        out << "Price: ";
    out << soda.price << endl;

    return out;
}
