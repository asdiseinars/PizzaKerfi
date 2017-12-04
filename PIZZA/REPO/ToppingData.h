#ifndef TOPPINGDATA_H
#define TOPPINGDATA_H
#include <vector>
#include "topping.h"
#include <fstream>
#include <iostream>

using namespace std;


class ToppingData
{
    public:
        ToppingData();
        void storeAllToppings(const vector<Topping>& toppings);
        vector<Topping> retrieveAllToppings();

    private:
};

#endif // TOPPINGDATA_H
