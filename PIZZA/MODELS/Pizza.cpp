#include "Pizza.h"

Pizza::Pizza(){
    name = "Margarita";
    size = "Medium";
    price = 1500.0;
    verbose = true;
}

Pizza::Pizza(string name, vector<Topping> toppings){
    this->name = name;
    this->toppings = toppings;
    size = "Medium";
    price = 1500.0;
    verbose = true;
}

void Pizza:: createPizza() {
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

/*
void Pizza::write(ofstream& fout) const {

    int toppingCount = toppings.size();

    fout.write((char*)(&toppingCount), sizeof(int));

    for(int i = 0; i < toppingCount; i++){
        toppings[i].write(fout);
    }
}

void Pizza::read(ifstream& fin) {
    int toppingCount;
    fin.read((char*)(&toppingCount), sizeof(int));

    Topping topping;
    for(unsigned int i = 0; i < toppings.size(); i++){
        topping.read(fin);
        addTopping(topping);
    }
}*/


istream& operator >> (istream& in, Pizza& pizza) {
    if(pizza.verbose) {
        cout << "Pizza name: ";
    }
        in >> pizza.name;

    if(pizza.verbose) {
        cout << "Toppings: ";
    }
    for(unsigned int i = 0; i < pizza.toppings.size(); i++) {
        pizza.toppings[i].verbose = false;
        in >> pizza.toppings[i];
    }

    return in;
}


ostream& operator << (ostream& out, Pizza& pizza) {

    if(pizza.verbose) {
        cout << "Pizza name: ";
    }

        out << pizza.name << endl;

    if(pizza.verbose) {
            cout << "Pizza price: ";
    }

        out << pizza.price << endl;

    if(pizza.verbose) {
            cout << "Toppings: ";
    }


    for (unsigned int i = 0; i < pizza.toppings.size(); i++) {
        pizza.toppings[i].verbose = false;
        out << pizza.toppings[i];
    }
    cout << endl;

    return out;
}



