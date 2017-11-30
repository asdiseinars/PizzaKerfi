#include "PizzaData.h"

PizzaData::PizzaData()
{
    //ctor
}

PizzaData::~PizzaData()
{
    //dtor
}

void PizzaData::storePizza( Pizza& pizza){
    ofstream fout;

    fout.open("pizzas.txt");

    fout << pizza;

    fout.close();
}

Pizza PizzaData::retrievePizza(){
    ifstream fin;
    fin.open("pizzas.txt");

    Pizza pizza;
    fin >> pizza;

    fin.close();

    return pizza;
}
