#include "AdminController.h"

AdminController::AdminController() {

}

void AdminController::init(){
    displayLogo();
    displayAdminLogo();
    displayAdminUI();

    char selection = '\0';
    cin >> selection;

    if (selection == '1') { //add/edit toppings
        clearScreen();
        displayLogo();
        displayAdminLogo();

        modifyToppings();
    }

    else if (selection == '2') { // Add/edit pizzas
        clearScreen();
        displayLogo();
        displayAdminLogo();

        modifyPizzas();
    }

    else if (selection == '3') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}

void AdminController::modifyToppings() {
    char selection;
    displayAdminToppingUI();
    cin >> selection;

        if(selection == '1') { // Displays a list of all toppings
            clearScreen();
            displayLogo();
            displayAdminLogo();
            displayAllToppings();
            displayAdminBackOrQuitUI();
            cin >> selection;

            if (selection == 'b') {
                clearScreen();
                displayLogo();
                displayAdminLogo();
                modifyToppings();
            }
            else if (selection == 'q') {
                return;
            }
        }

        else if (selection == '2') { // Adds new topping to the list
            clearScreen();
            displayLogo();
            displayAdminLogo();
            addTopping();

            displayAdminBackOrQuitUI();

            cin >> selection;

              if (selection == 'b') {
                clearScreen();
                displayLogo();
                displayAdminLogo();
                modifyToppings();
            }
            else if (selection == 'q') {
                return;
            }

        }

        else if (selection == '3') { // Removes topping from the list
           clearScreen();
           displayLogo();
           displayAdminLogo();
           removeTopping();

           displayAdminBackOrQuitUI();

           cin >> selection;

           if (selection == 'b') {
                clearScreen();
                displayLogo();
                displayAdminLogo();
                modifyToppings();
            }
            else if (selection == 'q') {
                return;
            }
        }

        else if (selection == 'b') {
            clearScreen();
            init();
        }
}


void AdminController::displayAllToppings(){
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    for (unsigned int i = 0; i < toppings.size(); i++) {
        Topping topp = toppings.at(i);
        cout << topp << endl;
    }
}

void AdminController::addTopping() {
    char selection = 'y';

    while(selection == 'y'){
        Topping topping;
        cin >> topping;
        toppingData.addTopping(topping);

        cout << endl << "Do you want to add another topping? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another topping? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    }
}

void AdminController::removeTopping() { //Laga þetta fall
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    cout << endl;

    for(unsigned int i = 0; i < toppings.size(); i++){
        Topping topp = toppings.at(i);
        cout << "Number: [" << i+1 << "]"<< endl;
        cout << topp << endl;
    }

    cout << "What topping do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    toppings.erase(toppings.begin() + input);

    toppingData.storeAllToppings(toppings);
    cout << endl << "The topping has been removed!" << endl << endl;

}

void AdminController::modifyPizzas() {
    char selection;
    displayAdminPizzaUI();
    cin >> selection;

    if (selection == '1') { //All pizzas
        displayAllPizzas();
    }

    else if (selection == '2') { //Add new pizza to menu
        addPizzaToMenu();
    }

    else if (selection == '2') { //Remove pizza from menu
        removePizzaFromMenu();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::displayAllPizzas() { //Útfæra fall
}

void AdminController::addPizzaToMenu() { //útfæra fall
}

void AdminController::removePizzaFromMenu() {//útfæra fall
}


