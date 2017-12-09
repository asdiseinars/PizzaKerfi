#ifndef SODADATA_H
#define SODADATA_H
#include "Soda.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class SodaData {
  private:

  public:
    SodaData();
    void storeAllSodas(vector<Soda> sodas);
    vector<Soda> retrieveAllSodas();
    void addSoda(Soda& soda);
    //Soda selectSoda();

};

#endif // TOPPINGDATA_H

