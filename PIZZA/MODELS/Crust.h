#ifndef CRUST_H
#define CRUST_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

class Crust
{
  private:
    string name;
    double price;

  public:
    Crust();
    Crust(string name, double price);
    string getName();
    double getPrice();

    void setName(string name);
    void setPrice(double price);

    friend ifstream& operator >> (ifstream& fin, Crust& crust);
    friend ofstream& operator << (ofstream& fout, Crust& crust);
};


#endif // TOPPING_H
