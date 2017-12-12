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

    else if (selection == '6') { //Add/edit crust
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyCrust();
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        init();

    }
}

void AdminUI::validateUserInputModifyToppings(char selection) {
    if(selection == '2') {
        try{

        }
        catch (InvalidPriceExceptions) {
            cout << "Invalid input!" << endl;
        }
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
        globalController.displayAllToppings();
        toppingBackFunction();
    }

    else if (selection == '2') { // Adds new topping to the list
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addTopping();

        toppingBackFunction();
    }

    else if (selection == '3') { // Removes topping from the list
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removeTopping();

        toppingBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::addTopping() {
    char selection = 'y';

    while(selection == 'y') {
        string newName;
        double newPrice;

        cout << "Name: ";
        cin >> newName;
        cout << "Price: ";
        cin >> newPrice;
        Topping topping(newName, newPrice);
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

    globalController.displayAllToppings();

    cout << "What topping do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    toppings.erase(toppings.begin() + input);

    toppingData.storeAllToppings(toppings);
    cout << endl << "The topping has been removed!" << endl << endl;

}

void AdminController::toppingBackFunction() {
    displayAdminBackOrQuitUI();
        char selection;
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

void AdminController::modifyPizzas() {
    char selection;
    displayAdminPizzaUI();
    cin >> selection;

    if (selection == '1') { //See all pizzas
        globalController.displayAllPizzas();
        pizzaBackFunction();
    }

    else if (selection == '2') { //Add new pizza to menu
        addPizzaToMenu();
        pizzaBackFunction();
    }

    else if (selection == '3') { //Remove pizza from menu
        removePizzaFromMenu();
        pizzaBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::addPizzaToMenu() { ///gera fallegra
    string myName;
    vector<Topping> myToppings;
    cout << "Pizza name: ";
    cin >> myName;
    double myPrice;
    cout << "Pizza price: ";
    cin >> myPrice;

    cout << endl;

    cout << "CRUSTS" << endl;
    cout << "------------------------------------------" << endl;
    vector<Crust> crusts = crustData.retrieveAllCrusts();
    for(unsigned int i = 0; i < crusts.size(); i++) {
        Crust crust = crusts.at(i);
        cout << "[" << i+1 << "] \t" << crust.getName() << endl;
    }
    cout << "------------------------------------------" << endl;

    char inputCrust;
    cout << "Please select a crust." << endl;
    cin >> inputCrust;
    int inputIntCrust = inputCrust - 48;
    Crust myCrust = crusts.at(inputIntCrust - 1);

    cout << "TOPPINGS" << endl;
    cout << "------------------------------------------" << endl;
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    for(unsigned int i = 0; i < toppings.size(); i++) {
        Topping topp = toppings.at(i);
        cout << "[" << i+1 << "] \t" << topp.getName() << endl;
    }
    cout << "------------------------------------------" << endl;

    int toppingCount = 0;
    int inputTopping = 0;

    cout << endl << "How many toppings do you want to add to your pizza?" << endl;
    cin >> toppingCount;

    cout << "Please enter the number of toppings you want to add to your pizza. " << endl;
    for(int i = 0; i < toppingCount; i++) {
        cin >> inputTopping;
        Topping topping = toppings.at(inputTopping - 1);
        cout << "Name: " << topping.getName() << "\t" <<"Price: " << topping.getPrice() << endl;
        myToppings.push_back(topping);
    }

    Pizza newPizza(myName, myPrice, toppingCount, myToppings, myCrust);
    pizzaData.addPizzaToMenu(newPizza);

    cout << endl;
    cout << myName << " has been added to your menu!" << endl;
    cout << endl;

}

void AdminController::removePizzaFromMenu() {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();
    cout << endl;

    for (unsigned int i = 0; i < pizzas.size(); i++) {
            cout << "[" << i+1 << "] " << pizzas.at(i).getName() << endl;
            cout << "----------" << endl;
            cout << "\t" << pizzas.at(i).getPrice() << "kr." << endl;
            cout << "\tToppings: " << endl;
            for(unsigned  int j = 0; j < pizzas.at(i).getToppings().size(); j++){
                Topping t = pizzas.at(i).getToppings().at(j);
                cout << "\t\t" << pizzas.at(i).getToppings().at(j).getName() << endl;
            }
            cout << endl;
        }

    cout << "What topping do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    pizzas.erase(pizzas.begin() + input);

    pizzaData.storeAllPizzas(pizzas);
    cout << endl << "The pizza has been removed from the menu!" << endl << endl;

}

void AdminController::pizzaBackFunction() {
    displayAdminBackOrQuitUI();
    char selection;
    cin >> selection;

    if (selection == 'b') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyPizzas();
    }
    else if (selection == 'q') {
        return;
    }
}

void AdminController::modifySodas() {
    char selection;
    displayAdminSodasUI();
    cin >> selection;

    if (selection == '1') { //All pizzas
        globalController.displayAllSodas();
        sodaBackFunction();
    }

    else if (selection == '2') { //Add new soda to menu
        addSodaToMenu();
        sodaBackFunction();
    }

    else if (selection == '3') { //Remove soda from menu
        removeSodaFromMenu();
        sodaBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::addSodaToMenu() {
    char selection = 'y';

    while(selection == 'y') {
        string newName;
        double newPrice;

        cout << "Name: ";
        cin >> newName;
        cout << "Price: ";
        cin >> newPrice;
        Soda soda(newName, newPrice);
        sodaData.addSoda(soda);
        cout << endl << "Do you want to add another drink? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another drink? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    }
}

void AdminController::removeSodaFromMenu() {
    vector<Soda> sodas = sodaData.retrieveAllSodas();
    cout << endl;

    globalController.displayAllSodas();

    cout << "What drink do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    sodas.erase(sodas.begin() + input);

    sodaData.storeAllSodas(sodas);
    cout << endl << "The drink has been removed!" << endl << endl;
}

void AdminController::sodaBackFunction(){
    displayAdminBackOrQuitUI();
    char selection;
    cin >> selection;

    if (selection == 'b') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifySodas();
    }
    else if (selection == 'q') {
        return;
    }
}

void AdminController::modifyLocations() {

    displayAdminLocationUI();
    char selection;
    cin >> selection;

    if(selection == '1') { // Displays a list of all locations
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalController.displayAllLocations();
        locationBackFunction();
    }

    else if (selection == '2') { // Adds new location to the list
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addLocations();
        locationBackFunction();
    }

    else if (selection == '3') { // Removes location from the list
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removeLocations();
        locationBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::addLocations() {
    char selection = 'y';
    while(selection == 'y') {

        string newName;
        cout << "Name: ";
        cin >> newName;

        Location location(newName);
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

    globalController.displayAllLocations();

    cout << "What location do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    locations.erase(locations.begin() + input);

    locationData.storeAllLocations(locations);
    cout << endl << "The topping has been removed!" << endl << endl;
}

void AdminController::locationBackFunction() {
    displayAdminBackOrQuitUI();
    char selection;
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

void AdminController::modifyBreadsticks() {
    char selection;
    displayAdminSideOrderUI();
    cin >> selection;

    if (selection == '1') { //All breadsticks
        globalController.displayAllBreadsticks();
        breadsticksBackFunction();
    }

    else if (selection == '2') { //Add new breadsticks to menu
        addBreadsticksToMenu();
        breadsticksBackFunction();
    }

    else if (selection == '2') { //Remove breadsticks from menu
        removeBreadsticksFromMenu();
        breadsticksBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::addBreadsticksToMenu() {
    char selection = 'y';

    while(selection == 'y') {
        string newName;
        double newPrice;

        cout << "Name: ";
        cin >> newName;
        cout << "Price: ";
        cin >> newPrice;
        Breadsticks bread(newName, newPrice);
        breadsticksData.addBreadsticks(bread);
        cout << endl << "Do you want to add another side order? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another side order? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    }
}

void AdminController::removeBreadsticksFromMenu() {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    cout << endl;

    globalController.displayAllBreadsticks();

    cout << "What side order do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    breadsticks.erase(breadsticks.begin() + input);

    breadsticksData.storeAllBreadsticks(breadsticks);
    cout << endl << "The side order has been removed!" << endl << endl;
}

void AdminController::breadsticksBackFunction() {
    displayAdminBackOrQuitUI();
    char selection;
    cin >> selection;

    if (selection == 'b') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyBreadsticks();
    }

    else if (selection == 'q') {
        return;
    }
}

void AdminController::modifyCrust() {
    char selection;
    displayAdminCrustUI();
    cin >> selection;

    if (selection == '1') { //All crusts on menu
        globalController.displayAllCrusts();
        crustBackFunction();
    }

    else if (selection == '2') { //Add new crust to menu
        addCrustToMenu();
        crustBackFunction();
    }

    else if (selection == '3') { //Remove crust from menu
        removeCrustFromMenu();
        crustBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }
}

void AdminController::addCrustToMenu() {
    char selection = 'y';

    while(selection == 'y') {
        string newName;
        double newPrice;

        cout << "Name: ";
        cin >> newName;
        cout << "Price: ";
        cin >> newPrice;
        Crust crust(newName, newPrice);
        crustData.addCrust(crust);
        cout << endl << "Do you want to add another crust? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another crust? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    }
}

void AdminController::removeCrustFromMenu() {
    vector<Crust> crusts = crustData.retrieveAllCrusts();
    cout << endl;

    globalController.displayAllCrusts();

    cout << "What crust do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    crusts.erase(crusts.begin() + input);

    crustData.storeAllCrusts(crusts);
    cout << endl << "The crust has been removed!" << endl << endl;
}

void AdminController::crustBackFunction() {
    displayAdminBackOrQuitUI();
    char selection;
    cin >> selection;

    if (selection == 'b') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyCrust();
    }

    else if (selection == 'q') {
        return;
    }
}
