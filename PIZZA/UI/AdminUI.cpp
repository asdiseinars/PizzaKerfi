#include "AdminUI.h"


void AdminUI::displayAdminUI(){
    cout << "Press 1 to edit toppings" << endl;
    cout << "Press 2 to edit pizzas" << endl;
    cout << "Press b to go back" << endl;
}

void AdminUI::displayAdminToppingUI(){
    cout << "Press 1 to add new toppings" << endl;
    cout << "Press 2 to see all toppings" << endl;
    cout << "Press b to go back" << endl;
}

void AdminUI::displayAdminPizzaUI() {
    cout << "Press 1 to add new pizzas" << endl;
    cout << "Press 2 to see all pizzas" << endl;
    cout << "Press b to go back" << endl;
}
