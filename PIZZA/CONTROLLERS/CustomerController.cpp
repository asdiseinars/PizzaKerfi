#include "CustomerController.h"

CustomerController::CustomerController()
{
    //ctor
}

void CustomerController::init(){

    displayCustomerUI();

    char selection = '\0';
    cout << "Insert option" << endl;
    cin >> selection;

    if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
