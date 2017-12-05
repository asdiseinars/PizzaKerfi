#include "Pizza.h"

Pizza::Pizza(){

    string name = "Margarita";
    string size = "Medium";
    double price = 1500.0;
    verbose = true;
}

Pizza::Pizza(int toppingCount) {

}

void Pizza::addTopping(Topping topping){

    toppings.push_back(topping);
}

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
}

int Pizza::get_number() {
    return number;
}

string Pizza::get_name() {
    return name;
}

string Pizza::get_size() {
    return size;
}

double Pizza::get_price() {
    return price;
}

vector<Topping> Pizza::get_toppings() {
    return toppings;
}

void Pizza::set_number(int number) {
    this->number = number;
}

void Pizza::set_name(string name) {
    this->name = name;
}

void Pizza::set_size(string size) {
    this->size = size;
}

void Pizza::set_price(double price) {
    this->price = price;
}

void Pizza::set_toppings(vector<Topping> toppings) {
    this->toppings = toppings;
}















istream& operator >> (istream& in, Pizza& pizza) {
    int toppingCount;
    in >> toppingCount;

    Topping topping;
    for (unsigned int i = 0; i < pizza.toppings.size(); i++) {
        in >> topping;
        pizza.addTopping(topping);
    }
    return in;
}

ostream& operator << (ostream& out, Pizza& pizza) {
    if (pizza.verbose) {
            out << "Pizza with toppings: " << endl;
    }

    for (unsigned int i = 0; i < pizza.toppings.size(); i++) {
        out << pizza.toppings[i] << endl;
    }

    return out;
}


