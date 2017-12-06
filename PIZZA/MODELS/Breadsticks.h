#ifndef BREADSTICKS_H
#define BREADSTICKS_H
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Breadsticks
{

    private:
        string name;
        double price;
        bool verbose;

    public:
        Breadsticks();
        Breadsticks(string name, double price);

        string getName();
        double getPrice();

        void setName(string name);
        void setPrice(double price);
        void setVerbose(bool verbose);

        friend istream& operator >> (istream& in, Breadsticks& breadsticks);
        friend ostream& operator << (ostream& out, Breadsticks& breadsticks);


};


#endif // TOPPING_H
