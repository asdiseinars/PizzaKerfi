#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H
#include "PizzaUI.h"
#include "HomeUI.h"
#include "GlobalHelp.h"
#include "SalesmanController.h"
#include "BakerController.h"
#include "CustomerController.h"
#include "AdminController.h"
#include "AboutUI.h"
#include "AdminUI.h"
#include "CustomerUI.h"
#include "DeliveryController.h"

using namespace GlobalHelp;
using namespace HomeUI;
using namespace AdminUI;
using namespace BakerUI;
using namespace SalesmanUI;
using namespace CustomerUI;
using namespace AboutUI;

class HomeController {
  public:
    HomeController();
    void init();

  private:
};

#endif // HOMECONTROLLER_H
