#include "PizzaData.h"

PizzaData::PizzaData(){

}

void PizzaData::storePizzaToMenu(Pizza& pizza)
{
    ofstream fout;
    fout.open("menu.txt", ios::app);
    pizza.setVerbose(false);
    fout << pizza;
    fout.close();
    pizza.setVerbose(true);
}

/*Pizza PizzaData::retrievePizza(){

}

*/
