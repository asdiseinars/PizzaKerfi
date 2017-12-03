#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Pizza
{
    private:
        string name;
        string size;
        double price;
        vector<Topping> toppings;

    public:
        Pizza();
        Pizza(int toppingCount);
        void addTopping(Topping topping);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, Pizza& pizza);
        bool verbose;

};

#endif // PIZZA_H
