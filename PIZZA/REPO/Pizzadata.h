#ifndef PIZZADATA_H
#define PIZZADATA_H
#include "Pizza.h"
#include <fstream>
#include <iostream>

using namespace std;

class PizzaData
{
    private:

    public:
        PizzaData();
        void storePizza(const Pizza& pizza);
        Pizza retrievePizza();



};

#endif // PIZZADATA_H

