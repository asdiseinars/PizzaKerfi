#include "AdminController.h"

AdminController::AdminController() {

}

void AdminController::init(){
    displayLogo();
    displayAdminLogo();
    displayAdminUI();

    char selection = '\0';
    cin >> selection;

    if (selection == '1') { //add/edit toppings
        clearScreen();
        displayLogo();
        displayAdminLogo();
        displayAdminToppingUI();

        cin >> selection;

        if(selection == '1'){ // add new toppings
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

            pizzaData.storePizza(pizza);

        }

        else if (selection == '2') { // edit toppings
           /* Topping topping;
            cin >> topping;
            toppingData.storeAllToppings(topping);*/

        }

        else if (selection == '3') { // all toppings
            cout << "Here are all the toppings you have on list" << endl;
             /*PizzaData data;
            Pizza pizza = data.retrievePizza();
            cout << pizza << endl;*/
        }

        else if (selection == 'b') {
            clearScreen();
            AdminController admin;
            admin.init();
        }
    }

    else if (selection == '2') { //add/edit pizzas
        clearScreen();
        displayLogo();
        displayAdminLogo();
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
