#include "SalesmanUI.h"

void SalesmanUI::displaySalesmanUI() {
    cout << "Press 1 to add pizzas to order" << endl;
    cout << "Press 2 to add drinks to order" << endl;
    cout << "Press 3 to add side orders to order" << endl;
    cout << "Press 4 to complete order" << endl;
    cout << "Press b to go back" << endl;
}

void SalesmanUI::displaySalesmanPizzaUI() {
    cout << "Press 1 to choose pizza from menu" << endl;
    cout << "Press 2 to make your own pizza" << endl;
    cout << "Press b to go back" << endl;
}

void SalesmanUI::displaySalesmanDrinksUI() {
    cout << "Choose drinks: " << endl;
}

void SalesmanUI::displaySalesmanSideOrdersUI() {
    cout << "Choose side orders: " << endl;
}

void SalesmanUI::displaySalesmanCompleteOrderUI() {
    cout << "Complete order: " << endl;
}

void SalesmanUI::displaySalesmanBackOrQuitUI() {
    cout << "b: Go back" << endl;
    cout << "q: Quit" << endl;
}
