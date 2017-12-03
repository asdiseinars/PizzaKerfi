#include "SalesmanController.h"

SalesmanController::SalesmanController()
{
    //ctor
}


void SalesmanController::init(){

    displayLogo();
    displaySalesmanUI();
    char selection = '\0';
    cin >> selection;

    if (selection == '1') {
        clearScreen();
        displayLogo();
        displaySalesmanMenuUI();

        cin >> selection;

        if (selection == 'b') {
            clearScreen();
            SalesmanController salesman;
            salesman.init();

        }
    }

    else if (selection == '2') {
        clearScreen();
        displayLogo();
        cout << "Make your own pizza" << endl;
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
