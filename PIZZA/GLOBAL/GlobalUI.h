#ifndef GLOBALUI_H
#define GLOBALUI_H
#include <iostream>
#include <string>
#include <vector>
#include "BreadsticksData.h"
#include "SodaData.h"
#include "CrustData.h"
#include "pizzadata.h"
#include "LocationData.h"

using namespace std;



class GlobalUI
{
  private:
    PizzaData pizzaData;
    ToppingData toppingData;
    LocationData locationData;
    BreadsticksData breadsticksData;
    SodaData sodaData;
    CrustData crustData;

  public:
    GlobalUI();
    void displayAllToppings();
    void displayAllPizzas();
    void displayAllSodas();
    void displayAllLocations();
    void displayAllBreadsticks();
    void displayAllCrusts();


};

#endif // GLOBALUI_H
