#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
}

void SalesmanController::init() {
    displayLogo();
    displaySalesmanLogo();
    string yourLocation = globalController.chooseLocation();
    modifySalesman(yourLocation);
}

void SalesmanController::modifySalesman(string yourLocation) {
    clearScreen();
    displayLogo();
    displaySalesmanLogo();
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    char selection;
    displaySalesmanUI();
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
        clearScreen();
        init();
    }
}







