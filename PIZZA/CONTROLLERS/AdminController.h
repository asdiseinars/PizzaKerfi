#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "pizzadata.h"
#include "ToppingData.h"
#include <stdlib.h>

using namespace GlobalHelp;
using namespace AdminUI;

class AdminController
{
    private:
        PizzaData pizzaData;
        ToppingData toppingData;

    public:
        AdminController();
        void init();

        void modifyPizzas();
        void displayAllToppings();
        void addTopping();
        void removeTopping();

        void modifyToppings();
        void displayAllPizzas();
        void addPizzaToMenu();
        void removePizzaFromMenu();
};

#endif // ADMINCONTROLLER_H
