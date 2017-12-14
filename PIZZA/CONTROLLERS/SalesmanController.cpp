#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
}

void SalesmanController::endMessage() {
    cout << "Press any button if you would like to continue" << endl;
    cout << "Press q to quit" << endl;

    char input = '\0';
    cin >> input;

    if (input == 'q') {
        return;
    }
    else {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
    }
}

void SalesmanController::init() {
    displayLogo();
    displaySalesmanLogo();
    string yourLocation = globalController.chooseLocation();
    modifySalesman(yourLocation);
}

void SalesmanController::modifySalesman(string yourLocation) {
    cout << " is your current location" << endl << endl;
    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    displayStepsOfOrdering();
    string phoneNumber = "";
    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 1: Input phone number (7 digits)" << "\e[0m";

    cin >> phoneNumber;
    while(phoneNumber.length() != 7) {
        cin >> phoneNumber;
        cout << "Invalid phone number!";
    }
    cout << endl;
    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 2: " << "\e[0m" << endl;
    cout << "\e[1m" << "Order pizza/s from menu" << "\e[0m" << endl << endl;

    globalUI.displayAllPizzas();

    int pizzaFromMenuCount = getPizzaFromMenuCount();
    vector<Pizza> pizzasToOrder = orderPizzaFromMenu(pizzaFromMenuCount);
    cout << endl;

    cout << "You have selected the following pizzas: " << endl;
    for(int i = 0; i < pizzasToOrder.size(); i++) {
        cout << "Name: " << pizzasToOrder.at(i).getName() << endl;
        cout << "Price: " << pizzasToOrder.at(i).getPrice() << endl;
        cout << "Toppings: " << endl;
        for(int j = 0; j < pizzasToOrder.at(i).getToppings().size(); j++) {
            cout << pizzasToOrder.at(i).getToppings().at(j).getName() << endl;
        }
    }

    cout << "\e[1m" << "Current price for pizzas from menu: " << "\e[0m" << getTotalPriceOfPizzasFromMenu(pizzasToOrder) << endl; ///laga þennnan texta
    cout << "\e[1m" << "Total price: " << "\e[0m" << getTotalPriceOfPizzasFromMenu(pizzasToOrder)<< endl;

    cout << endl;
    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 3: " << "\e[0m";
    cout << "\e[1m" << "Order pizza/s made from scratch" << "\e[0m" << endl << endl;

    int pizzasFromScratchCount = getPizzaFromScratchCount();
    vector<Pizza> pizzasFromScratchOrder = orderPizzaFromScratch(pizzasFromScratchCount);

    cout << endl;
    cout << "\e[1m" << "Current price for pizzas from scratch: " << "\e[0m" << getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) << endl;
    cout << "\e[1m" << "Total price: " << "\e[0m" <<    getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) +
                                                        getTotalPriceOfPizzasFromMenu(pizzasToOrder);

    cout << endl << endl;
    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 4: " << "\e[0m";
    cout << "\e[1m" << "Order side orders" << "\e[0m" << endl << endl;


    globalUI.displayAllBreadsticks();
    int breadsticksCount = getBreadsticksCount();
    cout << endl;
    vector<Breadsticks> breadsticksToOrder = orderBreadsticksFromMenu(breadsticksCount);

    cout << "\e[1m" << "Current price for side orders: " << "\e[0m" << getTotalPriceOfBreadsticks(breadsticksToOrder) << endl;
    cout << endl << "\e[1m" << "Total price: " << "\e[0m" <<    getTotalPriceOfBreadsticks(breadsticksToOrder) +
                                                                getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) +
                                                                getTotalPriceOfPizzasFromMenu(pizzasToOrder);
    cout << endl << endl;
    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 5: " << "\e[0m";
    cout << "\e[1m" << "Order drinks" << "\e[0m" << endl << endl;

    globalUI.displayAllSodas();
    int sodaCount = getSodaCount();
    vector<Soda> sodasToOrder = orderSodaFromMenu(sodaCount);
    cout << endl;

    cout << "\e[1m" << "Current price for drinks: " << "\e[0m" << getTotalPriceOfSodas(sodasToOrder);
    cout << endl;
    cout << "\e[1m" << "Current price: " << "\e[0m" <<  getTotalPriceOfSodas(sodasToOrder) +
                                                        getTotalPriceOfBreadsticks(breadsticksToOrder) +
                                                        getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) +
                                                        getTotalPriceOfPizzasFromMenu(pizzasToOrder);
    cout << endl << endl;
    endMessage();



    ///eitthvað lost eftir þetta

    double totalPrice = getTotalPriceOfSodas(sodasToOrder) +
                        getTotalPriceOfBreadsticks(breadsticksToOrder) +
                        getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) +
                        getTotalPriceOfPizzasFromMenu(pizzasToOrder);

    cout << "\e[1m" << "Total price: " << "\e[0m" << totalPrice << endl;

    int orderStatus = 1;

    clearScreen();

    displayLogo();
    ///complete order
    //display

    Order newOrder(yourLocation, pizzasToOrder, pizzaFromMenuCount, pizzasFromScratchOrder, pizzasFromScratchCount,
                    breadsticksToOrder, breadsticksCount, sodasToOrder, sodaCount, totalPrice, orderStatus, phoneNumber);
    orderData.addOrderToOrders(newOrder);

}

