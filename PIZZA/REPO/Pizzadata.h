#ifndef PIZZADATA_H
#define PIZZADATA_H
#include "Pizza.h"
#include "Topping.h"
#include "ToppingData.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class PizzaData {
  private:

  public:
    PizzaData();
    void addPizzaToMenu(Pizza& pizza);
    vector<Pizza> retrieveAllPizzas();
    void storeAllPizzas(vector<Pizza> pizza);

};

#endif // PIZZADATA_H

