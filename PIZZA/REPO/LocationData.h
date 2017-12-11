#ifndef LOCATIONDATA_H
#define LOCATIONDATA_H
#include <Location.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class LocationData {
  private:
  public:
    LocationData();
    void addLocation(Location& location);
    void storeAllLocations(vector<Location> locations);
    vector<Location> retrieveAllLocations();

};

#endif // LOCATIONDATA_H
