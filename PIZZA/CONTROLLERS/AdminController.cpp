#include "AdminController.h"
#include <iostream>
using namespace std;

AdminController::AdminController() {

}

void AdminController::init() {
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

    else if (selection == '3') { //Add/edit soda
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifySodas();
    }

    else if (selection == '4') { //Add/edit breadsticks
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyBreadsticks();
    }

    else if (selection == '5') { //Add/edit locations
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyLocations();
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
        } else if (selection == 'q') {
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
        } else if (selection == 'q') {
            return;
        }
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::displayAllToppings() {
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    if(toppings.size() < 1){
        cout << "There are no toppings on the menu! " << endl;
    }
    else{
        cout << "TOPPINGS" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < toppings.size(); i++) {
            Topping topp = toppings.at(i);
            cout << topp << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void AdminController::addTopping() {
    char selection = 'y';

    while(selection == 'y') {
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

void AdminController::removeTopping() {
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    cout << endl;

    cout << "TOPPINGS" << endl;
    cout << "------------------------------------------" << endl << endl;
    for(unsigned int i = 0; i < toppings.size(); i++) {
        Topping topp = toppings.at(i);
        cout << "Number: [" << i+1 << "]"<< endl;
        cout << topp << endl;
    }
    cout << "------------------------------------------" << endl;

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

void AdminController::modifyBreadsticks() {
    char selection;
    void displayAdminBreadSticksUI();
    cin >> selection;

    if (selection == '1') { //All breadsticks
        displayAllBreadsticks();
    }

    else if (selection == '2') { //Add new breadsticks to menu
        addBreadsticksToMenu();
    }

    else if (selection == '2') { //Remove breadsticks from menu
        removeBreadsticksFromMenu();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::modifySodas() {
    char selection;
    void displayAdminSodaUI();
    cin >> selection;

    if (selection == '1') { //All pizzas
        displayAllSodas();
    }

    else if (selection == '2') { //Add new soda to menu
        addSodaToMenu();
    }

    else if (selection == '2') { //Remove soda from menu
        removeSodaFromMenu();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::displayAllPizzas() { ///pizzurnar prentast ekki rétt út á skjáinn
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();
    if(pizzas.size() < 1){
        cout << "There are no toppings on the menu! " << endl;
    }
    else{
        for (unsigned int i = 0; i < pizzas.size(); i++) {
            cout << pizzas.at(i) << endl;
        }
    }
}

void AdminController::addPizzaToMenu() {
    string myName;
    vector<Topping> myToppings;
    cout << "Pizza name: ";
    cin >> myName;
    cout << endl;


    cout << "TOPPINGS" << endl;
    cout << "------------------------------------------" << endl << endl;

    vector<Topping> toppings = toppingData.retrieveAllToppings();
    for(unsigned int i = 0; i < toppings.size(); i++) {
        Topping topp = toppings.at(i);
        cout << "Number: [" << i+1 << "]"<< endl;
        cout << topp << endl;
    }

    cout << "------------------------------------------" << endl;

    char selection;
    do {
        char input;
        cout << "Plese enter the number of the topping you want to add to your pizza. " << endl;
        cin >> input;
        int inputInt = input - 48;
        Topping topping = toppings.at(inputInt - 1);
        cout << topping << endl;
        myToppings.push_back(topping);

        cout << endl << "Do you want to add another topping? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another topping? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    } while(selection == 'y');

    Pizza newPizza(myName, myToppings);
    pizzaData.addPizzaToMenu(newPizza);
}

void AdminController::removePizzaFromMenu() { ///kemmst ekki í fallið?? get því ekki testað hvort það sé rétt
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();
    cout << endl;

    for(unsigned int i = 0; i < pizzas.size(); i++) {
        Pizza pizza = pizzas.at(i);
        cout << "Number: [" << i+1 << "]"<< endl;
        cout << pizza << endl;
    }

    cout << "What topping do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    pizzas.erase(pizzas.begin() + input);

    pizzaData.storeAllPizzas(pizzas);
    cout << endl << "The pizza has been removed from the menu!" << endl << endl;

}

void AdminController::modifyLocations() {
    char selection;
    displayAdminLocationUI();
    cin >> selection;

    if(selection == '1') { // Displays a list of all locations
        clearScreen();
        displayLogo();
        displayAdminLogo();
        displayAllLocations();
        displayAdminBackOrQuitUI();
        cin >> selection;

        if (selection == 'b') {
            clearScreen();
            displayLogo();
            displayAdminLogo();
            modifyLocations();
        }

        else if (selection == 'q') {
            return;
        }
    }

    else if (selection == '2') { // Adds new location to the list
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addLocations();

        displayAdminBackOrQuitUI();

        cin >> selection;

        if (selection == 'b') {
            clearScreen();
            displayLogo();
            displayAdminLogo();
            modifyLocations();
        } else if (selection == 'q') {
            return;
        }
    }

    else if (selection == '3') { // Removes location from the list
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removeLocations();
        displayAdminBackOrQuitUI();

        cin >> selection;

        if (selection == 'b') {
            clearScreen();
            displayLogo();
            displayAdminLogo();
            modifyLocations();
        } else if (selection == 'q') {
            return;
        }
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}


void AdminController::displayAllLocations() {
    vector<Location> locations = locationData.retrieveAllLocations();
    if(locations.size() < 1){
        cout << "There are no locations on the menu!" << endl;
    }
    else{
       for (unsigned int i = 0; i < locations.size(); i++) {
            Location location = locations.at(i);
            cout << location << endl;
        }
    }
}

void AdminController::addLocations() {
    char selection = 'y';
    while(selection == 'y') {
        Location location;
        cin >> location;
        locationData.addLocation(location);

        cout << endl << "Do you want to add another location? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another location? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    }
}

void AdminController::removeLocations() {
    vector<Location> locations = locationData.retrieveAllLocations();
    cout << endl;

    for(unsigned int i = 0; i < locations.size(); i++) {
        Location location = locations.at(i);
        cout << "Number: [" << i+1 << "]"<< endl;
        cout << location << endl;
    }

    cout << "What location do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    locations.erase(locations.begin() + input);

    locationData.storeAllLocations(locations);
    cout << endl << "The topping has been removed!" << endl << endl;
}

void AdminController::displayAllBreadsticks() {
}

void AdminController::addBreadsticksToMenu() {
}

void AdminController::removeBreadsticksFromMenu() {
}

void AdminController::displayAllSodas() {
}

void AdminController::addSodaToMenu() {
}


void AdminController::removeSodaFromMenu() {
}
