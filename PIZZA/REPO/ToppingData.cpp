#include "ToppingData.h"


ToppingData::ToppingData() {

}

void ToppingData::clearToppings() {
    ofstream fout;
    fout.open("toppings.txt");
    fout.close();
}

void ToppingData::storeAllToppings(vector<Topping> toppings) {

    //clearToppings();

    ofstream fout;
    fout.open("toppings.txt");

    for(unsigned int i = 0; i < toppings.size(); i++){
        toppings[i].setVerbose(false);
        fout << toppings[i];
    }
    fout.close();
}

vector<Topping> ToppingData::retrieveAllToppings() {

    vector <Topping> toppings;
    Topping top;

    ifstream fin;
    fin.open("toppings.txt");
    while(!fin.eof()) {
        top.setVerbose(false);
        fin >> top;
        top.setVerbose(true);
        toppings.push_back(top);
    }
    toppings.pop_back();

    return toppings;
}

void ToppingData::addTopping(Topping& topping){
    ofstream fout;
    fout.open("toppings.txt", ios::app);

    topping.setVerbose(false);
    fout << topping;
    fout.close();
    topping.setVerbose(true);
}


