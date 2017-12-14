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
        displayOrdersForBaker(yourLocation);
        BackOrQuitBakerFunction(yourLocation);
    }

    else if(selection == '2') {
        vector<Order> thisOrders = orderData.getOrderForLocation(yourLocation);
        int input = 0;

        clearScreen();
        displayLogo();
        displayBakerLogo();
        displayOrdersReadyToBePutInOven(yourLocation);

        cout << "What order do you put in the oven? " << endl;

        cin >> input;
        input -= 1;


         while (input > thisOrders.size() || input < 1 || thisOrders[input].getOrderStatus() != 1) {
            clearScreen();
            displayLogo();
            displayBakerLogo();
            displayOrdersInOven(yourLocation);

            cout << "What order do you want to take out of the oven? " << endl;

            cin >> input;
            input -= 1;
        }

        if(thisOrders[input].getOrderStatus() == 1) {
            thisOrders[input].setOrderStatus(2);
            orderData.storeAllOrders(thisOrders);
        }

        BackOrQuitBakerFunction(yourLocation);
    }

    else if (selection == '3') {

        vector<Order> thisOrders = orderData.getOrderForLocation(yourLocation);
        int input = 0;

        clearScreen();
        displayLogo();
        displayBakerLogo();
        displayOrdersInOven(yourLocation);

        cout << "What order do you want to take out of the oven? " << endl;

        cin >> input;
        input -= 1;

        while (input > thisOrders.size() || input < 1 || thisOrders[input].getOrderStatus() != 2) {
            clearScreen();
            displayLogo();
            displayBakerLogo();
            displayOrdersInOven(yourLocation);

            cout << "What order do you want to take out of the oven? " << endl;

            cin >> input;
            input -= 1;
        }


        if(thisOrders[input].getOrderStatus() == 2) {
            thisOrders[input].setOrderStatus(3);
            orderData.storeAllOrders(thisOrders);
        }

        BackOrQuitBakerFunction(yourLocation);
    }

    else if(selection == 'b') {
        clearScreen();
        init();
    }

    else if(selection == 'h') {
        HomeController home;
        home.init();
    }

    else {
        clearScreen();
        displayLogo();
        displayBakerLogo();
        cout << "\e[1m\033[4m" << "Your location is " << yourLocation << "\e[0m\033[0m" << endl << endl;
        displayBakerOrderUI();
        modifyBakerOrders(yourLocation);
    }
}

