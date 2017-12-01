#include "Pizza.h"

Pizza::Pizza()
{
    verbose = true;
}

Pizza::Pizza(int toppingCount) {

}


void Pizza::addTopping(Topping topping){

    toppings.push_back(topping);
}

void Pizza::write(ofstream& fout) const {

    int tCount = toppings.size();

    fout.write((char*)(&tCount), sizeof(int));

    /*for(int i = 0; i < tCount; i++){
        fout.write((char*)(&toppings.at(i)), sizeof(Topping));
    }*/

    for(int i = 0; i < tCount; i++){
        toppings[i].write(fout);
    }
}

void Pizza::read(ifstream& fin) {
    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

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




