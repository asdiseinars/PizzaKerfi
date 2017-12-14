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

    ifstream myFile("breadsticks.txt");
    if(myFile.fail()) {
        cout << "There are no side orders on the menu! " << endl;
        cout << "Please exit and add side orders to the menu first." << endl;
    }

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


