#include "Order.h"

Order::Order()
{
    string location = "";
}


Order::Order(string location, vector<Pizza> pizzas, vector<Breadsticks> breadsticks, vector<Soda> sodas) {
    this->location = location;
    this->pizzas = pizzas;
    this->breadsticks = breadsticks;
    this->sodas = sodas;
}

void Order::setLocation(string location) {
    this->location = location;
}

void Order::setPizzas(vector<Pizza> pizzas) {
    this->pizzas = pizzas;
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

vector<Pizza> Order::getPizzas() {
    return pizzas;
}

vector<Breadsticks> Order::getBreadsticks() {
    return breadsticks;
}

vector<Soda> Order::getSodas() {
    return sodas;
}

ofstream& operator << (ofstream& fout, Order& order) {
    fout << order.location << endl;

    for (unsigned int i = 0; i < order.pizzas.size(); i++) {
        fout << order.pizzas[i] << endl;
    }

    for (unsigned int i = 0; i < order.breadsticks.size(); i++) {
        fout << order.breadsticks[i] << endl;
    }

    for (unsigned int i = 0; i < order.sodas.size(); i++) {
        fout << order.sodas[i] << endl;
    }
    return fout;
}

ifstream& operator >> (ifstream& fin, Order& order) {
    fin >> order.location;

    for (unsigned int i = 0; i < order.pizzas.size(); i++) {
    fin >> order.pizzas[i];
    }

    for (unsigned int i = 0; i < order.breadsticks.size(); i++) {
        fin >> order.breadsticks[i];
    }

    for (unsigned int i = 0; i < order.sodas.size(); i++) {
        fin >> order.sodas[i];
    }
    return fin;
}





