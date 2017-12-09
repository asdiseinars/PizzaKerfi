#ifndef ORDER_H
#define ORDER_H
#include "Breadsticks.h"
#include "Crust.h"
#include "Location.h"
#include "Order.h"
#include "Pizza.h"
#include "Soda.h"
#include "Topping.h"
#include <string>

class Order
{
     private:
         string location;
         vector<Pizza> pizzas;
         vector<Breadsticks> breadsticks;
         vector<Soda> sodas;

    public:
        Order();
        Order(string location, vector<Pizza> pizzas, vector<Breadsticks> breadsticks, vector<Soda> sodas);

        void setLocation(string location);
        void setPizzas(vector<Pizza> pizzas);
        void setBreadsticks(vector<Breadsticks> breadsticks);
        void setSodas(vector<Soda> sodas);

        string getLocation();
        vector<Pizza> getPizzas();
        vector<Breadsticks> getBreadsticks();
        vector<Soda> getSodas();

        friend ofstream& operator << (ofstream& fout, Order& order);
        friend ifstream& operator >> (ifstream& fin, Order& order);
};

#endif // ORDER_H
