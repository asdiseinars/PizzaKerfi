#include "Order.h"

Order::Order()
{
    string location = "";
    int pizzasFromMenuCount = 0;
    int pizzasFromScratchCount = 0;
    int breadsticksCount = 0;
    int sodasCount = 0;

}

Order::Order(string location, vector<Pizza> pizzasFromMenu, int pizzasFromMenuCount, vector<Pizza> pizzasFromScratch, int pizzasFromScratchCount,
             vector<Breadsticks> breadsticks, int breadsticksCount, vector<Soda> sodas, int sodasCount) {

    this->location = location;
    this->pizzasFromMenu = pizzasFromMenu;
    this->pizzasFromMenuCount = pizzasFromMenuCount;
    this->pizzasFromScratch = pizzasFromScratch;
    this->pizzasFromScratchCount = pizzasFromScratchCount;
    this->breadsticks = breadsticks;
    this->breadsticksCount = breadsticksCount;
    this->sodas = sodas;
    this->sodasCount = sodasCount;
}

void Order::setLocation(string location) {
    this->location = location;
}

void Order::setPizzasFromMenu(vector<Pizza> pizzasFromMenu) {
    this->pizzasFromMenu = pizzasFromMenu;
}

void Order::setPizzasFromScratch(vector<Pizza> pizzasFromScratch) {
    this->pizzasFromScratch = pizzasFromScratch;
}

void Order::setBreadsticks(vector<Breadsticks> breadsticks) {
    this->breadsticks = breadsticks;
}

void Order::setSodas(vector<Soda> sodas) {
    this->sodas = sodas;
}

string Order::getLocation() {
    return location;
}

vector<Pizza> Order::getpizzasFromMenu() {
    return pizzasFromMenu;
}

vector<Pizza> Order::getpizzasFromScratch() {
    return pizzasFromScratch;
}

vector<Breadsticks> Order::getBreadsticks() {
    return breadsticks;
}

vector<Soda> Order::getSodas() {
    return sodas;
}

ofstream& operator << (ofstream& fout, Order& order) {
    fout << order.location << endl;

    for (unsigned int i = 0; i < order.pizzasFromMenu.size(); i++) {
        fout << order.pizzasFromMenu[i];
    }
    fout << order.pizzasFromMenuCount << endl;

    for (unsigned int i = 0; i < order.pizzasFromScratch.size(); i++) {
        fout << order.pizzasFromScratch[i];
    }
    fout << order.pizzasFromScratchCount << endl;

    for (unsigned int i = 0; i < order.breadsticks.size(); i++) {
        fout << order.breadsticks[i];
    }
    fout << order.breadsticksCount << endl;

    for (unsigned int i = 0; i < order.sodas.size(); i++) {
        fout << order.sodas[i];
    }
    fout << order.sodasCount << endl;

    return fout;
}

ifstream& operator >> (ifstream& fin, Order& order) {
    fin >> order.location;

    for (unsigned int i = 0; i < order.pizzasFromMenu.size(); i++) {
    fin >> order.pizzasFromMenu[i];
    }
    fin >> order.pizzasFromMenuCount;

    for (unsigned int i = 0; i < order.pizzasFromScratch.size(); i++) {
    fin >> order.pizzasFromScratch[i];
    }
    fin >> order.pizzasFromScratchCount;

    for (unsigned int i = 0; i < order.breadsticks.size(); i++) {
        fin >> order.breadsticks[i];
    }
    fin >> order.breadsticksCount;

    for (unsigned int i = 0; i < order.sodas.size(); i++) {
        fin >> order.sodas[i];
    }
    fin >> order.sodasCount;

    return fin;
}





