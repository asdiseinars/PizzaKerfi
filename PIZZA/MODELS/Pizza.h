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
        int number;
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
        int get_number();
        string get_name();
        string get_size();
        double get_price();
        vector<Topping> get_toppings();
        void set_number(int number);
        void set_name(string name);
        void set_size(string size);
        void set_price(double price);
        void set_toppings(vector<Topping> toppings);
        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, Pizza& pizza);
        bool verbose;

};

#endif // PIZZA_H
