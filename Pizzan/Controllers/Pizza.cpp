#include "Pizza.h"

Pizza::Pizza()
{
    //ctor
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::addTopping(Topping topping){

    toppings.push_back(topping);
}

void Pizza::write(ofstream& fout) const {

    fout.write((char*)(&toppings.size()), sizeof(int));

    for(int i = 0; i < toppings.size(); i++){
        fout.write((char*)(&toppings.at(i)), sizeof(Topping));
    }
}

void Pizza::read(ifstream& fin) {
    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

    Topping topping;
    for(int i = 0; i < toppings.size(); i++){
        fin.read((char*)(&toppings), sizeof(Topping));
        addTopping(topping);
    }

}

istream& operator >> (istream& in, Pizza& pizza) {
    int toppingCount;
    in >> toppingCount;

    Topping topping;
    for (int i = 0; i < pizza.toppings.size(); i++) {
        in >> topping;
        pizza.addTopping(topping);
    }
    return in;
}

ostream& operator << (ostream& out, Pizza& pizza) {
    out << "Pizza with toppings: " << endl;

    for (int i = 0; i < pizza.toppings.at(i)) //Komin hingað

return out;
}




