#include "PizzaUI.h"

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}

void PizzaUI::displayPizzaUI(){

    clearScreen();
    displayLogo();
    char selection = '\0';

    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;

    cin >> selection;

    if(selection == 'm'){
        int toppingCount;

        cout << "How many toppings: ";
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

    else if (selection == 'r') {
        PizzaData data;

        Pizza pizza = data.retrievePizza();

        cout << pizza << endl;

    }
}



