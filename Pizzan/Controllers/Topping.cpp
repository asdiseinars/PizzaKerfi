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

    return in;
}

ostream& operator << (ostream& out, Topping& topping){

    return out;
}
