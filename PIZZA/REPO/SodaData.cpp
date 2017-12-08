#include "SodaData.h"

SodaData::SodaData() {

}

void SodaData::clearSodas() {
    ofstream fout;
    fout.open("sodas.txt");
    fout.close();
}

void SodaData::storeAllSodas(vector<Soda> sodas) {

    clearSodas();

    ofstream fout;
    fout.open("sodas.txt");

    for(unsigned int i = 0; i < sodas.size(); i++) {
        sodas[i].setVerbose(false);
        fout << sodas[i];
    }
    fout.close();
}

vector<Soda> SodaData::retrieveAllSodas() {

    vector <Soda> sodas;
    Soda soda;

    ifstream fin;
    fin.open("sodas.txt");
    while(!fin.eof()) {
        soda.setVerbose(false);
        fin >> soda;
        soda.setVerbose(true);
        sodas.push_back(soda);
    }
    sodas.pop_back();

    return sodas;
}

void SodaData::addSoda(Soda& soda) {
    ofstream fout;
    fout.open("sodas.txt", ios::app);

    soda.setVerbose(false);
    fout << soda;
    fout.close();
    soda.setVerbose(true);
}


