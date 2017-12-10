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

void AdminController::displayAllToppings() {
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    if(toppings.size() < 1){
        cout << "There are no toppings on the menu! " << endl;
    }
    else{
        cout << "TOPPINGS" << endl;
        cout << "-----------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < toppings.size(); i++) {
            Topping topping = toppings.at(i);
            cout << "Name: " << topping.getName() << "\t \t Price: " << topping.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
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

    cout << "TOPPINGS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < toppings.size(); i++) {
        Topping topp = toppings.at(i);
        cout << "[" << i+1 << "] \t" << topp.getName() << "\t" << topp.getPrice() << endl;
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

void AdminController::modifyPizzas() {
    char selection;
    displayAdminPizzaUI();
    cin >> selection;

    if (selection == '1') { //See all pizzas
        displayAllPizzas();
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

void AdminController::displayAllPizzas() {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();
    if(pizzas.size() < 1){
        cout << "There are no pizzas on the menu! " << endl;
    }
    else{
        for (unsigned int i = 0; i < pizzas.size(); i++) {
            cout << "[" << i+1 << "] " << pizzas.at(i).getName() << " " << pizzas.at(i).getPrice() << "kr." << endl;
            cout << "----------" << endl;
            cout << "Crust: " << pizzas.at(i).getCrust().getName() << endl;
            cout << "\tToppings: " << endl;
            for(unsigned  int j = 0; j < pizzas.at(i).getToppings().size(); j++){
                Topping t = pizzas.at(i).getToppings().at(j);
                cout << "\t\t" << pizzas.at(i).getToppings().at(j).getName() << endl;
            }
            cout << endl;
        }
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

    char selection;
    int toppingCount = 0;

    do {
        char inputTopping;
        cout << "Please enter the number of the topping you want to add to your pizza. " << endl;
        cin >> inputTopping;
        int inputIntTopping = inputTopping - 48;
        Topping topping = toppings.at(inputIntTopping - 1);
        cout << "Name: " << topping.getName() << "\t" <<"Price: " << topping.getPrice() << endl;
        myToppings.push_back(topping);

        toppingCount++;
        cout << toppingCount;

        cout << endl << "Do you want to add another topping? (y/n)" << endl;

        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another topping? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
    } while(selection == 'y');


    Pizza newPizza(myName, myPrice, toppingCount, myToppings, myCrust);
    pizzaData.addPizzaToMenu(newPizza);

    cout << endl;
    cout << myName << " has been added to your menu" << endl;
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

void AdminController::modifySodas() {
    char selection;
    displayAdminSodasUI();
    cin >> selection;

    if (selection == '1') { //All pizzas
        displayAllSodas();
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

void AdminController::modifyLocations() {

    displayAdminLocationUI();
    char selection;
    cin >> selection;

    if(selection == '1') { // Displays a list of all locations
        clearScreen();
        displayLogo();
        displayAdminLogo();
        displayAllLocations();
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

void AdminController::displayAllLocations() {
    vector<Location> locations = locationData.retrieveAllLocations();
    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl;
    if(locations.size() < 1){
        cout << "There are no locations on the menu!" << endl;
    }
    else{
       for (unsigned int i = 0; i < locations.size(); i++) {
            Location location = locations.at(i);
            cout << location.getName() << endl;
        }
    }
    cout << "------------------------------------------" << endl;
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

    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl;

    for(unsigned int i = 0; i < locations.size(); i++) {
        Location location = locations.at(i);
        cout << "[" << i+1 << "]"<< location.getName() << endl;
    }
    cout << "------------------------------------------" << endl;

    cout << "What location do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    locations.erase(locations.begin() + input);

    locationData.storeAllLocations(locations);
    cout << endl << "The topping has been removed!" << endl << endl;
}

void AdminController::modifyBreadsticks() {
    char selection;
    displayAdminSideOrderUI();
    cin >> selection;

    if (selection == '1') { //All breadsticks
        displayAllBreadsticks();
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

void AdminController::displayAllBreadsticks() {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    if(breadsticks.size() < 1){
        cout << "There are no side orders on the menu! " << endl;
    }
    else{
        cout << "SIDE ORDERS" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < breadsticks.size(); i++) {
            Breadsticks bread = breadsticks.at(i);
            cout << "Name: " << bread.getName() << "\t \t Price: " << bread.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
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

    cout << "SIDE ORDERS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < breadsticks.size(); i++) {
        Breadsticks bread = breadsticks.at(i);
        cout << "[" << i+1 << "] \t" << bread.getName() << "\t" << bread.getPrice() << endl;
    }
    cout << "------------------------------------------" << endl;

    cout << "What side order do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    breadsticks.erase(breadsticks.begin() + input);

    breadsticksData.storeAllBreadsticks(breadsticks);
    cout << endl << "The side order has been removed!" << endl << endl;

}

void AdminController::displayAllSodas() {
   vector<Soda> sodas = sodaData.retrieveAllSodas();
    if(sodas.size() < 1){
        cout << "There are no drinks on the menu! " << endl;
    }
    else{
        cout << "DRINKS" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < sodas.size(); i++) {
            Soda soda = sodas.at(i);
            cout << "Name: " << soda.getName() << "\t \t Price: " << soda.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
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

    cout << "DRINKS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < sodas.size(); i++) {
        Soda soda = sodas.at(i);
        cout << "[" << i+1 << "] \t" << soda.getName() << "\t" << soda.getPrice() << endl;
    }
    cout << "------------------------------------------" << endl;

    cout << "What drink do you want to remove? ";
    int input;
    cin >> input;
    input -= 1;

    sodas.erase(sodas.begin() + input);

    sodaData.storeAllSodas(sodas);
    cout << endl << "The drink has been removed!" << endl << endl;
}

void AdminController::modifyCrust() {
    char selection;
    displayAdminCrustUI();
    cin >> selection;

    if (selection == '1') { //All crusts on menu
        displayAllCrusts();
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

void AdminController::displayAllCrusts () {
   vector<Crust> crusts = crustData.retrieveAllCrusts();
    if(crusts.size() < 1){
        cout << "There are no crusts on the menu! " << endl;
    }
    else{
        cout << "CRUSTS" << endl;
        cout << "------------------------------------------" << endl;
        for (unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "Name: " << crust.getName() << "\t \t Price: " << crust.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
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

    cout << "CRUSTS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < crusts.size(); i++) {
        Crust crust = crusts.at(i);
        cout << "[" << i+1 << "] \t" << crust.getName() << "\t" << crust.getPrice() << endl;
    }
    cout << "------------------------------------------" << endl;

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
