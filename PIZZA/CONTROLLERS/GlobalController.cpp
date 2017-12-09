#include "GlobalController.h"

GlobalController::GlobalController()
{
    //ctor
}

string GlobalController::chooseLocation(){
    vector<Location> locations = locationData.retrieveAllLocations();

    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < locations.size(); i++){
        cout << "[" << i+1 << "] " << locations[i].getName() << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << "Choose location: ";
    char input = 0;
    cin >> input;

    string yourLocation = "";

    int inputInt = input - 48;
    for(unsigned int i = 0; i < locations.size(); i++){
        if(inputInt == i + 1){
            yourLocation = locations[i].getName();
        }
    }
    cout << yourLocation;
    return yourLocation;
}
