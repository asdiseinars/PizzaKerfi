#include "AdminUI.h"


void AdminUI::displayAdminUI() {
    cout << "1: Toppings" << endl;
    cout << "2. Pizzas" << endl;
    cout << "3. Drinks" << endl;
    cout << "4: Side orders" << endl;
    cout << "5: Locations" << endl;
    cout << "6: Crusts" << endl;
    cout << "h: Go home" << endl;
}

void AdminUI::displayAdminToppingUI() {
    cout << "\e[1m" << "TOPPINGS" << "\e[0m" << endl;
    cout << "1: See all toppings" << endl;
    cout << "2: Add new topping" << endl;
    cout << "3: Remove topping" << endl;
    cout << "b: Go back" << endl;
    cout << "h: Go home" << endl;
}

void AdminUI::displayAdminBackOrQuitUI() {
    cout << "b: Go back" << endl;
    cout << "Press anything else to quit" << endl;
}

void AdminUI::displayAdminPizzaUI() {
    cout << "\e[1m" << "PIZZAS" << "\e[0m" << endl;
    cout << "1: See all pizzas on menu" << endl;
    cout << "2: Add new pizza to menu" << endl;
    cout << "3: Remove pizza from menu" << endl;
    cout << "b: Go back" << endl;
    cout << "h: Go home" << endl;
}

void AdminUI::displayAdminSodasUI() {
    cout << "\e[1m" << "SODAS" << "\e[0m" << endl;
    cout << "1: See all drinks" << endl;
    cout << "2: Add new drink to menu" << endl;
    cout << "3: Remove drink from menu" << endl;
    cout << "b: Go back" << endl;
    cout << "h: Go home" << endl;
}

void AdminUI::displayAdminLocationUI() {
    cout << "\e[1m" << "LOCATIONS" << "\e[0m" << endl;
    cout << "1: See all locations" << endl;
    cout << "2: Add new location" << endl;
    cout << "3: Remove location" << endl;
    cout << "b: Go back" << endl;
    cout << "h: Go home" << endl;
}

void AdminUI::displayAdminSideOrderUI() {
    cout << "\e[1m" << "SIDE ORDERS" << "\e[0m" << endl;
    cout << "1: See all side orders" << endl;
    cout << "2: Add new side order" << endl;
    cout << "3: Remove side order" << endl;
    cout << "b: Go back" << endl;
    cout << "h: Go home" << endl;
}

void AdminUI::displayAdminCrustUI() {
    cout << "\e[1m" << "CRUSTS" << "\e[0m" << endl;
    cout << "1: See all crusts" << endl;
    cout << "2: Add new crust" << endl;
    cout << "3: Remove crust" << endl;
    cout << "b: Go back" << endl;
    cout << "h: Go home" << endl;
}





