#ifndef GLOBALCONTROLLER_H
#define GLOBALCONTROLLER_H
#include <iostream>
#include <string>
#include <vector>
#include "LocationData.h"


using namespace std;


class GlobalController {
  private:
    LocationData locationData;

  public:
    GlobalController();
    string chooseLocation();

};

#endif // GLOBALCONTROLLER_H
