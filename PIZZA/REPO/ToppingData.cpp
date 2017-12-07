#include "ToppingData.h"


ToppingData::ToppingData() {

}

void ToppingData::storeAllToppings(vector<Topping> toppings) {

    ofstream fout;
    fout.open("toppings.txt");

    for(unsigned int i = 0; i < toppings.size(); i++) {
        toppings[i].setVerbose(false);
        fout << toppings[i];
    }
    fout.close();
}

vector<Topping> ToppingData::retrieveAllToppings() {
    vector <Topping> toppings;
    Topping topping;

    ifstream fin;
    fin.open("toppings.txt");
    while(!fin.eof()) {
        topping.setVerbose(false);
        fin >> topping;
        topping.setVerbose(true);
        toppings.push_back(topping);
    }
    toppings.pop_back();

    return toppings;
}

void ToppingData::addTopping(Topping& topping) {
    ofstream fout;
    fout.open("toppings.txt", ios::app);

    topping.setVerbose(false);
    fout << topping;
    fout.close();
    topping.setVerbose(true);
}


