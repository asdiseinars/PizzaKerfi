#include "WelcomeView.h"

WelcomeView::WelcomeView(){ }

void WelcomeView::displayWelcome(){

    char selection = '\0';
    while(selection != 'q'){
        cout << "Type 1 if you are an admin" << endl;
        cout << "Type 2 if you are a salesman" << endl;
        cout << "Type 3 if you are a baker" << endl;
        cout << "Type 4 if you are a customer" << endl;
        cout << "Type h for help" << endl;
        cout << "Type a for about" << endl;
        cout << "Type q for quit" << endl;

        cin >> selection;

        if(selection == '1'){
            PizzaView pizzaview;
            pizzaview.displayPizzaView();
            cout << endl;
        }
   }


}
