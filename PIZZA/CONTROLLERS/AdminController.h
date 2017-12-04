#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "pizzadata.h"
#include "ToppingData.h"

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
};

#endif // ADMINCONTROLLER_H
