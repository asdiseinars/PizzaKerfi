#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include "ToppingData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Crust.h"

using namespace std;

class Pizza {
  private:
    string name;
    string size;
    double price;
    Crust crust;
    vector<Topping> toppings;
    int toppingCount;

  public:
    Pizza();
    Pizza(string name, double price, int toppingCount, vector<Topping> toppings, Crust crust);

    string getName();
    string getSize();
    double getPrice();
    vector<Topping> getToppings();
    Crust getCrust();

    void setName(string name);
    void setSize(string size);
    void setPrice(double price);
    void setToppings(vector<Topping> toppings);
    void setCrust(Crust crust);

    friend ifstream& operator >> (ifstream& fin, Pizza& pizza);
    friend ofstream& operator << (ofstream& fout, Pizza& pizza);
};


#endif // PIZZA_H
