#include "Topping.h"

Topping::Topping(){
    string name = "";
    double price = 0.0;
}

Topping::Topping(string name, double price){
    this->name = name;
    this->price = price;

}

Topping::~Topping(){
    //dtor
}

istream& operator >> (istream& in, Topping& topping){
    getline(in, topping.name);
    in >> topping.price;
    return in;
}

ostream& operator << (ostream& out, Topping& topping){
    out << topping.name << endl;
    out << topping.price;
    return out;
}
