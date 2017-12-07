#include "PizzaData.h"

PizzaData::PizzaData(){

}

void PizzaData::storePizzaToMenu(Pizza& pizza)
{
    ofstream fout;
    fout.open("pizzamenu.txt", ios::app);
    pizza.setVerbose(false);
    fout << pizza;
    fout.close();
    pizza.setVerbose(true);
}

vector<Pizza> PizzaData::retrieveAllPizzas() { ///a eftir að testa

    vector <Pizza> pizzas;
    Pizza pizza;

    ifstream fin;
    fin.open("pizzamenu.txt");
    while(!fin.eof()) {
        pizza.setVerbose(false);
        fin >> pizza;
        //pizza.setVerbose(true);
        pizzas.push_back(pizza);
    }
    pizzas.pop_back();

    return pizzas;
}
