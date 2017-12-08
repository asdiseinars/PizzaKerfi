#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Location
{
    private:
        string name;
    public:
        Location();
        bool verbose;

        string getLocation();
        void setName(string name);
        void setVerbose (bool verbose);

        friend istream& operator >> (istream& in, Location& location);
        friend ostream& operator << (ostream& out, const Location& location);


};

#endif // LOCATIONS_H
