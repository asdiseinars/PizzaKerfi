#ifndef PIZZADATA_H
#define PIZZADATA_H
#include <fstream>
#include "Pizza.h"
#include <iostream>

using namespace std;


class PizzaData
{
    private:

    public:
        PizzaData();
        virtual ~PizzaData();

        void storePizza( Pizza& pizza);
        Pizza retrievePizza();


};

#endif // PIZZADATA_H
