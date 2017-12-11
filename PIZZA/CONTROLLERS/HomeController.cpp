#include "HomeController.h"


HomeController::HomeController() {

}

void HomeController::init() {

    char selection = '\0';

    do {
        clearScreen();
        displayLogo();
        displayHomeLogo();
        displayHomeUI();
        cin >> selection;

    } while(selection !='1' &&
            selection != '2' &&
            selection != '3' &&
            selection != '4' &&
            selection != 'c' &&
            selection != 'q' &&
            selection != 'a');

    if(selection == '1') {
        clearScreen();
        AdminController admin;
        admin.init();
    }

    else if (selection == '2') {
        clearScreen();
        SalesmanController salesman;
        salesman.init();
    }

    else if (selection == '3') {
        clearScreen();
        BakerController baker;
        baker.init();
    }

    else if (selection == '4') {
        clearScreen();
        CustomerController customer;
        customer.init();
    }

    else if (selection == 'c') {
        clearScreen();
        displayLogo();
        displayContactUsUI();

        cout << endl;
        displayCustumerBackOrQuitUI();
        char selection;
        cin >> selection;
        if (selection == 'b') {
            clearScreen();
            init();
        } //laga?
    }

    else if (selection == 'a') {
        clearScreen();
        displayLogo();
        displayAboutUI();

        cout << endl;
        displayCustumerBackOrQuitUI();
        char selection;
        cin >> selection;
        if (selection == 'b') {
            clearScreen();
            init();
        }
    }
}
