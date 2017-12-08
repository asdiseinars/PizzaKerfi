#include "Location.h"

Location::Location(){
    name = '\0';
    verbose = true;
}

string Location::getLocation(){
    return name;
}

void Location::setName(string name){
    this->name = name;
}

void Location::setVerbose(bool verbose) {
    this->verbose = verbose;
}

ifstream& operator >> (ifstream& in, Location& location){
    in >> location.name;

    return in;
}

ofstream& operator << (ofstream& out, const Location& location){
    out << location.name << endl;

    return out;
}

ostream& operator << (ostream& out, const Location& location){
    cout << "Name: ";
    out << location.name << endl;

    return out;
}

istream& operator >> (istream& in, Location& location){
    cout << "Name: ";
    in >> location.name;

    return in;
}
