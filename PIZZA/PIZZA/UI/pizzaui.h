#ifndef PIZZAVIEW_H
#define PIZZAVIEW_H
#include "Pizza.h"
#include "PizzaData.h"
#include <iostream>

using namespace std;


class PizzaUI
{
    private:

    public:
        PizzaUI();
        virtual ~PizzaUI();
        void displayPizzaUI();

};

#endif // PIZZAVIEW_H
