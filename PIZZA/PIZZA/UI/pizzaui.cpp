#include "PizzaUI.h"
#include "Pizza.h"
#include "Topping.h"
#include <iostream>

using namespace std;

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}

void PizzaUI::displayPizzaUI(){

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



