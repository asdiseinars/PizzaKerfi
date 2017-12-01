#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>

using namespace std;


class Topping
{

    private:
        string name;
        double price;

    public:
        Topping();
        Topping(string name, double price);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, Topping& topping);


};

#endif // TOPPING_H
