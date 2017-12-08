#include "BakerController.h"

BakerController::BakerController() {
    //ctor
}

void BakerController::init() {
    displayLogo();
    displayBakerLogo();
    displayBakerUI();

    char selection = '\0';
    cin >> selection;

    chooseLocation();

    if(selection == '1') {
        clearScreen();
        displayLogo();
        displayBakerLogo();
        displayBakerOrdersUI();
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}

void BakerController::chooseLocation(){
    vector<Location> locations;
    LocationData locationData;
    locations = locationData.retrieveAllLocations();

    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl << endl;
    for(unsigned int i = 0; i < locations.size(); i++){
        cout << "Location number: [" << i+1 << "]" << endl;
        cout << locations[i] << endl << endl;
    }
    cout << "------------------------------------------" << endl;

    //cout << "Choose location: ";
    char input = 0;
    cin >> input;
    int inputInt = input - 48;
    for(unsigned int i = 0; i < locations.size(); i++){
        if(inputInt == i + 1){
            //?? = locations[i]; hérna verðum við að vista hvaða location hann valdi svo við getum kallað í það í hinum föllunum

        }
    }
}

