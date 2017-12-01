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
        displayHome();
        cin >> selection;

    }while(selection !='1' &&
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
        cout << "Welcome salesman" << endl;

        cout << endl;

    }
    else if (selection == '3'){
        cout << "Welcome baker" << endl;
        cout << endl;

    }
    else if (selection == '4'){
        cout << "Welcome customer" << endl;
        cout << endl;
    }

    else if (selection == 'h'){
        ///texti

    }
    else if (selection == 'a'){
        ///texti
    }
}
