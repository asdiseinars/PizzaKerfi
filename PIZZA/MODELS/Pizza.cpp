#include "Pizza.h"

Pizza::Pizza() {
    name = "Margarita";
    size = "Medium";
    price = 1500.0;
    verbose = true;
}

Pizza::Pizza(string name, vector<Topping> toppings) {
    this->name = name;
    this->toppings = toppings;
    size = "Medium";
    price = 1500.0;
    verbose = true;
}

string Pizza::getName() {
    return name;
}

string Pizza::getSize() {
    return size;
}

double Pizza::getPrice() {
    return price;
}

vector<Topping> Pizza::getToppings() {
    return toppings;
}

void Pizza::setName(string name) {
    this->name = name;
}

void Pizza::setSize(string size) {
    this->size = size;
}

void Pizza::setPrice(double price) {
    this->price = price;
}

void Pizza::setToppings(vector<Topping> toppings) {
    this->toppings = toppings;
}

void Pizza::setVerbose(bool verbose) {
    this->verbose = verbose;
}


ifstream& operator >> (ifstream& in, Pizza& pizza) {
    in >> pizza.name;
    for(unsigned int i = 0; i < pizza.toppings.size(); i++) {
        in >> pizza.toppings[i];
    }
    return in;
}


ofstream& operator << (ofstream& out, Pizza& pizza) {

    out << pizza.name << endl;
    out << pizza.price << endl;
    for (unsigned int i = 0; i < pizza.toppings.size(); i++) {
        out << pizza.toppings[i];
    }
    return out;
}

istream& operator >> (istream& in, Pizza& pizza) {
    cout << "Pizza name: ";
    in >> pizza.name;

    cout << "Toppings: ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++) {
        in >> pizza.toppings[i];
    }

    return in;
}

ostream& operator << (ostream& out, Pizza& pizza) {
    cout << "Pizza name: " << endl;
    out << pizza.name << endl;

    cout << "Pizza price: " << endl;
    out << pizza.price << endl;

    cout << "Toppings: ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++) {
        out << pizza.toppings[i] << endl;
    }

    return out;
}



