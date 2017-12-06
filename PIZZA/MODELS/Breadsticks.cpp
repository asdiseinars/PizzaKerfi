#include "Breadsticks.h"
#include <fstream>

Breadsticks::Breadsticks(){
   name = '\0';
   price = 0;
   verbose = true;
}

Breadsticks::Breadsticks(string name, double price){
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

void Breadsticks::setVerbose(bool verbose){
    this->verbose = verbose;
}

istream& operator >> (istream& in, Breadsticks& breadsticks) {
    if(breadsticks.verbose)
        cout << "Topping name: ";
    in >> ws;
    getline(in, breadsticks.name);

    if(breadsticks.verbose)
        cout << "Topping price: ";
    in >> breadsticks.price;

    return in;
}

ostream& operator << (ostream& out, Breadsticks& breadsticks) {
    if(breadsticks.verbose)
        out << "Topping: ";
    out << breadsticks.name << endl;

    if(breadsticks.verbose)
        out << "Price: ";
    out << breadsticks.price << endl;

    return out;
}

