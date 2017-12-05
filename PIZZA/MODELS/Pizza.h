#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include "ToppingData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int MAX_TOPPINGS = 15;


class Pizza
{
    private:
        string name;
        string size;
        double price;
        vector<Topping> toppings;
        int toppingCount;


    public:
        Pizza();
        Pizza(string size, vector<Topping> toppings, int toppingsToAdd);
        bool verbose;
        //void write(ofstream& fout) const;
        //void read(ifstream& fin);

        void createPizza();
        void chooseToppings();
        //void fixName();


        string getName();
        string getSize();
        double getPrice();
        vector<Topping> getToppings();

        void setName(string name);
        void setSize(string size);
        void setPrice(double price);
        void setToppings(vector<Topping> toppings);
        void setVerbose(bool verbose);

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);


};


#endif // PIZZA_H
