#include "Order.h"

Order::Order()
{
    string location = "";
    int pizzasFromMenuCount = 0;
    int pizzasFromScratchCount = 0;
    int breadsticksCount = 0;
    int sodasCount = 0;
    double totalPrice = 0;
    int orderStatus = 0;
    string phoneNumber = "";
}

Order::Order(string location, vector<Pizza> pizzasFromMenu, int pizzasFromMenuCount, vector<Pizza> pizzasFromScratch, int pizzasFromScratchCount,
             vector<Breadsticks> breadsticks, int breadsticksCount, vector<Soda> sodas, int sodasCount, double totalPrice, int orderStatus,
             string phoneNumber) {

    this->location = location;
    this->pizzasFromMenu = pizzasFromMenu;
    this->pizzasFromMenuCount = pizzasFromMenuCount;
    this->pizzasFromScratch = pizzasFromScratch;
    this->pizzasFromScratchCount = pizzasFromScratchCount;
    this->breadsticks = breadsticks;
    this->breadsticksCount = breadsticksCount;
    this->sodas = sodas;
    this->sodasCount = sodasCount;
    this->totalPrice = totalPrice;
    this->orderStatus = orderStatus;
    this->phoneNumber = phoneNumber;
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

void Order::setOrderStatus(int orderStatus) {
    this->orderStatus = orderStatus;
}

void Order::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

string Order::getLocation() {
    return location;
}

vector<Pizza> Order::getPizzasFromMenu() {
    return pizzasFromMenu;
}

vector<Pizza> Order::getPizzasFromScratch() {
    return pizzasFromScratch;
}

vector<Breadsticks> Order::getBreadsticks() {
    return breadsticks;
}

vector<Soda> Order::getSodas() {
    return sodas;
}

double Order::getTotalPrice() {
    return totalPrice;
}

int Order::getOrderStatus() {
    return orderStatus;
}

string Order::getPhoneNumber() {
    return phoneNumber;
}

ofstream& operator << (ofstream& fout, Order& order) {
    fout << order.location << endl;

    fout << order.phoneNumber << endl;

    fout << order.pizzasFromMenu.size() << endl;

    for (unsigned int i = 0; i < order.pizzasFromMenu.size(); i++) {
        fout << order.pizzasFromMenu[i];
    }

    fout << order.pizzasFromScratch.size() << endl;
    for (unsigned int i = 0; i < order.pizzasFromScratch.size(); i++) {
        fout << order.pizzasFromScratch[i];
    }

    fout << order.breadsticks.size() << endl;
    for (unsigned int i = 0; i < order.breadsticks.size(); i++) {
        fout << order.breadsticks[i];
    }

    fout << order.sodas.size() << endl;
    for (unsigned int i = 0; i < order.sodas.size(); i++)
    {
        fout << order.sodas[i];
    }

    fout << order.totalPrice << endl;

    fout << order.orderStatus << endl;

    return fout;
}

ifstream& operator >> (ifstream& fin, Order& order) {
    fin >> order.location;

    fin >> order.phoneNumber;

    fin >> order.pizzasFromMenuCount;
    for (unsigned int i = 0; i < order.pizzasFromMenuCount; i++) {
        Pizza p;
        fin >> p;
        order.pizzasFromMenu.push_back(p);
    }

    fin >> order.pizzasFromScratchCount;
    for (unsigned int i = 0; i < order.pizzasFromScratchCount; i++) {
        Pizza p;
        fin >> p;
        order.pizzasFromScratch.push_back(p);
    }

    fin >> order.breadsticksCount;
    for (unsigned int i = 0; i < order.breadsticksCount; i++) {
        Breadsticks b;
        fin >> b;
        order.breadsticks.push_back(b);
    }

    fin >> order.sodasCount;
    for (unsigned int i = 0; i < order.sodasCount; i++) {
        Soda s;
        fin >> s;
        order.sodas.push_back(s);
    }

    fin >> order.totalPrice;

    fin >> order.orderStatus;

    return fin;
}

