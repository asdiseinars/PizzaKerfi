#ifndef SALESMANCONTROLLER_H
#define SALESMANCONTROLLER_H
#include <iostream>
#include "SalesmanUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "GlobalController.h"
#include "Location.h"
#include "LocationData.h"
#include "AdminController.h"
#include "OrderData.h"
#include "pizzadata.h"
#include "CrustData.h"
#include "ToppingData.h"
#include "BreadsticksData.h"
#include "SodaData.h"
#include "OrderData.h"

using namespace GlobalHelp;
using namespace std;
using namespace SalesmanUI;

class SalesmanController {
  private:
      LocationData locationData;
      GlobalController globalController;
      PizzaData pizzaData;
      CrustData crustData;
      ToppingData toppingData;
      BreadsticksData breadsticksData;
      SodaData sodaData;
      OrderData orderData;

  public:
    SalesmanController();
    void chooseLocation();
    void init();
    void modifySalesman(string yourLocation);
    vector<Pizza> orderPizzaFromMenu(int pizzasFromMenuCount);
    vector<Pizza> orderPizzaFromScratch(int pizzasFromScratchCount);
    vector<Breadsticks> orderBreadsticksFromMenu(int breadsticksCount);
    vector<Soda> orderSodaFromMenu(int sodaCount);
    int getSodaCount();
    int getPizzaFromScratchCount();
    int getPizzaFromMenuCount();
    int getBreadsticksCount();


};

#endif // SALESMANCONTROLLER_H
