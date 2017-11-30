#include "Welcome.h"

Welcome::Welcome()
{
    //ctor
}

Welcome::~Welcome()
{
    //dtor

}
void Welcome::initialize(){

    view.displayWelcome();
}

/*void Welecome::user_selection(){
    char selection = '\0';

    while(selection != 'q'){

        // Enter cool art

        cout << "Type 1 if you are an admin" << endl;
        cout << "Type 2 if you are a salesman" << endl;
        cout << "Type 3 if you are a baker" << endl;
        cout << "Type 4 if you are a customer" << endl;
        cout << "Type h for help" << endl;
        cout << "Type a for about" << endl;
        cout << "Type q for quit" << endl;

        cin >> selection;

        if(selection == '1'){

        }
        else if(selection == '2'){

        }
        else if(selection == '3'){

        }
        else if(selection == '4'){

        }
        else if(selection == 'h'){

        }
        else if(selection == 'a'){

        }
    }
}*/
