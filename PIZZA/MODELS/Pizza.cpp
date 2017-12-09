#include "Pizza.h"

Pizza::Pizza() {
    name = "";
    price = 0;
    toppingCount = 0;
}

Pizza::Pizza(string name, double price, int toppingCount, vector<Topping> toppings, Crust crust) {
    this->name = name;
    this->price = price;
    this->toppings = toppings;
    this->toppingCount = toppingCount;
    this->crust = crust;
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

Crust Pizza::getCrust() {
    return crust;
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

void Pizza::setCrust(Crust crust) {
    this->crust = crust;
}


ifstream& operator >> (ifstream& fin, Pizza& pizza) {
    fin >> pizza.name;
    fin >> pizza.price;
    fin >> pizza.toppingCount;
    for(unsigned int i = 0; i < pizza.toppingCount; i++) {
        Topping t;
        fin >> t;
        pizza.toppings.push_back(t);
    }
    fin >> pizza.crust;
    return fin;
}

ofstream& operator << (ofstream& fout, Pizza& pizza) {
    fout << pizza.name << endl;
    fout << pizza.price << endl;
    fout << pizza.toppingCount << endl;
    for(unsigned int i = 0; i < pizza.toppingCount; i++) {
        fout << pizza.toppings[i];
    }
    fout << pizza.crust;
    return fout;
}



