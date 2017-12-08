#include "BreadsticksData.h"

BreadsticksData::BreadsticksData() {

}

void BreadsticksData::clearBreadsticks() {
    ofstream fout;
    fout.open("breadsticks.txt");
    fout.close();
}

void BreadsticksData::storeAllBreadsticks(vector<Breadsticks> breadsticks) {
    clearBreadsticks();

    ofstream fout;
    fout.open("breadsticks.txt");

    for(unsigned int i = 0; i < breadsticks.size(); i++) {
        breadsticks[i].setVerbose(false);
        fout << breadsticks[i];
    }
    fout.close();
}

vector<Breadsticks> BreadsticksData::retrieveAllBredsticks() {

    vector <Breadsticks> breadsticks;
    Breadsticks bread;

    ifstream fin;
    fin.open("breadsticks.txt");
    while(!fin.eof()) {
        bread.setVerbose(false);
        fin >> bread;
        bread.setVerbose(true);
        breadsticks.push_back(bread);
    }
    breadsticks.pop_back();

    return breadsticks;
}

void BreadsticksData::addBreadsticks(Breadsticks& breadsticks) {
    ofstream fout;
    fout.open("breadsticks.txt", ios::app);

    breadsticks.setVerbose(false);
    fout << breadsticks;
    fout.close();
    breadsticks.setVerbose(true);
}


