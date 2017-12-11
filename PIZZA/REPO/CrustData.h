#ifndef CRUSTDATA_H
#define CRUSTDATA_H
#include "Crust.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class CrustData {

  private:

  public:
    CrustData();
    void storeAllCrusts(vector<Crust> crust);
    vector<Crust> retrieveAllCrusts();
    void addCrust(Crust& crust);
};

#endif // TOPPINGDATA_H

