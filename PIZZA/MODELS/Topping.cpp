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
    cout << endl;
    return in;
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