void BakerController::displayOrdersForBaker(string yourLocation) {
    vector<Order> ordersForLocation = orderData.getOrderForLocation(yourLocation);

    cout << "ORDERS" << endl;
    cout << "------------------------------------------" << endl;

    cout << "size of vector: " << ordersForLocation.size() << endl;

        for (unsigned int i = 0; i < ordersForLocation.size(); i++) {
            if (ordersForLocation[i].getOrderStatus() == 1 || ordersForLocation[i].getOrderStatus() == 2) {
                cout << "\e[1m" << "[" << i + 1 << "]" << "\e[0m" << endl;

                cout << "\e[1m" << "PIZZAS FROM MENU: " << "\e[0m" << endl;
                for(unsigned int j = 0; j < ordersForLocation.at(i).getPizzasFromMenu().size(); j++) {

                    cout <<  "\tName: "  << ordersForLocation.at(i).getPizzasFromMenu().at(j).getName() << endl;
                    cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                    cout <<  "\tToppings: ";
                    for (unsigned int k = 0; k < ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                        cout << ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << "  ";
                        } cout << endl;
                }
                cout << endl;

                cout << "\e[1m" << "CUSTOMIZED PIZZAS: " << "\e[0m" << endl;
                for(unsigned int m = 0; m < ordersForLocation.at(i).getPizzasFromScratch().size(); m++) {
                    cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                    cout << "\tToppings: ";
                    for (unsigned int n = 0; n < ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {
                        cout << ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << "  ";
                    }
                }

                cout << endl << endl;

                cout << "\e[1m" << "SIDE ORDERS: " << "\e[0m" << endl;
                for(unsigned int l = 0; l < ordersForLocation.at(i).getBreadsticks().size(); l++) {
                    cout << "\t" << ordersForLocation.at(i).getBreadsticks().at(l).getName() << endl;
                }

                cout << endl;

                cout << "Order status: ";
                if(ordersForLocation.at(i).getOrderStatus() == 1) {
                    cout << "\e[1m" << "Order recieved" << "\e[0m" << endl;
                }
                else if(ordersForLocation.at(i).getOrderStatus() == 2) {
                    cout << "\e[1m" << "In oven" << "\e[0m" << endl;
                }
                else if(ordersForLocation.at(i).getOrderStatus() == 3) {
                    cout << "\e[1m" << "Ready for delivery" << "\e[0m" << endl;
                }
                else{
                    cout << "\e[1m" << "Invalid order status" << "\e[0m" << endl;
                }

                cout << endl;

                cout << "------------------------------------------" << endl;
           }
        }

}


void BakerController::displayOrdersReadyToBePutInOven(string yourLocation) {
    vector<Order> ordersForLocation = orderData.getOrderForLocation(yourLocation);
    cout << "ORDERS" << endl;
    cout << "------------------------------------------" << endl;

    for (unsigned int i = 0; i < ordersForLocation.size(); i++) {
        if (ordersForLocation[i].getOrderStatus() == 1) {
            cout << "\e[1m" << "[" << i + 1 << "]" << "\e[0m" << endl;

            cout << "\e[1m" << "PIZZAS FROM MENU: " << "\e[0m" << endl;
            for(unsigned int j = 0; j < ordersForLocation.at(i).getPizzasFromMenu().size(); j++) {

                cout <<  "\tName: "  << ordersForLocation.at(i).getPizzasFromMenu().at(j).getName() << endl;
                cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                cout <<  "\tToppings: ";
                for (unsigned int k = 0; k < ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                    cout << ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << "  ";
                    } cout << endl;
            }
            cout << endl;

            cout << "\e[1m" << "CUSTOMIZED PIZZAS: " << "\e[0m" << endl;
            for(unsigned int m = 0; m < ordersForLocation.at(i).getPizzasFromScratch().size(); m++) {
                cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                cout << "\tToppings: ";
                for (unsigned int n = 0; n < ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {
                    cout << ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << "  ";
                }
            }

            cout << endl << endl;

            cout << "\e[1m" << "SIDE ORDERS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < ordersForLocation.at(i).getBreadsticks().size(); l++) {
                cout << "\t" << ordersForLocation.at(i).getBreadsticks().at(l).getName() << endl;
            }

            cout << endl;

            cout << "Order status: ";
            if(ordersForLocation.at(i).getOrderStatus() == 1) {
                cout << "\e[1m" << "Order recieved" << "\e[0m" << endl;
            }
            else if(ordersForLocation.at(i).getOrderStatus() == 2) {
                cout << "\e[1m" << "In oven" << "\e[0m" << endl;
            }
            else if(ordersForLocation.at(i).getOrderStatus() == 3) {
                cout << "\e[1m" << "Ready for delivery" << "\e[0m" << endl;
            }
            else{
                cout << "\e[1m" << "Invalid order status" << "\e[0m" << endl;
            }

            cout << endl;

            cout << "------------------------------------------" << endl;
        }
        else {
            cout << "There is no received order! " << endl;
            break;
        }
    }

}

void BakerController::displayOrdersInOven(string yourLocation) {
    vector<Order> ordersForLocation = orderData.getOrderForLocation(yourLocation);
    cout << "ORDERS" << endl;
    cout << "------------------------------------------" << endl;

    for (unsigned int i = 0; i < ordersForLocation.size(); i++) {
        if (ordersForLocation[i].getOrderStatus() == 2) {
            cout << "\e[1m" << "[" << i + 1 << "]" << "\e[0m" << endl;

            cout << "\e[1m" << "PIZZAS FROM MENU: " << "\e[0m" << endl;
            for(unsigned int j = 0; j < ordersForLocation.at(i).getPizzasFromMenu().size(); j++) {

                cout <<  "\tName: "  << ordersForLocation.at(i).getPizzasFromMenu().at(j).getName() << endl;
                cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                cout <<  "\tToppings: ";
                for (unsigned int k = 0; k < ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                    cout << ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << "  ";
                    } cout << endl;
            }
            cout << endl;

            cout << "\e[1m" << "CUSTOMIZED PIZZAS: " << "\e[0m" << endl;
            for(unsigned int m = 0; m < ordersForLocation.at(i).getPizzasFromScratch().size(); m++) {
                cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                cout << "\tToppings: ";
                for (unsigned int n = 0; n < ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {
                    cout << ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << "  ";
                }
            }
            cout << endl << endl;
            cout << "\e[1m" << "SIDE ORDERS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < ordersForLocation.at(i).getBreadsticks().size(); l++) {
                cout << "\t" << ordersForLocation.at(i).getBreadsticks().at(l).getName() << endl;
            }
            cout << endl;

            cout << "Order status: ";
            if(ordersForLocation.at(i).getOrderStatus() == 1) {
                cout << "\e[1m" << "Order recieved" << "\e[0m" << endl;
            }
            else if(ordersForLocation.at(i).getOrderStatus() == 2) {
                cout << "\e[1m" << "In oven" << "\e[0m" << endl;
            }
            else if(ordersForLocation.at(i).getOrderStatus() == 3) {
                cout << "\e[1m" << "Ready for delivery" << "\e[0m" << endl;
            }
            else{
                cout << "\e[1m" << "Invalid order status" << "\e[0m" << endl;
            }
            cout << endl;
            cout << "------------------------------------------" << endl;
        }
    }
}

void BakerController::BackOrQuitBakerFunction(string location) {
    displayBakerBackOrQuitUI();
        char selection;
        cin >> selection;

        if (selection == 'b') {
            clearScreen();
            displayLogo();
            displayBakerLogo();
            displayBakerOrderUI();
            modifyBakerOrders(location);
        }
        else{
            return;
        }
    }