int SalesmanController::getPizzaFromMenuCount() {
    cout << "\e[1m" << "How many pizzas do you want to order from menu? " << "\e[0m" << endl;
    int pizzasFromMenuCount = 0;
    cin >> pizzasFromMenuCount;
    return pizzasFromMenuCount;
}

vector<Pizza> SalesmanController::orderPizzaFromMenu(int pizzasFromMenuCount) {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();

    vector<Pizza> pizzaToOrder;
    cout << "\e[1m" << "What pizzas do you want to add to your order? " << "\e[0m" << endl;
    int input = 0;
    for(int i = 0; i < pizzasFromMenuCount; i++) {
        cin >> input;
        input -= 1;
        pizzaToOrder.push_back(pizzas.at(input));
    }
    return pizzaToOrder;
}

double SalesmanController::getTotalPriceOfPizzasFromMenu(vector<Pizza> pizzasFromMenu) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < pizzasFromMenu.size(); i++) {
        sumOfOrder += pizzasFromMenu[i].getPrice();
    }
    return sumOfOrder;
}

int SalesmanController::getPizzaFromScratchCount() {
    cout << "\e[1m" << "How many pizzas do you want to make from scratch? " << "\e[0m" << endl;
    int pizzasFromScratchCount = 0;
    cin >> pizzasFromScratchCount;
    return pizzasFromScratchCount;
}

vector<Pizza> SalesmanController::orderPizzaFromScratch(int pizzasFromScratchCount) {
    vector<Pizza> pizzaToOrderFromScratch;

    for(int i = 0; i < pizzasFromScratchCount; i++) {
        string myName =  "Customized";
        vector<Topping> myToppings;
        double myPrice = 3400;

        cout << endl;

        cout << "\e[1m CRUSTS \e[0m" << endl;
        cout << "------------------------------------------" << endl;
        vector<Crust> crusts = crustData.retrieveAllCrusts();
        for(unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "[" << i+1 << "]: " << crust.getName() << "\t" << crust.getPrice() << " kr." << endl;
        }
        cout << "------------------------------------------" << endl;

        char inputCrust;
        cout << "\e[1m" << "Please select a crust" << "\e[0m" << endl;
        cin >> inputCrust;
        int inputIntCrust = inputCrust - 48;
        Crust myCrust = crusts.at(inputIntCrust - 1);

        cout << "\e[1m TOPPINGS \e[0m" << endl;
        cout << "------------------------------------------" << endl;
        vector<Topping> toppings = toppingData.retrieveAllToppings();
        for(unsigned int i = 0; i < toppings.size(); i++) {
            Topping topping = toppings.at(i);
            cout << "[" << i+1 << "]: " << topping.getName() << "\t" << topping.getPrice() << " kr." << endl;
        }
        cout << "------------------------------------------" << endl;

        int toppingCount = 0;
        int inputTopping = 0;

        cout << endl << "\e[1m" << "How many toppings do you want to add to your pizza?" << "\e[0m" << endl;
        cin >> toppingCount;

        cout << "\e[1m" << "Please enter the number of toppings you want to add to your pizza" << "\e[0m" << endl;

        for(int i = 0; i < toppingCount; i++) {
        cin >> inputTopping;
        Topping topping = toppings.at(inputTopping - 1);
        cout << "\e[1m" << "Name: " << "\e[0m" << topping.getName() << endl;
        cout << "\e[1m" << "Price: " << "\e[0m" << topping.getPrice() << endl;
        cout << endl;
        myToppings.push_back(topping);
    }

        Pizza newPizza(myName, myPrice, toppingCount, myToppings, myCrust);
        pizzaToOrderFromScratch.push_back(newPizza);
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
    cout << "\e[1m" << "How many side orders do you want to order? " << "\e[0m" << endl;
    int breadsticksCount = 0;
    cin >> breadsticksCount;

return breadsticksCount;
}

vector<Breadsticks> SalesmanController::orderBreadsticksFromMenu(int breadsticksCount) {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    vector<Breadsticks> breadsticksToOrder;
    cout << "\e[1m" << "What side order do you want to add to your order?" << "\e[0m" << endl;
    int input = 0;
    for(int i = 0; i < breadsticksCount; i++) {
        cin >> input;
        input -= 1;
        breadsticksToOrder.push_back(breadsticks.at(input));
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
    cout << "\e[1m" << "How many sodas do you want to order? " << "\e[0m" << endl;
    int sodaCount = 0;
    cin >> sodaCount;

    return sodaCount;
}

vector<Soda> SalesmanController::orderSodaFromMenu(int sodaCount) {
    vector<Soda> sodas = sodaData.retrieveAllSodas();

    vector<Soda> sodasToOrder;
    cout << "\e[1m" << "What soda do you want to add to your order? " << "\e[0m" << endl;
    int input = 0;
    for(int i = 0; i < sodaCount; i++) {
        cin >> input;
        input -= 1;
        sodasToOrder.push_back(sodas.at(input));
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
