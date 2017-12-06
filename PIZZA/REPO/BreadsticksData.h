#ifndef BREADSTICKSDATA_H
#define BREADSTICKSDATA_H
#include "Breadsticks.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class BreadsticksData
{
    public:
        BreadsticksData();
        void storeAllBreadsticks(vector<Breadsticks> breadsticks);
        vector<Breadsticks> retrieveAllBredsticks();
        void addBreadsticks(Breadsticks& breadsticks);

    private:
        void clearBreadsticks();

};

#endif // BREADSTICKSDATA_H
