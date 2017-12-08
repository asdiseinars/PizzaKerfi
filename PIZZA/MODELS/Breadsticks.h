#ifndef BREADSTICKS_H
#define BREADSTICKS_H
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Breadsticks {

  private:
    string name;
    double price;

  public:
    Breadsticks();
    Breadsticks(string name, double price);

    string getName();
    double getPrice();

    void setName(string name);
    void setPrice(double price);

    friend ifstream& operator >> (ifstream& fin, Breadsticks& breadsticks);
    friend ofstream& operator << (ofstream& fout, Breadsticks& breadsticks);

};


#endif // TOPPING_H
