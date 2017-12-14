#include "DeliveryController.h"

DeliveryController::DeliveryController()
{
    //ctor
}

void DeliveryController::endMessage() {
    cout << "Press q to quit" << endl;
    cout << "Press h to go home" << endl;
    cout << "Press anything else to continue" << endl;


    char input = '\0';
    cin >> input;

    if (input == 'q') {
        return;
    }
    else if (input == 'h') {
        HomeController home;
        home.init();
    }
    else {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
    }
}

void DeliveryController::init() {
    displayLogo();
    displayDeliveryLogo();
    string yourLocation = globalController.chooseLocation();
    modifyDelivery(yourLocation);
}

void DeliveryController::modifyDelivery(string yourLocation) {
    /*cout << " is your current location" << endl << endl; ///viljum ekki að þetta komi ef location er ekki valid
    endMessage();*/

    clearScreen();
    displayLogo();
    displayDeliveryLogo();
    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
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
    else if (selection == 'b') {
        clearScreen();
        init();
    }
    else if (selection == 'h') {
        HomeController home;
        home.init();
    }
    else {
        modifyDelivery(yourLocation);
    }
}

void DeliveryController::displayOrders(string yourLocation) {
    vector<Order> allOrders = orderData.retrieveAllOrders();

    cout << "ORDERS" << endl;
    cout << "------------------------------------------" << endl;

    for (unsigned int i = 0; i < allOrders.size(); i++) {

            cout << "\e[1m" << "[" << i + 1 << "]" << "\e[0m" << endl;

            cout << "\e[1m" << "PIZZAS FROM MENU: " << "\e[0m" << endl;
            for(unsigned int j = 0; j < allOrders.at(i).getPizzasFromMenu().size(); j++) {

                cout <<  "\tName: "  << allOrders.at(i).getPizzasFromMenu().at(j).getName() << endl;
                cout << "\tCrust: " << allOrders.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                cout <<  "\tToppings: ";
                for (unsigned int k = 0; k < allOrders.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                    cout << allOrders.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << "  ";
                    } cout << endl;
            }
            cout << endl;

            cout << "\e[1m" << "CUSTOMIZED PIZZAS: " << "\e[0m" << endl;
            for(unsigned int m = 0; m < allOrders.at(i).getPizzasFromScratch().size(); m++) {
                cout << "\tCrust: " << allOrders.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                cout << "\tToppings: ";
                for (unsigned int n = 0; n < allOrders.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {
                    cout << allOrders.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << "  ";
                }
                cout << endl << endl;
            }

            cout << endl;


            cout << "\e[1m" << "SIDE ORDERS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < allOrders.at(i).getBreadsticks().size(); l++) {
                cout << "\t" << allOrders.at(i).getBreadsticks().at(l).getName() << endl;
            }

            cout << endl;


            cout << "\e[1m" << "DRINKS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < allOrders.at(i).getSodas().size(); l++) {
                cout << "\t" << allOrders.at(i).getSodas().at(l).getName() << endl;
            }

            cout << endl;

            cout << "Order status: ";
            if(allOrders.at(i).getOrderStatus() == 1) {
                cout << "Order recieved" << endl;
            }
            else if(allOrders.at(i).getOrderStatus() == 2) {
                cout << "In oven" << endl;
            }
            else if(allOrders.at(i).getOrderStatus() == 3) {
                cout << "Ready for delivery" << endl;
            }
            else{
                cout << "Invalid order status" << endl;
            }

            cout << endl;

            cout << "Total price of order: " << allOrders.at(i).getTotalPrice() << " kr." << "\e[0m" << endl;

            cout << "------------------------------------------" << endl;
    }

    cout << "Press h to go home" << endl;
    cout << "Press any other button to quit the program" << endl;


    char input = '\0';
    cin >> input;

    if (input == 'h') {
        HomeController home;
        home.init();
    }
    else {
        return;
    }
}

