#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include "ToppingData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int MAX_TOPPINGS = 15;


class Pizza {
  private:
    string name;
    string size;
    double price;
    vector<Topping> toppings;
    int toppingCount;

  public:
    Pizza();
    Pizza(string name, double price, int toppingCount, vector<Topping> toppings);

    string getName();
    string getSize();
    double getPrice();
    vector<Topping> getToppings();

    void setName(string name);
    void setSize(string size);
    void setPrice(double price);
    void setToppings(vector<Topping> toppings);

    friend ifstream& operator >> (ifstream& fin, Pizza& pizza);
    friend ofstream& operator << (ofstream& fout, Pizza& pizza);
};


#endif // PIZZA_H
