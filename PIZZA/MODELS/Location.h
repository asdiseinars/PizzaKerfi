#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Location
{
    private:
        string name;
    public:
        Location();
        Location(string name);

        string getName();

        void setName(string name);

        friend ifstream& operator >> (ifstream& fin, Location& location);
        friend ofstream& operator << (ofstream& fout, const Location& location);
};

#endif // LOCATIONS_H