void DeliveryController::displayReadyOrders(string yourLocation) {
    vector<Order> ordersForLocation = orderData.getOrderForLocationAndOrderStatus(yourLocation, 3);

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;

    cout << "\e[1m" << "ORDERS" << "\e[0m" << endl;
    cout << "------------------------------------------" << endl;

    for (unsigned int i = 0; i < ordersForLocation.size(); i++) {
        if (ordersForLocation[i].getOrderStatus() == 3) {
            cout << "\e[1m" << "[" << i + 1 << "]" << "\e[0m" << endl;

            cout << "\e[1m" << "PIZZAS FROM MENU: " << "\e[0m" << endl;
            for(unsigned int j = 0; j < ordersForLocation.at(i).getPizzasFromMenu().size(); j++) {

                cout <<  "\t"  << ordersForLocation.at(i).getPizzasFromMenu().at(j).getName() << " " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getPrice() << " kr." << endl;
                cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromMenu().at(j).getCrust().getName() << endl;

                cout <<  "\tToppings: ";
                for (unsigned int k = 0; k < ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().size(); k++) {

                    cout << ordersForLocation.at(i).getPizzasFromMenu().at(j).getToppings().at(k).getName() << "  ";
                    }
                    cout << endl << endl;
            }
            cout << endl;

            cout << "\e[1m" << "CUSTOMIZED PIZZAS: " << "\e[0m" << endl;
            for(unsigned int m = 0; m < ordersForLocation.at(i).getPizzasFromScratch().size(); m++) {
                cout << "\tCrust: " << ordersForLocation.at(i).getPizzasFromScratch().at(m).getCrust().getName() << endl;

                cout << "\tToppings: ";
                double sum = 0;
                for (unsigned int n = 0; n < ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().size(); n++) {

                    cout << ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getName() << "  ";
                    sum += ordersForLocation.at(i).getPizzasFromScratch().at(m).getToppings().at(n).getPrice();
                }
                cout << endl << "\tPrice: " << sum + ordersForLocation.at(i).getPizzasFromScratch().at(m).getCrust().getPrice() + 1500 <<  " kr." << endl;
                cout << endl;
            }

            cout << "\e[1m" << "SIDE ORDERS: " << "\e[0m" << endl;
            for(unsigned int l = 0; l < ordersForLocation.at(i).getBreadsticks().size(); l++) {
                cout << "\t" << ordersForLocation.at(i).getBreadsticks().at(l).getName() << "  " << ordersForLocation.at(i).getBreadsticks().at(l).getPrice() << " kr." << endl;
            }

            cout << "\e[1m" << "SODAS: " << "\e[0m" << endl;
            for(unsigned int p = 0; p < ordersForLocation.at(i).getBreadsticks().size(); p++) {
                cout << "\t" << ordersForLocation.at(i).getSodas().at(p).getName() << "  " << ordersForLocation.at(i).getSodas().at(p).getPrice() << " kr." << endl;
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
                cout << "Ready for delivery" << endl;
            }
            else{
                cout << "\e[1m" << "Invalid order status" << "\e[0m" << endl;
            }

            cout << endl;

            cout << "Total price: "  << "\e[1m" << ordersForLocation.at(i).getTotalPrice() << " kr." << "\e[0m" << endl;

            cout << "------------------------------------------" << endl;
        }
    }

    cout << "Press h to go home" << endl;
    cout << "Press b to go back" << endl;
    cout << "Press anything else to quit" << endl;

    char selection = '\0';
    cin >> selection;

    if (selection == 'h') {
        HomeController home;
        home.init();
    }
    else if (selection == 'b') {
        clearScreen();
        modifyDelivery(yourLocation);
    }
    else {
        return;
    }
}

void DeliveryController::displayReadyOrdersForCustomer(string yourLocation) {
    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
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

    char selection = '\0';
    cin >> selection;

    if (selection == 'h') {
        HomeController home;
        home.init();
    }
    else if (selection == 'b') {
        clearScreen();
        modifyDelivery(yourLocation);
    }
    else {
        return;
    }
}

void DeliveryController::markeOrderPaidAndDeliverd(string yourLocation, string phoneNumber) {
    cout << "Mark order paid and deliverd? (y/n)" << endl;
    char inputforno;
    char inputforyes;
    cin >> inputforno;

    if(inputforno == 'y') {
        vector<Order> thisOrder = orderData.getOrderForLocationAndOrderStatusAndPhoneNumber(yourLocation, 3, phoneNumber);
        for(int i = 0; i < thisOrder.size(); i++) {
            thisOrder.at(i).setOrderStatus(4);
            orderData.storeAllOrders(thisOrder);
        }
        cout << "The order has been marked" << endl;
        cout << "Press h to go home" << endl;
        cout << "Press anything else to quit" << endl;
        cin >> inputforyes;

        if (inputforyes == 'h') {
            HomeController home;
            home.init();
        }
        else {
            return;
        }
    }
    else {
        cout << "Press h to go home" << endl;
        cout << "Press anything else to quit" << endl;
        cin >> inputforno;

        if (inputforno == 'h') {
            HomeController home;
            home.init();
        }
        else {
            return;
        }
    }


        /*clearScreen();
        displayLogo();
        displayDeliveryLogo();
        displayReadyOrdersForCustomer(yourLocation);*/
}


