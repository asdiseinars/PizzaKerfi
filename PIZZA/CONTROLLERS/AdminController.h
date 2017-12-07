#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "pizzadata.h"
#include "ToppingData.h"
#include <stdlib.h>
#include "Pizza.h"

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
        void modifyBreadsticks();
        void modifySodas();
        void displayAllToppings();
        void addTopping();
        void removeTopping();
        void modifyToppings();
        void displayAllPizzas();
        void displayAllBreadsticks();
        void displayAllSodas();
        void addPizzaToMenu();
        void addBreadsticksToMenu();
        void addSodaToMenu();
        void removePizzaFromMenu();
        void removeBreadsticksFromMenu();
        void removeSodaFromMenu();
};

#endif // ADMINCONTROLLER_H
