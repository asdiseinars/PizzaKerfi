#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"

#include <vector>


class Pizza
{
    private:
        vector<Topping> toppings;

    public:
        Pizza();
        virtual ~Pizza();
        void addTopping(Topping topping);
        void write(ofstream& fout) const;
        void read(ifstream& fin);




};

#endif // PIZZA_H
