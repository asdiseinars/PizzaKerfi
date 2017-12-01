#include "HomeController.h"


HomeController::HomeController()
{
    //ctor
}

HomeController::~HomeController()
{
    //dtor
}

void HomeController::init(){

    char selection = '\0';

    do{
        clearScreen();
        displayLogo();
        displayHome();
        cin >> selection;

    }
    while(selection !='1' &&
           selection != '2' &&
           selection != '3' &&
           selection != '4' &&
           selection != 'h' &&
           selection != 'q' &&
           selection != 'a');


    if(selection == '1'){
        PizzaUI pizzaui;
        pizzaui.displayPizzaUI();
        cout << endl;
    }

    else if (selection == '2'){
        clearScreen();
        displaySalesmanUI();
    }

    else if (selection == '3'){
        clearScreen();
        displayBakerUI();
    }

    else if (selection == '4'){
        clearScreen();
        displayCustomerUI();
    }

    else if (selection == 'h'){
        clearScreen();
        cout << "Help" << endl;
    }

    else if (selection == 'a'){
        clearScreen();
        cout << "About" << endl;
    }
}
