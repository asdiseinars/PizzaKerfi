#include "GlobalController.h"

GlobalController::GlobalController() {
    //ctor
}

string GlobalController::chooseLocation() {
    vector<Location> locations = locationData.retrieveAllLocations();

    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl;
    for(unsigned int i = 0; i < locations.size(); i++) {
        cout << "[" << i+1 << "] " << locations[i].getName() << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << "Choose location: ";
    char input = 0;
    cin >> input;

    string yourLocation = "";

    int inputInt = input - 48;
    for(unsigned int i = 0; i < locations.size(); i++) {
        if(inputInt == i + 1) {
            yourLocation = locations[i].getName();
        }
    }
    cout << yourLocation;
    return yourLocation;
}

void GlobalController::displayAllToppings() {
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    if(toppings.size() < 1) {
        cout << "There are no toppings on the menu! " << endl;
    } else {
        cout << "TOPPINGS" << endl;
        cout << "-----------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < toppings.size(); i++) {
            Topping topping = toppings.at(i);
            cout << "[" << i+1 << "] " << "Name: " << topping.getName() << "\t \t Price: " << topping.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void GlobalController::displayAllPizzas() {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();
    if(pizzas.size() < 1) {
        cout << "There are no pizzas on the menu! " << endl;
    } else {
        for (unsigned int i = 0; i < pizzas.size(); i++) {
            cout << "[" << i+1 << "] " << pizzas.at(i).getName() << " " << pizzas.at(i).getPrice() << "kr." << endl;
            cout << "----------" << endl;
            cout << "Crust: " << pizzas.at(i).getCrust().getName() << endl;
            cout << "\tToppings: " << endl;
            for(unsigned  int j = 0; j < pizzas.at(i).getToppings().size(); j++) {
                Topping t = pizzas.at(i).getToppings().at(j);
                cout << "\t\t" << pizzas.at(i).getToppings().at(j).getName() << endl;
            }
            cout << endl;
        }
    }
}

void GlobalController::displayAllSodas() {
    vector<Soda> sodas = sodaData.retrieveAllSodas();
    if(sodas.size() < 1) {
        cout << "There are no drinks on the menu! " << endl;
    } else {
        cout << "DRINKS" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < sodas.size(); i++) {
            Soda soda = sodas.at(i);
            cout << "[" << i+1 << "] " << "Name: " << soda.getName() << "\t \t Price: " << soda.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void GlobalController::displayAllLocations() {
    vector<Location> locations = locationData.retrieveAllLocations();
    cout << "LOCATIONS" << endl;
    cout << "------------------------------------------" << endl;
    if(locations.size() < 1) {
        cout << "There are no locations on the menu!" << endl;
    } else {
        for (unsigned int i = 0; i < locations.size(); i++) {
            Location location = locations.at(i);
            cout << "[" << i+1 << "] " << location.getName() << endl;
        }
    }
    cout << "------------------------------------------" << endl;
}

void GlobalController::displayAllBreadsticks() {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    if(breadsticks.size() < 1) {
        cout << "There are no side orders on the menu! " << endl;
    } else {
        cout << "SIDE ORDERS" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < breadsticks.size(); i++) {
            Breadsticks bread = breadsticks.at(i);
            cout << "[" << i+1 << "] " << "Name: " << bread.getName() << "\t \t Price: " << bread.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void GlobalController::displayAllCrusts () {
    vector<Crust> crusts = crustData.retrieveAllCrusts();
    if(crusts.size() < 1) {
        cout << "There are no crusts on the menu! " << endl;
    } else {
        cout << "CRUSTS" << endl;
        cout << "------------------------------------------" << endl;
        for (unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "[" << i+1 << "] " << "Name: " << crust.getName() << "\t \t Price: " << crust.getPrice() << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

