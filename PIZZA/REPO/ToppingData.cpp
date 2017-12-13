#include "ToppingData.h"


ToppingData::ToppingData() {

}

void ToppingData::storeAllToppings(vector<Topping> toppings) {

    ofstream fout;
    fout.open("toppings.txt");

    for(unsigned int i = 0; i < toppings.size(); i++) {
        fout << toppings[i];
    }
    fout.close();
}

vector<Topping> ToppingData::retrieveAllToppings() {
    vector <Topping> toppings;

    ifstream fin;
    fin.open("toppings.txt");
    while(!fin.eof()) {
        Topping topping;
        fin >> topping;
        toppings.push_back(topping);
    }
    toppings.pop_back();

    return toppings;
}

/*void ToppingData::changeTopping(Topping topping) {
    vector<Topping> toppings = retrieveAllToppings();
    vector<Topping> newToppings;
    ofstream fout;
    fout.open ("toppings.txt");

    for (unsigned int i = 0; i < toppings.size(); i++) {
        if (toppings[i] == topping) {
            cin >> newtopping[i].getName();
            cin >> newtopping[i].getPrice();
        }
    }

} */


void ToppingData::addTopping(Topping& topping) {
    ofstream fout;
    fout.open("toppings.txt", ios::app);

    fout << topping;
    fout.close();
}


