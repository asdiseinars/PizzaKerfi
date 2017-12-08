#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
}



void SalesmanController::init() {
    displayLogo();
    displaySalesmanLogo();
    chooseLocation();
}



    /*displayLogo();
    displaySalesmanLogo();
    displaySalesmanUI();
    char selection = '\0';
    cin >> selection;

    if (selection == '1') {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
        displaySalesmanMenuUI();

        cin >> selection;

        if (selection == 'b') {
            clearScreen();
            init();

        }
    }

    else if (selection == '2') {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
        cout << "Make your own pizza" << endl;
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
*/

void SalesmanController::chooseLocation(){
    vector<Location> locations;
    locations = locationData.retrieveAllLocations();

    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < locations.size(); i++){
        cout << "Location number: [" << i+1 << "]" << endl;
        Location location;
        cout << location.getName() << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << "Choose location: ";
    char input = 0;
    cin >> input;

    int inputInt = input - 48;
    for(unsigned int i = 0; i < locations.size(); i++){
        if(inputInt == i + 1){
            //yourLocation = locations[i]; hérna verðum við að vista hvaða location hann valdi svo við getum kallað í það í hinum föllunum

        }
    }
}





