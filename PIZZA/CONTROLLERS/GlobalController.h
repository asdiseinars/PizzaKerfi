#ifndef GLOBALCONTROLLER_H
#define GLOBALCONTROLLER_H
#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "LocationData.h"
#include "BreadsticksData.h"
#include "SodaData.h"
#include "CrustData.h"
#include "pizzadata.h"

using namespace std;


class GlobalController
{
    private:
        PizzaData pizzaData;
        ToppingData toppingData;
        LocationData locationData;
        BreadsticksData breadsticksData;
        SodaData sodaData;
        CrustData crustData;

    public:
        GlobalController();
        string chooseLocation();
        void displayAllToppings();
        void displayAllPizzas();
        void displayAllSodas();
        void displayAllLocations();
        void displayAllBreadsticks();
        void displayAllCrusts();



};

#endif // GLOBALCONTROLLER_H
