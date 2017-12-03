#include "PizzaData.h"

PizzaData::PizzaData(){

}

void PizzaData::storePizza(Pizza& pizza){
    ofstream fout;

    fout.open("Pizza.dat", ios::app | ios::binary);

    pizza.verbose = false;
    fout << pizza;

    fout.close();
}

Pizza PizzaData::retrievePizza(){
    ifstream fin;

    fin.open("Pizza.dat", ios::binary);

    Pizza pizza;
    fin >> pizza;

    fin.close();

    return pizza;
}

