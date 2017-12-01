#ifndef PIZZAVIEW_H
#define PIZZAVIEW_H
#include "Pizza.h"
#include "PizzaData.h"
#include <iostream>

using namespace std;



class PizzaView
{
    private:

    public:
        PizzaView();
        virtual ~PizzaView();
        void displayPizzaView();

};

#endif // PIZZAVIEW_H
