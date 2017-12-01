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
        virtual ~PizzaData();

        void storePizza(Pizza& pizza);
        Pizza retrievePizza();


};

#endif // PIZZADATA_H

