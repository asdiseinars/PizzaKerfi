#include "AdminController.h"


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

    else if (selection == '7') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyOrders();
    }

    else if (selection == 'h') {
        HomeController home;
        home.init();
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

void AdminController::modifyToppings() {
    char selection;
    displayAdminToppingUI();
    cin >> selection;

    if(selection == '1') { // Displays a list of all toppings
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalUI.displayAllToppings();
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

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }
    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyToppings();
    }
}

void AdminController::addTopping() {
    char selection = 'y';

    cout << "\033[4m" << "Add toppings to menu" <<  "\033[0m" << endl << endl;

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

    char selection = 'y';

    cout << "\033[4m" << "Remove topping from menu" <<  "\033[0m" << endl << endl;

    while(selection == 'y') {
        vector<Topping> toppings = toppingData.retrieveAllToppings();
        cout << endl;

        globalUI.displayAllToppings();

        cout << "What topping do you want to remove? ";
        unsigned int input;
        cin >> input;
        input -= 1;

        if (input + 1 > toppings.size() || input + 1 <= 0) {
            cout << "Invalid input!" << endl << endl;

        } else {
            toppings.erase(toppings.begin() + input);
            toppingData.storeAllToppings(toppings);
            cout << endl << "The topping has been removed!" << endl << endl;
        }

        cout << "Do you want to remove another topping? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to remove another topping? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        }
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
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalUI.displayAllPizzas();
        pizzaBackFunction();
    }

    else if (selection == '2') { //Add new pizza to menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addPizzaToMenu();
        pizzaBackFunction();
    }

    else if (selection == '3') { //Remove pizza from menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removePizzaFromMenu();
        pizzaBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyCrust();
    }
}

void AdminController::addPizzaToMenu() {
    char selection = 'y';

    while(selection == 'y') {

        cout << "\033[4m" << "Add pizza to menu" <<  "\033[0m" << endl << endl;

        string myName;
        vector<Topping> myToppings;
        cout << "Pizza name: ";
        cin >> myName;
        double myPrice;
        cout << "Pizza price: ";
        cin >> myPrice;

        while (myPrice < 0) {
            cout << "Invalid input. Please enter a positive integer as your price!" << endl;
            cout << "Price: ";
            cin >> myPrice;
        }

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

        while (toppingCount < 0) {
            cout << "Invalid input!" << endl;
            cout << "How many toppings do you want to add to your pizza?";
            cin >> toppingCount;
        }

        cout << "Please enter the numbers for the toppings you want to add to your pizza. " << endl;
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

        cout << "Do you want to add another pizza? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to add another pizza? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        displayAdminLogo();
    }
}

