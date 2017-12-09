#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
}



void SalesmanController::init() {
    displayLogo();
    displaySalesmanLogo();
    string yourLocation = globalController.chooseLocation();
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






