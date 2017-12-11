#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
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
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    ///step 1

    cout << "PIZZA MENU" << endl;
    cout << "------------------------------------------" << endl;
    globalController.displayAllPizzas();
    cout << "------------------------------------------" << endl;

    int pizzaFromMenuCount = getPizzaFromMenuCount();
    vector<Pizza> pizzasToOrder = orderPizzaFromMenu(pizzaFromMenuCount);
    clearScreen();

    displayLogo();
    displaySalesmanLogo();
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    ///step 2
    int pizzasFromScratchCount = getPizzaFromScratchCount();
    vector<Pizza> pizzasFromScratchOrder = orderPizzaFromScratch(pizzasFromScratchCount);
    clearScreen();

    displayLogo();
    displaySalesmanLogo();
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    /// step 3
    int breadsticksCount = getBreadsticksCount();
    vector<Breadsticks> breadsticksToOrder = orderBreadsticksFromMenu(breadsticksCount);
    clearScreen();

    displayLogo();
    displaySalesmanLogo();
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    ///step 4
    int sodaCount = getSodaCount();
    vector<Soda> sodasToOrder = orderSodaFromMenu(sodaCount);
    clearScreen();

    displayLogo();
    ///complete order
    display

    Order newOrder(yourLocation, pizzasToOrder, pizzaFromMenuCount, pizzasFromScratchOrder, pizzasFromScratchCount, breadsticksToOrder, breadsticksCount, sodasToOrder, sodaCount);
    orderData.addOrderToOrders(newOrder);

}

int SalesmanController::getPizzaFromMenuCount() {
    cout << "How many pizzas do you want to order from menu? " << endl;
    int pizzasFromMenuCount = 0;
    cin >> pizzasFromMenuCount;
    return pizzasFromMenuCount;
}

vector<Pizza> SalesmanController::orderPizzaFromMenu(int pizzasFromMenuCount) {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();

    vector<Pizza> pizzaToOrder;

    cout << "What pizzas do you want to add to your order? " << endl;
    int input = 0;
    for(int i = 0; i < pizzasFromMenuCount; i++) {
        cin >> input;
        input -= 1;
        pizzaToOrder.push_back(pizzas.at(input));
    }

    return pizzaToOrder;
}

int SalesmanController::getPizzaFromScratchCount() {
    cout << "How many pizzas do you want to make from scratch? " << endl;
    int pizzasFromScratchCount = 0;
    cin >> pizzasFromScratchCount;
    return pizzasFromScratchCount;
}

vector<Pizza> SalesmanController::orderPizzaFromScratch(int pizzasFromScratchCount) {
    vector<Pizza> pizzaToOrderFromScratch;

    for(int i = 0; i < pizzasFromScratchCount; i++) {
        string myName = "Customized";
        vector<Topping> myToppings;
        double myPrice = 3400;

        cout << endl;

        cout << "CRUSTS" << endl;
        cout << "------------------------------------------" << endl;
        vector<Crust> crusts = crustData.retrieveAllCrusts();
        for(unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "[" << i+1 << "] \t" << crust.getName() << endl;
        }
        cout << "------------------------------------------" << endl;

        char inputCrust;
        cout << "Please select a crust." << endl;
        cin >> inputCrust;
        int inputIntCrust = inputCrust - 48;
        Crust myCrust = crusts.at(inputIntCrust - 1);

        cout << "TOPPINGS" << endl;
        cout << "------------------------------------------" << endl;
        vector<Topping> toppings = toppingData.retrieveAllToppings();
        for(unsigned int i = 0; i < toppings.size(); i++) {
            Topping topp = toppings.at(i);
            cout << "[" << i+1 << "] \t" << topp.getName() << endl;
        }
        cout << "------------------------------------------" << endl;

        char selection;
        int toppingCount = 0;

        do {
            char inputTopping;
            cout << "Please enter the number of the topping you want to add to your pizza. " << endl;
            cin >> inputTopping;
            int inputIntTopping = inputTopping - 48;
            Topping topping = toppings.at(inputIntTopping - 1);
            cout << "Name: " << topping.getName() << "\t" <<"Price: " << topping.getPrice() << endl;
            myToppings.push_back(topping);

            toppingCount++;
            cout << toppingCount;

            cout << endl << "Do you want to add another topping? (y/n)" << endl;

            cin >> selection;

            while(selection != 'y' && selection != 'n') {
                cout << endl << "Invalid input! " << endl << endl;
                cout << "Do you want to add another topping? (y/n)" << endl;
                cin >> selection;
                cout << endl;
            }
        } while(selection == 'y');


        Pizza newPizza(myName, myPrice, toppingCount, myToppings, myCrust);
        pizzaToOrderFromScratch.push_back(newPizza);
    }

    return pizzaToOrderFromScratch;
}

int SalesmanController::getBreadsticksCount() {
    cout << "How many side orders do you want to order? " << endl;
    int breadsticksCount = 0;
    cin >> breadsticksCount;
    return breadsticksCount;
}

vector<Breadsticks> SalesmanController::orderBreadsticksFromMenu(int breadsticksCount) {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    globalController.displayAllBreadsticks();

    vector<Breadsticks> breadsticksToOrder;

    cout << "What side order do you want to add to your order? " << endl;
    int input = 0;
    for(int i = 0; i < breadsticksCount; i++) {
        cin >> input;
        input -= 1;
        breadsticksToOrder.push_back(breadsticks.at(input));
    }

    return breadsticksToOrder;
}

int SalesmanController::getSodaCount() {
    cout << "How many sodas do you want to order? " << endl;
    int sodaCount = 0;
    cin >> sodaCount;

    return sodaCount;
}

vector<Soda> SalesmanController::orderSodaFromMenu(int sodaCount) {
    vector<Soda> sodas = sodaData.retrieveAllSodas();
    globalController.displayAllSodas();

    vector<Soda> sodasToOrder;

    cout << "What soda do you want to add to your order? " << endl;
    int input = 0;
    for(int i = 0; i < sodaCount; i++) {
        cin >> input;
        input -= 1;
        sodasToOrder.push_back(sodas.at(input));
    }

    return sodasToOrder;
}
