#ifndef PIZZAVIEW_H
#define PIZZAVIEW_H
#include <iostream>
#include "Pizza.h"
#include "PizzaData.h"
#include "GlobalHelp.h"
#include "HomeController.h"

using namespace std;
using namespace GlobalHelp;


class PizzaUI
{
    private:

    public:
        PizzaUI();
        virtual ~PizzaUI();
        void displayPizzaUI();

};

#endif // PIZZAVIEW_H
