#include "BakerController.h"

BakerController::BakerController() {
    //ctor
}

void BakerController::init() {
    displayLogo();
    displayBakerLogo();

    string yourLocation = globalController.chooseLocation();

    clearScreen();
    displayLogo();
    displayBakerLogo();
    cout << "\e[1m\033[4m" << "Your location is " << yourLocation << "\e[0m\033[0m" << endl << endl;
    displayBakerOrderUI();
    modifyBakerOrders(yourLocation);
}


void BakerController::modifyBakerOrders(string yourLocation) {
    char selection = '\0';
    cin >> selection;

    if(selection == '1') {
        clearScreen();
        displayLogo();
        displayBakerLogo();

        vector<Order> ordersForLocation = orderData.getOrderForLocation(yourLocation);

        cout << "ORDERS" << endl;
        cout << "------------------------------------------" << endl;

        for (unsigned int i = 0; i < ordersForLocation.size(); i++) {
            cout << "[" << i + 1 << "]" << endl;
            for(unsigned int j = 0; j < ordersForLocation.at(i).getPizzasFromMenu().size(); j++) {

                cout << "Name: " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getName() << endl;
                cout << "Crust: " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                cout << "Toppings: " << endl;
                for (unsigned int k = 0; k < ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                    cout << ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << endl;

                }
                cout << endl;
            }
            cout << endl;

            for(unsigned int m = 0; m < ordersForLocation.at(i).getPizzasFromScratch().size(); m++) {
                cout << "Name: " << ordersForLocation.at(i).getPizzasFromScratch().at(m).getName() << endl;
                cout << "Crust: " << ordersForLocation.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                cout << "Toppings: " << endl;
                for (unsigned int n = 0; n < ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {
                    cout << ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << endl;
                }
            }

            cout << endl;

            cout << "Side orders: " << endl;
            for(unsigned int l = 0; l < ordersForLocation.at(i).getBreadsticks().size(); l++) {
                cout << ordersForLocation.at(i).getBreadsticks().at(l).getName() << endl;
            }

            cout << endl;

        }
        cout << "------------------------------------------" << endl;
    }

    else if(selection == '2') {

    }

    else if(selection == 'b') {

    }

}





