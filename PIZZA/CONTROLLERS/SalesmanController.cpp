#include "SalesmanController.h"

SalesmanController::SalesmanController()
{
    //ctor
}


void SalesmanController::init(){

    displayLogo();
    displaySalesmanUI();
    char selection = '\0';
    cout << "Insert option" << endl;
    cin >> selection;

    if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
