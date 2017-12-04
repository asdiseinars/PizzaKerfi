#include "ToppingData.h"
#include <fstream>
#include <iostream>

using namespace std;



void ToppingData::storeAllToppings(const vector<Topping> &toppings) {

    ofstream fout;
    fout.open("toppings.bin", ios::binary);
    int toppingCount = toppings.size();
    fout.write((char*)(&toppingCount), sizeof(int));

    for (int i = 0; i < toppingCount; i++) {
        toppings[i].write(fout);
    }
    fout.close();
}

vector<Topping> ToppingData::retrieveAllToppings() {

    vector <Topping> toppings;
    Topping topping;

    ifstream fin;
    fin.open("toppings.bin", ios::binary);

    if(fin.is_open()) {
        int toppingCount;

        fin.read((char*)(&toppingCount), sizeof(int));

        for (int i = 0; i < toppingCount; i++) {
            topping.read(fin);
            toppings.push_back(topping);
        }
        fin.close();
    }
    return toppings;
}







