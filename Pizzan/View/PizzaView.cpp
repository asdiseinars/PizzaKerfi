#include "PizzaView.h"
#include "Pizza.h"
#include "Topping.h"
#include <iostream>

using namespace std;

PizzaView::PizzaView()
{
    //ctor
}

PizzaView::~PizzaView()
{
    //dtor
}

void PizzaView::displayPizzaView(){

    char selection = '\0';

    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;

    cin >> selection;

    if(selection == 'm'){
        int tCount;

        cout << "How many toppings: ";
        cin >> tCount;

        Pizza pizza(tCount);
        for(int i = 0; i < tCount; i++){
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
