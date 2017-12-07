#ifndef PIZZADATA_H
#define PIZZADATA_H
#include "Pizza.h"
#include "Topping.h"
#include "ToppingData.h"
#include <fstream>
#include <iostream>

using namespace std;

class PizzaData
{
    private:

    public:
        PizzaData();
        void storePizzaToMenu(Pizza& pizza);
        Pizza retrievePizza();



};

#endif // PIZZADATA_H

