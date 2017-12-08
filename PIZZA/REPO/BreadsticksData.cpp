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
        fout << breadsticks[i];
    }
    fout.close();
}

vector<Breadsticks> BreadsticksData::retrieveAllBreadsticks() {

    vector <Breadsticks> breadsticks;
    Breadsticks bread;

    ifstream fin;
    fin.open("breadsticks.txt");
    while(!fin.eof()) {
        fin >> bread;
        breadsticks.push_back(bread);
    }
    breadsticks.pop_back();

    return breadsticks;
}

void BreadsticksData::addBreadsticks(Breadsticks& breadsticks) {
    ofstream fout;
    fout.open("breadsticks.txt", ios::app);
    fout << breadsticks;
    fout.close();
}


