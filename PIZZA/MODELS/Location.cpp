#include "Location.h"

Location::Location(){
    name = "";
}

Location::Location(string name){
    this->name = name;
}

string Location::getName(){
    return name;
}


void Location::setName(string name){
    this->name = name;
}


ifstream& operator >> (ifstream& fin, Location& location){
    fin >> location.name;

    return fin;
}

ofstream& operator << (ofstream& fout, const Location& location){
    fout << location.name << endl;

    return fout;
}

