#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H
#include "PizzaUI.h"
#include "HomeUI.h"
#include "GlobalHelp.h"
#include "BakerUI.h"
#include "SalesmanUI.h"
#include "CustomerUI.h"

using namespace GlobalHelp;
using namespace HomeUI;
using namespace BakerUI;
using namespace SalesmanUI;
using namespace CustomerUI;

class HomeController
{
    public:
        HomeController();
        virtual ~HomeController();
        void init();

    private:
};

#endif // HOMECONTROLLER_H
