#include "DeliveryController.h"

DeliveryController::DeliveryController()
{
    //ctor
}

void DeliveryController::init() {
    displayLogo();
    displayDeliveryLogo();
    string yourLocation = globalController.chooseLocation();
    modifyDelivery(yourLocation);
}

void DeliveryController::modifyDelivery(string yourLocation) {
    clearScreen();
    displayLogo();
    displayDeliveryLogo();
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    displayDeliveryUI();

    char selection = '\0';
    cin >> selection;

    if(selection == '1') {
        clearScreen();
        displayLogo();
        displayDeliveryLogo();
        displayOrders(yourLocation);
    }

    else if (selection == '2') {
        clearScreen();
        displayLogo();
        displayDeliveryLogo();
        displayReadyOrders(yourLocation);
    }

    else if (selection == '3') {
        clearScreen();
        displayLogo();
        displayDeliveryLogo();
        displayReadyOrdersForCustomer(yourLocation);

    }
}

void DeliveryController::displayOrders(string yourLocation) {
    vector<Order> ordersForLocation = orderData.getOrderForLocation(yourLocation);

    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;

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

        cout << "Order status: ";
        if(ordersForLocation.at(i).getOrderStatus() == 1) {
            cout << "Order recieved" << endl;
        }
        else if(ordersForLocation.at(i).getOrderStatus() == 2) {
            cout << "In oven" << endl;
        }
        else if(ordersForLocation.at(i).getOrderStatus() == 3) {
            cout << "Ready" << endl;
        }
        else{
            cout << "Invalid order status! " << endl;
        }

        cout << endl;

        cout << "Total price of order: " << ordersForLocation.at(i).getTotalPrice() << endl;
    }
    cout << "------------------------------------------" << endl;
}

void DeliveryController::displayReadyOrders(string yourLocation) {
    vector<Order> ordersForLocation = orderData.getOrderForLocationAndOrderStatus(yourLocation, 3);

    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;

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

        cout << "Order status: ";
        if(ordersForLocation.at(i).getOrderStatus() == 1) {
            cout << "Order recieved" << endl;
        }
        else if(ordersForLocation.at(i).getOrderStatus() == 2) {
            cout << "In oven" << endl;
        }
        else if(ordersForLocation.at(i).getOrderStatus() == 3) {
            cout << "Ready" << endl;
        }
        else{
            cout << "Invalid order status! " << endl;
        }

        cout << endl;

        cout << "Total price of order: " << ordersForLocation.at(i).getTotalPrice() << endl;
    }
    cout << "------------------------------------------" << endl;
}

void DeliveryController::displayReadyOrdersForCustomer(string yourLocation) {
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    cout << "Please enter customer phone number (7 digits): " << endl;
    string phoneNumber = "";
    cin >> phoneNumber;
    while(phoneNumber.length() != 7) {
        cin >> phoneNumber;
        cout << "Invalid phone number!" << endl;
    }

    vector<Order> ordersForLocation = orderData.getOrderForLocationAndOrderStatusAndPhoneNumber(yourLocation, 3, phoneNumber);

    cout << endl;
    cout << "ORDER FOR PHONENUMBER " << phoneNumber << endl;
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

        cout << "Total price of order: " << ordersForLocation.at(i).getTotalPrice() << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << endl;

    markeOrderPaidAndDeliverd(yourLocation, phoneNumber);
}

void DeliveryController::markeOrderPaidAndDeliverd(string yourLocation, string phoneNumber) {
    cout << "Mark order paid and deliverd? (y/n)" << endl;
    char selection;
    cin >> selection;

    if(selection == 'y') {
        vector<Order> thisOrder = orderData.getOrderForLocationAndOrderStatusAndPhoneNumber(yourLocation, 3, phoneNumber);
        thisOrder.at(0).setOrderStatus(4);
        orderData.storeAllOrders(thisOrder);
        orderData.storeAllOrdersToLegacy(thisOrder);
        //deleteOrderFromFile(yourLocation);
    }

    else {
        clearScreen();
        displayLogo();
        displayDeliveryLogo();
        displayReadyOrdersForCustomer(yourLocation);
    }
}

void DeliveryController::deleteOrderFromFile(string yourLocation) {
    vector<Order> thisOrder = orderData.getOrderForLocation(yourLocation);
    vector<Order> newOrders;
    for (unsigned int i = 0; i < thisOrder.size(); i++) {
        if (thisOrder[i].getOrderStatus() != 4) {
            newOrders.push_back(thisOrder[i]);
        }
        orderData.storeAllOrders(newOrders);
    }
}

