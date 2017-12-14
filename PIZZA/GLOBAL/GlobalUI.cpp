#include "GlobalUI.h"

GlobalUI::GlobalUI()
{
    //ctor
}

void GlobalUI::displayAllToppings() {
    vector<Topping> toppings = toppingData.retrieveAllToppings();
    if(toppings.size() < 1) {
        cout << "There are no toppings on the menu! " << endl;
    } else {
        cout << "\e[1m" << "TOPPINGS" << "\e[0m" << endl;
        cout << "-----------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < toppings.size(); i++) {
            Topping topping = toppings.at(i);
            cout << "[" << i+1 << "] " << "Name: " << topping.getName() << "\t \t Price: " << topping.getPrice() << " kr."  << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void GlobalUI::displayAllPizzas() {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();
    if(pizzas.size() < 1) {
        cout << "There are no pizzas on the menu! " << endl;
    } else {
        cout << "\e[1m" << "PIZZA MENU" << "\e[0m" << endl;
        cout << "------------------------------------------" << endl;
        for (unsigned int i = 0; i < pizzas.size(); i++) {
            cout << "[" << i+1 << "] " << pizzas.at(i).getName() << " " << pizzas.at(i).getPrice() << " kr." << endl;
            cout << "\tCrust: " << pizzas.at(i).getCrust().getName() << endl;
            cout << "\tToppings: ";
            for(unsigned  int j = 0; j < pizzas.at(i).getToppings().size(); j++) {
                Topping t = pizzas.at(i).getToppings().at(j);
                cout << pizzas.at(i).getToppings().at(j).getName() << "  ";
            }
            cout << endl;
        cout << "------------------------------------------" << endl;
            cout << endl;
        }

    }
}

void GlobalUI::displayAllSodas() {
    vector<Soda> sodas = sodaData.retrieveAllSodas();
    if(sodas.size() < 1) {
        cout << "There are no drinks on the menu! " << endl;
    } else {
        cout << "\e[1m" << "DRINKS" << "\e[0m" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < sodas.size(); i++) {
            Soda soda = sodas.at(i);
            cout << "[" << i+1 << "] " << "Name: " << soda.getName() << "\t \t Price: " << soda.getPrice() << " kr." << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void GlobalUI::displayAllLocations() {
    vector<Location> locations = locationData.retrieveAllLocations();
    if(locations.size() < 1) {
        cout << "There are no locations!" << endl;
    } else {
        cout << "\e[1m" << "LOCATIONS" << "\e[0m" << endl;
        cout << "------------------------------------------" << endl;
        for (unsigned int i = 0; i < locations.size(); i++) {
            Location location = locations.at(i);
            cout << "[" << i+1 << "] " << location.getName() << endl;
        }
    }
    cout << "------------------------------------------" << endl;
}

void GlobalUI::displayAllBreadsticks() {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    if(breadsticks.size() < 1) {
        cout << "There are no side orders on the menu! " << endl;
    } else {
        cout << "\e[1m" << "SIDE ORDERS" << "\e[0m" << endl;
        cout << "------------------------------------------" << endl << endl;
        for (unsigned int i = 0; i < breadsticks.size(); i++) {
            Breadsticks bread = breadsticks.at(i);
            cout << "[" << i+1 << "] " << "Name: " << bread.getName() << "\t \t Price: " << bread.getPrice() << " kr." << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void GlobalUI::displayAllCrusts () {
    vector<Crust> crusts = crustData.retrieveAllCrusts();
    if(crusts.size() < 1) {
        cout << "There are no crusts on the menu! " << endl;
    } else {
        cout << "\e[1m" << "CRUSTS" << "\e[0m" << endl;
        cout << "------------------------------------------" << endl;
        for (unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "[" << i+1 << "] " << "Name: " << crust.getName() << "\t \t Price: " << crust.getPrice() << " kr." << endl;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}
