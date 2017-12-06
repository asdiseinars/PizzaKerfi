#include "Pizza.h"

Pizza::Pizza(){
    name = "Margarita";
    size = "Medium";
    price = 1500.0;
    verbose = true;
}

Pizza::Pizza(string size, vector<Topping> toppings, int addToppingToPizza){
    name = '\0';
    price = 1500;
    if(addToppingToPizza > MAX_TOPPINGS) {
        cout << "WOW! To many toppings!" << endl;
    }

    else {
        for (int i = 0; i < addToppingToPizza; i++) {
            toppings[i] = toppings[i];
        }
        toppingCount = addToppingToPizza;
    }
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

    pizza.chooseToppings();

    return in;
}


ostream& operator << (ostream& out, const Pizza& pizza) {

    if(pizza.verbose) {
        out << "Pizza name: " << pizza.name << endl;
        out << "Pizza price: " << pizza.price << endl;
        out << endl;
    }

    else {
        out << pizza.name << endl;
        out << pizza.price << endl;
    }

    return out;
}

void Pizza::chooseToppings() {

}


