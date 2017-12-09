#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "pizzadata.h"
#include "ToppingData.h"
#include "LocationData.h"
#include <stdlib.h>
#include "Pizza.h"
#include "BreadsticksData.h"
#include "SodaData.h"

using namespace GlobalHelp;
using namespace AdminUI;

class AdminController {
  private:
    PizzaData pizzaData;
    ToppingData toppingData;
    LocationData locationData;
    BreadsticksData breadsticksData;
    SodaData sodaData;

  public:
    AdminController();
    void init();

    void modifyPizzas();
    void displayAllPizzas();
    void addPizzaToMenu();
    void removePizzaFromMenu();

    void modifyToppings();
    void displayAllToppings();
    void addTopping();
    void removeTopping();

    void modifyBreadsticks();
    void displayAllBreadsticks();
    void addBreadsticksToMenu();
    void removeBreadsticksFromMenu();

    void modifySodas();
    void displayAllSodas();
    void addSodaToMenu();
    void removeSodaFromMenu();

    void modifyLocations();
    void displayAllLocations();
    void addLocations();
    void removeLocations();
};

#endif // ADMINCONTROLLER_H
