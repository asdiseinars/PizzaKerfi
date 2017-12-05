#include <fstream>
#include "Topping.h"

Topping::Topping(){

}

Topping::Topping(string name, double price){
    this->name = name;
    this->price = price;

}

istream& operator >> (istream& in, Topping& topping) {
    cout << "Name: ";
    in >> ws;
    getline(in, topping.name);

    cout << "Price: ";
    in >> topping.price;

    return in;
}

int Topping::get_number(){
    return number;
}

string Topping::get_name() {
    return name;
}
double Topping::get_price() {
    return price;
}

void Topping::set_number(int number){
    this->number = number;
}

void Topping::set_name(string name) {
    this->name = name;
}

void Topping::set_price(double price) {
    this->price = price;
}

ostream& operator << (ostream& out, Topping& topping) {
    out << topping.name << endl;
    out << topping.price;
    return out;
}

void Topping::write(ofstream& fout) const {

    int stringLenght = name.length() + 1;

    fout.write((char*)(&stringLenght), sizeof(int));
    fout.write(name.c_str(), stringLenght);

    fout.write((char*)(&price), sizeof(double));

}

void Topping::read(ifstream& fin) {

    int stringLenght;

    fin.read((char*)(&stringLenght), sizeof(int));
    char* str = new char[stringLenght];

    fin.read(str, stringLenght);

    name = str;

    fin.read((char*)(&price), sizeof(double));

    delete[] str;

}
