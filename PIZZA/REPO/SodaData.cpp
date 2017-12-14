#include "SodaData.h"

SodaData::SodaData() {

}

void SodaData::storeAllSodas(vector<Soda> sodas) {

    ofstream fout;
    fout.open("sodas.txt");

    for(unsigned int i = 0; i < sodas.size(); i++) {
        fout << sodas[i];
    }
    fout.close();
}

vector<Soda> SodaData::retrieveAllSodas() {

    ifstream myFile("sodas.txt");
    if(myFile.fail()) {
        cout << "There are no drinks on the menu! " << endl;
        cout << "Please exit and add drinks to the menu first." << endl;
    }

    vector <Soda> sodas;
    Soda soda;

    ifstream fin;
    fin.open("sodas.txt");
    while(!fin.eof()) {
        fin >> soda;
        sodas.push_back(soda);
    }
    sodas.pop_back();

    return sodas;
}

void SodaData::addSoda(Soda& soda) {
    ofstream fout;
    fout.open("sodas.txt", ios::app);

    fout << soda;
    fout.close();
}


