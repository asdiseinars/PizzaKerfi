#include "LocationData.h"

LocationData::LocationData() {
}


void LocationData::addLocation(Location& location) {
    ofstream fout;
    fout.open("location.txt", ios::app);


    fout << location;
    fout.close();

}

vector<Location> LocationData::retrieveAllLocations() {
    vector <Location> locations;
    Location location;

    ifstream fin;
    fin.open("location.txt");
    while(!fin.eof()) {

        fin >> location;

        locations.push_back(location);
    }
    locations.pop_back();

    return locations;
}

void LocationData::storeAllLocations(vector<Location> locations) {
    ofstream fout;
    fout.open("location.txt");

    for(unsigned int i = 0; i < locations.size(); i++) {

        fout << locations[i];
    }
    fout.close();
}
