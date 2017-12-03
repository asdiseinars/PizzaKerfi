#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H
#include "PizzaUI.h"
#include "HomeUI.h"
#include "GlobalHelp.h"
#include "SalesmanController.h"
#include "BakerController.h"
#include "CustomerController.h"

using namespace GlobalHelp;
using namespace HomeUI;
using namespace BakerUI;
using namespace SalesmanUI;
using namespace CustomerUI;

class HomeController
{
    public:
        HomeController();
        void init();

    private:
};

#endif // HOMECONTROLLER_H
