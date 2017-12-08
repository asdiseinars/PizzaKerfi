#include "PizzaData.h"

PizzaData::PizzaData() {

}

void PizzaData::addPizzaToMenu(Pizza& pizza) {
    ofstream fout;
    fout.open("pizzamenu.txt", ios::app);
    fout << pizza;
    fout.close();
}

vector<Pizza> PizzaData::retrieveAllPizzas() {

    vector <Pizza> pizzas;


    ifstream fin;
    fin.open("pizzamenu.txt");
    while(!fin.eof()) {
        Pizza pizza;
        fin >> pizza;
        pizzas.push_back(pizza);
    }
    pizzas.pop_back();

    return pizzas;
}

void PizzaData::storeAllPizzas(vector<Pizza> pizzas) {

    ofstream fout;
    fout.open("pizzamenu.txt");
    for(unsigned int i = 0; i < pizzas.size(); i++) {
        fout << pizzas[i];
    }
    fout.close();
}
