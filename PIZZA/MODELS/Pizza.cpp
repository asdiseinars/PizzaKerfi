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


