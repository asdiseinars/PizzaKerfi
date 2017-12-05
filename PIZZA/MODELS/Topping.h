#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>

using namespace std;


class Topping
{

    private:
        int number;
        string name;
        double price;

    public:
        Topping();
        Topping(string name, double price);
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        int get_number();
        string get_name();
        double get_price();
        void set_number(int number);
        void set_name(string name);
        void set_price(double price);
        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, Topping& topping);


};

#endif // TOPPING_H
