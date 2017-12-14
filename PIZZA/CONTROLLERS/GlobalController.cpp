#include "GlobalController.h"

GlobalController::GlobalController() {
    //ctor
}

string GlobalController::chooseLocation() {
    vector<Location> locations = locationData.retrieveAllLocations();

    cout << "\e[1m" << "LOCATIONS" << "\e[0m" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < locations.size(); i++) {
        cout << "[" << i+1 << "] " << locations[i].getName() << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << "Choose location: ";
    int input = 0;
    string yourLocation = "";
    cin >> input;
    input -= 1;

    while(input >= locations.size() || locations.size() < 0 ) {
        cout << "Location not available!" << endl;
        cout << "Try another location." << endl;
        cin >> input;
        input -= 1;
    }

    for(unsigned int i = 0; i < locations.size(); i++) {
        yourLocation = locations[input].getName();
    }

    cout << yourLocation;

    return yourLocation;
}


