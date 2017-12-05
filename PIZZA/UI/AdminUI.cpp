#include "AdminUI.h"


void AdminUI::displayAdminUI(){
    cout << "Press 1 to add/edit toppings" << endl;
    cout << "Press 2 to edit pizzas" << endl;
    cout << "Press b to go back" << endl;
}

void AdminUI::displayAdminToppingUI(){
    cout << "Press 1 to see all toppings" << endl;
    cout << "Press 2 to add new toppings" << endl;
    cout << "Press 3 to remove toppings" << endl;
    cout << "Press b to go back" << endl;
}

void AdminUI::displayAdminPizzaUI() {
    cout << "Press 1 to see all pizzas on menu" << endl;
    cout << "Press 2 to add new pizza to menu" << endl;
    cout << "Press 3 to remove pizza from menu" << endl;
    cout << "Press b to go back" << endl;
}
