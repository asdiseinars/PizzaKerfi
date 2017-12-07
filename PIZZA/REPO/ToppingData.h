#ifndef TOPPINGDATA_H
#define TOPPINGDATA_H
#include "topping.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class ToppingData {

      private:

      public:
        ToppingData();
        void storeAllToppings(vector<Topping> toppings);
        vector<Topping> retrieveAllToppings();
        void addTopping(Topping& topping);
};

#endif // TOPPINGDATA_H