void AdminController::removePizzaFromMenu() {
    char selection = 'y';

    cout << "\033[4m" << "Remove pizza from menu" <<  "\033[0m" << endl << endl;

    while(selection == 'y') {
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

    cout << "What pizza do you want to remove? ";
    unsigned int input;
    cin >> input;
    input -= 1;

    if (input + 1 > pizzas.size() || input + 1 <= 0) {
            cout << "Invalid input!" << endl << endl;
    }

    else {
        pizzas.erase(pizzas.begin() + input);

        pizzaData.storeAllPizzas(pizzas);
        cout << endl << "The pizza has been removed from the menu!" << endl << endl;
    }
    cout << "Do you want to remove another pizza? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to remove another pizza? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        displayAdminLogo();
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

void AdminController::modifyOrders() {
    char selection;
    displayAdminOrderUI();
    cin >> selection;

    if (selection == '1') {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        displayAllOrders();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifySodas();
    }
}

void AdminController::modifySodas() {
    char selection;
    displayAdminSodasUI();
    cin >> selection;

    if (selection == '1') { //All sodas
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalUI.displayAllSodas();
        sodaBackFunction();
    }

    else if (selection == '2') { //Add new soda to menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addSodaToMenu();
        sodaBackFunction();
    }

    else if (selection == '3') { //Remove soda from menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removeSodaFromMenu();
        sodaBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifySodas();
    }

}

void AdminController::addSodaToMenu() {
    char selection = 'y';

    cout << "\033[4m" << "Add soda to menu" <<  "\033[0m" << endl << endl;

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
    char selection = 'y';

    cout << "\033[4m" << "Remove soda from menu" <<  "\033[0m" << endl << endl;

    while(selection == 'y') {
        vector<Soda> sodas = sodaData.retrieveAllSodas();
        cout << endl;

        globalUI.displayAllSodas();

        cout << "What drink do you want to remove? ";
        unsigned int input;
        cin >> input;
        input -= 1;

        if (input + 1 > sodas.size() || input + 1 <= 0) {
            cout << "Invalid input!" << endl << endl;
        }
        else {
            sodas.erase(sodas.begin() + input);
            sodaData.storeAllSodas(sodas);
            cout << endl << "The drink has been removed!" << endl << endl;
        }

        cout << "Do you want to remove another drink? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to remove another drink? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        displayAdminLogo();
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

void AdminController::modifyLocations() {

    displayAdminLocationUI();
    char selection;
    cin >> selection;

    if(selection == '1') { // Displays a list of all locations
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalUI.displayAllLocations();
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

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyLocations();
    }
}

void AdminController::addLocations() {
    char selection = 'y';

    cout << "\033[4m" << "Add location to menu" <<  "\033[0m" << endl << endl;

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
    char selection = 'y';

    cout << "\033[4m" << "Remove pizza from menu" <<  "\033[0m" << endl << endl;

    while(selection == 'y') {
        vector<Location> locations = locationData.retrieveAllLocations();

        globalUI.displayAllLocations();

        cout << "What location do you want to remove? ";
        unsigned int input;
        cin >> input;
        input -= 1;

        if (input + 1 > locations.size() || input + 1 <= 0) {
            cout << "Invalid input!" << endl << endl;
        }
        else {
            locations.erase(locations.begin() + input);
            locationData.storeAllLocations(locations);
            cout << endl << "The location has been removed!" << endl << endl;
        }

        cout << "Do you want to remove another location? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to remove another location? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        displayAdminLogo();
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

void AdminController::modifyBreadsticks() {
    char selection;
    displayAdminSideOrderUI();
    cin >> selection;

    if (selection == '1') { //All breadsticks
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalUI.displayAllBreadsticks();
        breadsticksBackFunction();
    }

    else if (selection == '2') { //Add new breadsticks to menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addBreadsticksToMenu();
        breadsticksBackFunction();
    }

    else if (selection == '3') { //Remove breadsticks from menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removeBreadsticksFromMenu();
        breadsticksBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyBreadsticks();
    }
}

void AdminController::addBreadsticksToMenu() {
    char selection = 'y';

    cout << "\033[4m" << "Add side order to menu" <<  "\033[0m" << endl << endl;

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
    char selection = 'y';

    cout << "\033[4m" << "Remove side order from menu" <<  "\033[0m" << endl << endl;

    while(selection == 'y') {
        vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
        cout << endl;

        globalUI.displayAllBreadsticks();

        cout << "What side order do you want to remove? ";
        unsigned int input;
        cin >> input;
        input -= 1;

        if (input + 1 > breadsticks.size() || input + 1 <= 0) {
            cout << "Invalid input!" << endl << endl;
        }
        else {
            breadsticks.erase(breadsticks.begin() + input);
            breadsticksData.storeAllBreadsticks(breadsticks);
            cout << endl << "The side order has been removed!" << endl << endl;
        }

        cout << "Do you want to remove another side order? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to remove another side order? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        displayAdminLogo();
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

void AdminController::modifyCrust() {
    char selection;
    displayAdminCrustUI();
    cin >> selection;

    if (selection == '1') { //All crusts on menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        globalUI.displayAllCrusts();
        crustBackFunction();
    }

    else if (selection == '2') { //Add new crust to menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        addCrustToMenu();
        crustBackFunction();
    }

    else if (selection == '3') { //Remove crust from menu
        clearScreen();
        displayLogo();
        displayAdminLogo();
        removeCrustFromMenu();
        crustBackFunction();
    }

    else if (selection == 'b') {
        clearScreen();
        init();
    }

    else if (selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayAdminLogo();
        modifyCrust();
    }
}

void AdminController::addCrustToMenu() {
    char selection = 'y';

    cout << "\033[4m" << "Add crust to menu" <<  "\033[0m" << endl << endl;

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
    char selection = 'y';

    cout << "\033[4m" << "Remove crust from menu" <<  "\033[0m" << endl << endl;

    while(selection == 'y') {
        vector<Crust> crusts = crustData.retrieveAllCrusts();
        cout << endl;

        globalUI.displayAllCrusts();

        cout << "What crust do you want to remove? ";
        unsigned int input;
        cin >> input;
        input -= 1;

        if (input + 1 > crusts.size() || input + 1 <= 0) {
            cout << "Invalid input!" << endl << endl;
        }
        else {
            crusts.erase(crusts.begin() + input);
            crustData.storeAllCrusts(crusts);
            cout << endl << "The crust has been removed!" << endl << endl;
        }

        cout << "Do you want to remove another crust? (y/n)" << endl;
        cin >> selection;

        while(selection != 'y' && selection != 'n') {
            cout << endl << "Invalid input! " << endl << endl;
            cout << "Do you want to remove another crust? (y/n)" << endl;
            cin >> selection;
            cout << endl;
        }
        clearScreen();
        displayLogo();
        displayAdminLogo();
    }
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

void AdminController::displayAllOrders() {
    vector<Order> allOrders = orderData.retrieveAllOrders();

    cout << "ORDERS" << endl;
    cout << "------------------------------------------" << endl;

    for (unsigned int i = 0; i < allOrders.size(); i++) {

            cout << "\e[1m" << "[" << i + 1 << "]" << "\e[0m" << endl;

            cout << "\e[1m" << "PIZZAS FROM MENU: " << "\e[0m" << endl;
            for(unsigned int j = 0; j < allOrders.at(i).getPizzasFromMenu().size(); j++) {

                cout <<  "\tName: "  << allOrders.at(i).getPizzasFromMenu().at(j).getName() << endl;
                cout << "\tCrust: " << allOrders.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                cout <<  "\tToppings: ";
                for (unsigned int k = 0; k < allOrders.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                    cout << allOrders.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << "  ";
                    } cout << endl;
            }
            cout << endl;

            cout << "\e[1m" << "CUSTOMIZED PIZZAS: " << "\e[0m" << endl;
            for(unsigned int m = 0; m < allOrders.at(i).getPizzasFromScratch().size(); m++) {
                cout << "\tCrust: " << allOrders.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                cout << "\tToppings: ";
                for (unsigned int n = 0; n < allOrders.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {
                    cout << allOrders.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << "  ";
                }
            }

            cout << endl << endl;

            cout << "\e[1m" << "SIDE ORDERS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < allOrders.at(i).getBreadsticks().size(); l++) {
                cout << "\t" << allOrders.at(i).getBreadsticks().at(l).getName() << endl;
            }

            cout << endl;


            cout << "\e[1m" << "DRINKS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < allOrders.at(i).getSodas().size(); l++) {
                cout << "\t" << allOrders.at(i).getSodas().at(l).getName() << endl;
            }

            cout << endl;

            cout << "Order status: ";
            if(allOrders.at(i).getOrderStatus() == 1) {
                cout << "Order recieved" << endl;
            }
            else if(allOrders.at(i).getOrderStatus() == 2) {
                cout << "In oven" << endl;
            }
            else if(allOrders.at(i).getOrderStatus() == 3) {
                cout << "Ready for delivery" << endl;
            }
            else{
                cout << "Invalid order status" << endl;
            }

            cout << endl;

            cout << "Total price of order: " << allOrders.at(i).getTotalPrice() << endl;

            cout << "------------------------------------------" << endl;

    }
    endMessage();
}

void AdminController::endMessage() {
    char selection;

    cout << "Press h to go home" << endl;
    cout << "Press q to quit" << endl;

    cin >> selection;

    if (selection == 'h') {
        HomeController home;
        home.init();
    }
    else if (selection == 'q') {
        return;
    }
    else {
        cout << "Invalid input!" << endl;
        endMessage();
    }
}
