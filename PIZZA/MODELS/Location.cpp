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

istream& operator >> (istream& in, Location& location){
    if(location.verbose){
            cout << "Location name: ";
    }
    in >> location.name;

    return in;
}

ostream& operator << (ostream& out, const Location& location){

    out << location.name << endl;

    return out;
}
