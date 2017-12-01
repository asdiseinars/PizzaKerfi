#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H
#include "PizzaUI.h"
#include "HomeUI.h"
#include "GlobalHelp.h"

using namespace GlobalHelp;
using namespace HomeUI;

class HomeController
{
    public:
        HomeController();
        virtual ~HomeController();
        void init();

    private:
};

#endif // HOMECONTROLLER_H
