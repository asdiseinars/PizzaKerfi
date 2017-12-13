#ifndef ORDERDATA_H
#define ORDERDATA_H
#include <iostream>
#include "Order.h"
#include <vector>

using namespace std;

class OrderData {

  private:

  public:
    OrderData();
    void addOrderToOrders(Order& order);
    void addOrderToLegacy(Order& order);
    vector<Order> retrieveAllOrders();
    void storeAllOrders(vector<Order> order);
    vector<Order> getOrderForLocation(string location);
    vector<Order> getOrderForLocationAndOrderStatus(string location, int orderStatus);
    vector<Order> getOrderForLocationAndOrderStatusAndPhoneNumber(string location, int orderStatus, string phoneNumber);
    vector<Order> retrieveAllOrdersFromLegacy();
    void storeAllOrdersToLegacy(vector<Order> orders);
    void removeFromOrder(string yourLocation);
    void moveOrderToLegacy(string yourLocation);

};

#endif // ORDERDATA_H
