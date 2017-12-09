#ifndef SODA_H
#define SODA_H
#include <iostream>
#include <string>

using namespace std;

class Soda {
  private:
    string name;
    double price;
    bool verbose;

  public:
    Soda();
    Soda(string name, double price);

    string getName();
    double getPrice();

    void setName(string name);
    void setPrice(double price);

    friend istream& operator >> (istream& in, Soda& soda);
    friend ostream& operator << (ostream& out, Soda& soda);

};

#endif // SODA_H
