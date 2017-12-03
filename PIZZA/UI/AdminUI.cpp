#include "AdminUI.h"


void AdminUI::displayAdminUI(){
    cout << "Press 1 to edit toppings" << endl;
    cout << "Press 2 to edit pizzas" << endl;
    cout << "Press b to go back" << endl;
}

void AdminUI::displayToppingUI(){
    cout << "m: add topping" << endl;
    cout << "r: read pizza" << endl;
    cout << "b: back" << endl;
}
