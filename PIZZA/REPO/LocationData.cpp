#include "LocationData.h"

LocationData::LocationData(){
}


void LocationData::addLocation(Location& location){
    ofstream fout;
    fout.open("location.txt", ios::app);

    location.setVerbose(false);
    fout << location;
    fout.close();
    location.setVerbose(true);
}

vector<Location> LocationData::retrieveAllLocations(){
    vector <Location> locations;
    Location location;

    ifstream fin;
    fin.open("location.txt");
    while(!fin.eof()) {
        location.setVerbose(false);
        fin >> location;
        location.setVerbose(true);
        locations.push_back(location);
    }
    locations.pop_back();

    return locations;
}

void LocationData::storeAllLocations(vector<Location> locations){
    ofstream fout;
    fout.open("location.txt");

    for(unsigned int i = 0; i < locations.size(); i++) {
        locations[i].setVerbose(false);
        fout << locations[i];
    }
    fout.close();
}
