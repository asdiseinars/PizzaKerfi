#ifndef DELIVERYCONTROLLER_H
#define DELIVERYCONTROLLER_H
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
#include "DeliveryUI.h"

using namespace GlobalHelp;
using namespace std;
using namespace DeliveryUI;

class DeliveryController
{
    private:
        GlobalController globalController;
        OrderData orderData;
    public:
        DeliveryController();
        void init();
        void modifyDelivery(string yourLocation);
        void displayOrders(string yourLocation);
        void displayReadyOrders(string yourLocation);
        void displayReadyOrdersForCustomer(string yourLocation);
};

#endif // DELIVERYCONTROLLER_H
