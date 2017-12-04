#include "PizzaData.h"

class FileNotFoundException{};;

PizzaData::PizzaData(){

}

void PizzaData::storePizza(Pizza& pizza){
    ofstream fout;

    fout.open("Pizza.bin", ios::binary);

    //pizza.verbose = false;
    pizza.write(fout);

    fout.close();
}

Pizza PizzaData::retrievePizza(){
    ifstream fin;

    fin.open("Pizza.bin", ios::binary);


    if(fin.is_open()) {
        Pizza pizza;
        //fin >> pizza;
        pizza.read(fin);

        fin.close();
        return pizza;
    }
    throw FileNotFoundException(); ///skil ekki?
}

