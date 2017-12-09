#include "CrustData.h"

CrustData::CrustData()
{
    //ctor
}


void CrustData::storeAllCrusts(vector<Crust> crust) {

    ofstream fout;
    fout.open("crusts.txt");

    for(unsigned int i = 0; i < crust.size(); i++) {
        fout << crust[i];
    }
    fout.close();
}

vector<Crust> CrustData::retrieveAllCrusts() {

    vector <Crust> crust;
    Crust crustie;

    ifstream fin;
    fin.open("crusts.txt");
    while(!fin.eof()) {
        fin >> crustie;
        crust.push_back(crustie);
    }
    crust.pop_back();

    return crust;
}

void CrustData::addCrust(Crust& crust) {
    ofstream fout;
    fout.open("crusts.txt", ios::app);

    fout << crust;
    fout.close();
}


