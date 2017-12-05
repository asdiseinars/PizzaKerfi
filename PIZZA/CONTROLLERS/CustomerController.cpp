#include "CustomerController.h"

CustomerController::CustomerController()
{
    //ctor
}

void CustomerController::init(){

    displayLogo();
    displayCustomerLogo();
    displayCustomerUI();

    char selection = '\0';
    cin >> selection;

    if(selection == '1'){
        clearScreen();
        displayLogo();
        displayCustomerLogo();
        displayCustomerMenuUI();

        cin >> selection;

        if(selection == '1'){
            cout << "The pizza that you orderd" << endl;
        }
        else if(selection == 'b'){
            clearScreen();
            init();
        }
    }

    else if(selection == '2'){
        clearScreen();
        displayLogo();
        displayCustomerLogo();
        cout << "Make your own pizza" << endl;
        cout << "Add toppings" << endl;

    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
