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
    ifstream myFile("toppings.txt");
    if(myFile.fail()) {
        cout << "There are no toppings on the menu! " << endl;
        cout << "Please exit and add toppings to the menu first." << endl;
    }


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

void ToppingData::addTopping(Topping& topping) {
    ofstream fout;
    fout.open("toppings.txt", ios::app);

    fout << topping;
    fout.close();
}


