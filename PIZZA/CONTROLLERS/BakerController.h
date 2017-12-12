#ifndef BAKERCONTROLLER_H
#define BAKERCONTROLLER_H
#include "BakerUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "GlobalController.h"
#include "Location.h"
#include "LocationData.h"
#include <iostream>
#include "OrderData.h"
#include "Order.h"
#include <Vector>

using namespace GlobalHelp;
using namespace BakerUI;
using namespace std;

class BakerController {
  private:
    LocationData locationData;
    GlobalController globalController;
    OrderData orderData;

  public:
    BakerController();
    void init();
    string chooseLocation();
    void modifyBakerOrders(string yourLocation);
    void displayOrders(string yourLocation);

};

#endif // BAKERCONTROLLER_H
