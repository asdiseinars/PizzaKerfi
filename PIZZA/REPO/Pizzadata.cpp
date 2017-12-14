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
    ifstream myFile("pizzamenu.txt");
    if(myFile.fail()) {
        cout << "There are no pizzas on the menu! " << endl;
        cout << "Please exit and add pizzas to the menu first." << endl;
    }

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
