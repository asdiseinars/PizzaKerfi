#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
}

void SalesmanController::endMessage() {
    cout << "h: Go home" << endl;
    cout << "Press anything else to continue" << endl;

    char input = '\0';
    cin >> input;

    if (input == 'q') {
        return;
    }
    else if (input == 'b') {
        HomeController home;
        home.init();
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

void SalesmanController::BackOrQuitSalesmanFunction(){
    char input = '\0';
    cin >> input;

    if (input == 'b') {
        HomeController home;
        home.init();
    }
    else if (input == 'h') {
        HomeController home;
        home.init();
    }
    else {
        return;
    }
}


void SalesmanController::init() {
    displayLogo();
    displaySalesmanLogo();
    string yourLocation = globalController.chooseLocation();
    modifySalesman(yourLocation);
}

void SalesmanController::modifySalesman(string yourLocation) {
    clearScreen();
    displayLogo();
    displaySalesmanLogo();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;

    displayStepsOfOrdering();
    string phoneNumber = "";
    endMessage();

    /// Step 1
    cout <<  "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "STEP 1: Input phone number (7 digits) " << "\e[0m " << endl;
    cin >> phoneNumber;

    while(phoneNumber.length() != 7) {
        cout << "Invalid phone number! Try again." << endl;
        cin >> phoneNumber;
    }

    cout << endl;
    endMessage();

    /// Step 2
    cout <<  "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "STEP 2: Order pizza/s from menu" << "\e[0m" << endl << endl;

    globalUI.displayAllPizzas();

    int pizzaFromMenuCount = getPizzaFromMenuCount();
    vector<Pizza> pizzasToOrder = orderPizzaFromMenu(pizzaFromMenuCount);
    cout << endl;

    clearScreen();
    displayLogo();
    displayAdminLogo();
    cout <<  "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "ORDER STATUS" << "\e[0m" << endl;
     if (pizzaFromMenuCount != 0) {
        cout << "Pizza: ";
        for(int i = 0; i < pizzasToOrder.size(); i++) {
            cout << pizzasToOrder.at(i).getName() << "  ";
            }
        cout << endl;
    }
    cout << "Total price: "  << getTotalPriceOfPizzasFromMenu(pizzasToOrder) << " kr." << endl;

    cout << endl;
    endMessage();

    /// Step 3
    cout << "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "STEP 3: " << "\e[0m";
    cout << "\e[1m" << "Order pizza/s made from scratch" << "\e[0m" << endl << endl;

    int pizzasFromScratchCount = getPizzaFromScratchCount();
    vector<Pizza> pizzasFromScratchOrder = orderPizzaFromScratch(pizzasFromScratchCount);

    clearScreen();
    displayLogo();
    displayAdminLogo();
    cout <<  "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "ORDER STATUS" << "\e[0m" << endl;
    if (pizzaFromMenuCount != 0) {
        cout << "Pizza: ";
        for(int i = 0; i < pizzasToOrder.size(); i++) {
            cout << pizzasToOrder.at(i).getName() << "  ";
            }
        cout << endl;
    }
    if (pizzasFromScratchCount != 0) {
        cout << pizzasFromScratchOrder.size() << " customized pizzas";
        cout << endl;
    }
    cout << "Total price: " << getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) + getTotalPriceOfPizzasFromMenu(pizzasToOrder) << " kr." << endl;

    cout << endl;
    endMessage();

    /// Step 4
    cout << "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "STEP 4: " << "\e[0m";
    cout << "\e[1m" << "Order side orders" << "\e[0m" << endl << endl;

    globalUI.displayAllBreadsticks();
    int breadsticksCount = getBreadsticksCount();
    cout << endl;
    vector<Breadsticks> breadsticksToOrder = orderBreadsticksFromMenu(breadsticksCount);

    clearScreen();
    displayLogo();
    displayAdminLogo();
    cout << "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "ORDER STATUS" << "\e[0m" << endl;
    if (pizzaFromMenuCount != 0) {
        cout << "Pizza: ";
        for(int i = 0; i < pizzasToOrder.size(); i++) {
            cout << pizzasToOrder.at(i).getName() << "  ";
        }
        cout << endl;
    }
    if (pizzasFromScratchCount != 0) {
        cout << pizzasFromScratchOrder.size() << " customized pizzas";
        cout << endl;
    }
    if (breadsticksCount != 0) {
        cout << "Side Orders: ";
        for(int i = 0; i < breadsticksToOrder.size(); i++) {
            cout << breadsticksToOrder.at(i).getName() << "  ";
        }
        cout << endl;
    }
    cout << "Total price: " << getTotalPriceOfBreadsticks(breadsticksToOrder) + getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) + getTotalPriceOfPizzasFromMenu(pizzasToOrder);

    cout << endl << endl;
    endMessage();

    cout << "Your location is " << yourLocation << endl << endl;
    cout << "\e[1m" << "STEP 5: " << "\e[0m";
    cout << "\e[1m" << "Order drinks" << "\e[0m" << endl << endl;

    globalUI.displayAllSodas();
    int sodaCount = getSodaCount();
    vector<Soda> sodasToOrder = orderSodaFromMenu(sodaCount);
    cout << endl;


    double totalPrice = getTotalPriceOfSodas(sodasToOrder) +
                        getTotalPriceOfBreadsticks(breadsticksToOrder) +
                        getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) +
                        getTotalPriceOfPizzasFromMenu(pizzasToOrder);

    cout << endl;

    Order newOrder(yourLocation, pizzasToOrder, pizzaFromMenuCount, pizzasFromScratchOrder, pizzasFromScratchCount, breadsticksToOrder, breadsticksCount,
                   sodasToOrder, sodaCount, totalPrice, 1, phoneNumber);
    orderData.addOrderToOrders(newOrder);


    cout << "h: Go home" << endl;
    cout << "q: Quit" << endl;
    cout << "Press anything else to confirm your order and see your receipt" << endl;

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

    ///LOKASKREFID

    cout << "\e[1m" << "ORDER SUMMARY" << "\e[0m" << endl << endl;

    cout << "\e[1m" << "Location: " << "\e[0m" << yourLocation << endl;
    cout << "\e[1m" << "Phone number: " << "\e[0m" << phoneNumber << endl;
    cout << "\e[1m" << "Total price: " << "\e[0m" << totalPrice << endl << endl;

    cout << "\e[1m" << "Pizzas from menu: " << "\e[0m";

    if (pizzaFromMenuCount >= 1) {
        for(int i = 0; i < pizzasToOrder.size(); i++) {
        cout << pizzasToOrder.at(i).getName() << "  ";
        }
        cout << endl;
    }

    else {
        cout << "There are no pizzas from menu on your order" << endl;
    }

    cout << endl << "\e[1m" << "Pizzas made from scratch: " << "\e[0m" << endl;

    for (unsigned int i = 0; i < pizzasFromScratchOrder.size(); i++) {
        cout << "Customized pizza number " << i + 1 << endl;
        for (unsigned int j = 0; j < pizzasFromScratchOrder.at(i).getToppings().size(); j++) {
            cout << pizzasFromScratchOrder.at(i).getToppings().at(j).getName() << endl;
        }
        cout << endl;
    }

    cout << "\e[1m" << "Side orders: " << "\e[0m" << endl;

    for(int i = 0; i < breadsticksToOrder.size(); i++) {
        cout << breadsticksToOrder.at(i).getName() << "  ";
    }
    cout << endl << endl;

    cout << "\e[1m" << "Drinks: " << "\e[0m" << endl;

    for(int i = 0; i < sodasToOrder.size(); i++) {
            cout << sodasToOrder.at(i).getName() << "  ";
    }
    cout << endl << endl;

    cout << "\e[1m" << "Thank you for your order, come back soon!" << "\e[0m" << endl << endl;

    displaySalesmanBackOrQuitUI();
    BackOrQuitSalesmanFunction();
}

int SalesmanController::getPizzaFromMenuCount() {
    cout << "How many pizzas from menu? " << endl;
    int pizzasFromMenuCount = 0;
    cin >> pizzasFromMenuCount;
    return pizzasFromMenuCount;
}

vector<Pizza> SalesmanController::orderPizzaFromMenu(int pizzasFromMenuCount) {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();

    vector<Pizza> pizzaToOrder;

    if (pizzasFromMenuCount != 0) {
        cout << "Enter pizzas: " << endl;
        int input = 0;

        for(int i = 0; i < pizzasFromMenuCount; i++) {
            cin >> input;
            input -= 1;
            while(input > pizzas.size() || input < 0) {
                cout << "Pizza not available!" << endl;
                cin >> input;
                input -= 1;
            }

            cout << pizzas.at(input).getName() << endl;
            pizzaToOrder.push_back(pizzas.at(input));
        }

        return pizzaToOrder;
    }
}

double SalesmanController::getTotalPriceOfPizzasFromMenu(vector<Pizza> pizzasFromMenu) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < pizzasFromMenu.size(); i++) {
        sumOfOrder += pizzasFromMenu[i].getPrice();
    }
    return sumOfOrder;
}

int SalesmanController::getPizzaFromScratchCount() {
    cout << "How many pizzas do you want to make? " << endl;
    int pizzasFromScratchCount = 0;
    cin >> pizzasFromScratchCount;
    return pizzasFromScratchCount;
}

vector<Pizza> SalesmanController::orderPizzaFromScratch(int pizzasFromScratchCount) {
    vector<Pizza> pizzaToOrderFromScratch;

    for(int i = 0; i < pizzasFromScratchCount; i++) {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
        cout << "Pizza number [" << i + 1 << "]" << endl;
        string myName =  "Customized";
        vector<Topping> myToppings;
        double myPrice = 1500;

        cout << endl;

        cout << "\e[1m CRUSTS \e[0m" << endl;
        cout << "------------------------------------------" << endl;
        vector<Crust> crusts = crustData.retrieveAllCrusts();
        for(unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "[" << i+1 << "]: " << crust.getName() << "\t" << crust.getPrice() << " kr." << endl;
        }
        cout << "------------------------------------------" << endl << endl;

        int inputCrust;
        cout << "Please select a crust" << endl;
        cin >> inputCrust;
        inputCrust -= 1;
        while(inputCrust > crusts.size() || inputCrust < 0) {
                cout << "Crust not available!" << endl;
                cin >> inputCrust;
                inputCrust -= 1;
        }
        Crust myCrust = crusts.at(inputCrust);

        cout << endl << "\e[1m TOPPINGS \e[0m" << endl;
        cout << "------------------------------------------" << endl;
        vector<Topping> toppings = toppingData.retrieveAllToppings();
        for(unsigned int i = 0; i < toppings.size(); i++) {
            Topping topping = toppings.at(i);
            cout << "[" << i+1 << "]: " << topping.getName() << "\t" << topping.getPrice() << " kr." << endl;
        }
        cout << "------------------------------------------" << endl << endl;

        int toppingCount = 0;
        int inputTopping = 0;

        cout << "How many toppings?" << endl;
        cin >> toppingCount;

        cout << "Enter toppings: " << endl;

        for(int i = 0; i < toppingCount; i++) {
            cin >> inputTopping;
            inputTopping -= 1;
            while(inputTopping > toppings.size() || inputTopping < 0) {
                cout << "Topping not available!" << endl;
                cin >> inputTopping;
                inputTopping -= 1;
            }
            Topping topping = toppings.at(inputTopping);
            cout << "\e[0m" << topping.getName() << " " << "\e[0m" << topping.getPrice() << " kr." << endl;
            cout << endl;
            myToppings.push_back(topping);
    }

        Pizza newPizza(myName, myPrice, toppingCount, myToppings, myCrust);
        pizzaToOrderFromScratch.push_back(newPizza);
        cout << "------------------------------------------" << endl;
    }

    return pizzaToOrderFromScratch;
}

double SalesmanController::getTotalPriceOfPizzasFromScratch(vector<Pizza> pizzasFromScratch) {
    double startingPizzaPrice = 1500;
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < pizzasFromScratch.size(); i++) {
        sumOfOrder += startingPizzaPrice;
        sumOfOrder += pizzasFromScratch[i].getCrust().getPrice();
        for(unsigned int j = 0; j < pizzasFromScratch[i].getToppings().size(); j++) {
            sumOfOrder += pizzasFromScratch[i].getToppings()[j].getPrice();
        }
    }
    return sumOfOrder;
}

int SalesmanController::getBreadsticksCount() {
    cout << "How many side orders?" << endl;
    int breadsticksCount = 0;
    cin >> breadsticksCount;

return breadsticksCount;
}

vector<Breadsticks> SalesmanController::orderBreadsticksFromMenu(int breadsticksCount) {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    vector<Breadsticks> breadsticksToOrder;

    if (breadsticksCount != 0) {
        cout << "Enter side orders: " << endl;
        int inputSideOrder = 0;
        for(int i = 0; i < breadsticksCount; i++) {
            cin >> inputSideOrder;
            inputSideOrder -= 1;
             while(inputSideOrder > breadsticks.size() || inputSideOrder < 0) {
                cout << "Side order not available!" << endl;
                cin >> inputSideOrder;
                inputSideOrder -= 1;
            }
            breadsticksToOrder.push_back(breadsticks.at(inputSideOrder));
        }
    }

    return breadsticksToOrder;
}

double SalesmanController::getTotalPriceOfBreadsticks(vector<Breadsticks> breadsticks) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < breadsticks.size(); i++) {
        sumOfOrder += breadsticks[i].getPrice();
    }
    return sumOfOrder;
}

int SalesmanController::getSodaCount() {
    cout << "How many sodas? " << endl;
    int sodaCount = 0;
    cin >> sodaCount;

    return sodaCount;
}

vector<Soda> SalesmanController::orderSodaFromMenu(int sodaCount) {
    vector<Soda> sodas = sodaData.retrieveAllSodas();

    vector<Soda> sodasToOrder;
    if (sodaCount != 0) {
        cout << "Enter soda: " << endl;
        int input = 0;
        for(int i = 0; i < sodaCount; i++) {
            cin >> input;
            input -= 1;
            sodasToOrder.push_back(sodas.at(input));
        }
    }
    return sodasToOrder;
}

double SalesmanController::getTotalPriceOfSodas(vector<Soda> sodas) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < sodas.size(); i++) {
        sumOfOrder += sodas[i].getPrice();
    }
    return sumOfOrder;
}



