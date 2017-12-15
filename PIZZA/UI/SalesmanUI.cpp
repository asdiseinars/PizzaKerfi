#include "SalesmanUI.h"



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
    cout << "h: Home" << endl;
    cout << "Press anything else to quit" << endl;
}

void SalesmanUI::displayStepsOfOrdering() {
    cout << "\033[4m" << "THE ORDERING STEPS" << "\033[0m" <<endl;
    cout << "  Step 1: Insert phone number of customer" << endl;
    cout << "  Step 2: Order pizza/s from menu" << endl;
    cout << "  Step 3: Order pizza/s made from scratch" << endl;
    cout << "  Step 4: Order side orders" << endl;
    cout << "  Step 5: Order drinks" << endl << endl;
}
