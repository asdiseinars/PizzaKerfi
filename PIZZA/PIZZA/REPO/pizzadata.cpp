#include "PizzaData.h"

PizzaData::PizzaData(){

}

PizzaData::~PizzaData(){
    //dtor
}

void PizzaData::storePizza(Pizza& pizza){
    ofstream fout;

    fout.open("pizzas.dat", ios::app | ios::binary);

    pizza.verbose = false;
    fout << pizza;

    fout.close();
}

Pizza PizzaData::retrievePizza(){
    ifstream fin;

    fin.open("pizzas.dat", ios::app | ios::binary);

    Pizza pizza;
    fin >> pizza;

    fin.close();

    return pizza;
}

