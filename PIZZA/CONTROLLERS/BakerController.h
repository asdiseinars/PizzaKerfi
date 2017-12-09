#ifndef BAKERCONTROLLER_H
#define BAKERCONTROLLER_H
#include "BakerUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "GlobalController.h"
#include "Location.h"
#include "LocationData.h"
#include <iostream>

using namespace GlobalHelp;
using namespace BakerUI;
using namespace std;

class BakerController {
  private:
      LocationData locationData;
      GlobalController globalController;

  public:
    BakerController();
    void init();
    string chooseLocation();
    void modifyBakerOrders();

};

#endif // BAKERCONTROLLER_H
