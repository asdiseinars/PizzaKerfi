#include "AdminController.h"

AdminController::AdminController()
{
    //ctor
}

AdminController::~AdminController()
{
    //dtor
}

void AdminController::init(){
    displayLogo();
    displayAdminUI();

    char selection = '\0';
    cin >> selection;

    if (selection == '1') {
        clearScreen();
        displayLogo();
        displayAdminToppingUI();

        cin >> selection;
        if(selection == '1'){
            int toppingCount;

            cout << "How many new toppings do you want to add? ";
            cin >> toppingCount;

            Pizza pizza(toppingCount);
            for(int i = 0; i < toppingCount; i++){
                Topping topping;
                cin >> topping;
                pizza.addTopping(topping);
            }

            cout << pizza << endl;

            PizzaData data;
            data.storePizza(pizza);
        }
        else if (selection == '2') {
            PizzaData data;
            Pizza pizza = data.retrievePizza();
            cout << pizza << endl;
        }
        else if (selection == 'b') {
            clearScreen();
            AdminController admin;
            admin.init();
        }
    }

    else if (selection == '2') {
        clearScreen();
        displayLogo();
        displayAdminPizzaUI();

        cin >> selection;

        if (selection == '1') {
            cout << "How many pizzas do you want to add? " << endl;
        }

        else if (selection == '2') {
            cout << "Read all pizzas on menu: " << endl;
        }

        else if (selection == 'b') {
            clearScreen();
            AdminController admin;
            admin.init();

        }
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }

}
