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
    vector<Order> retrieveAllOrders();
    void storeAllOrders(vector<Order> order);
};

#endif // ORDERDATA_H
