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
        displaySalesmanPizzaUI();

        cin >> selection;

        if (selection == '1') {
            AdminController adminController;
            adminController.displayAllPizzas();
            ///Her velur salesman pizzu af matseðli
        }

        else if (selection == '2') {
            ///Her velur salesman pizzu fra grunni
        }

        else if (selection == 'b') {
            clearScreen();
            init();
        }
    }

    else if (selection == '2') {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
        displaySalesmanDrinksUI();
        ///Her velur salesman drykki til ad setja i order
    }

    else if (selection == '3') {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
        displaySalesmanSideOrdersUI();
        ///Her velur salesman side orders til ad setja i order
    }

    else if (selection == '4') {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
        displaySalesmanCompleteOrderUI();
        ///Her klárar salesman order
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}







