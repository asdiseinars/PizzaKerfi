#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


class Topping
{

    private:
        string name;
        double price;


    public:
        Topping();
        Topping(string name, double price);
        bool verbose;
        string getName();
        double getPrice();

        void setName(string name);
        void setPrice(double price);
        void setVerbose(bool verbose);

        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, Topping& topping);


};


#endif // TOPPING_H
