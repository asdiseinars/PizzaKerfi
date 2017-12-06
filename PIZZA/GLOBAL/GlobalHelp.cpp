#include "GlobalHelp.h"

void GlobalHelp::clearScreen() {

    system("cls");
}

void GlobalHelp::displayLogo() {
    cout << "  _____ _                _  ___ _       _                 " << endl;
    cout << " |  __ (_)              | |/ (_) |     | |                " << endl;
    cout << " | |__) | __________ _  | ' / _| |_ ___| |__   ___ _ __   " << endl;
    cout << " |  ___/ |_  /_  / _` | |  < | | __| __| '_   / _  '_   | " << endl;
    cout << " | |   | |/ / / / (_| | | .  | | || (__| | | |  __/ | | | " << endl;
    cout << " |_|   |_/___/___|__,_| |_||_|_|___|___|_| |_||___|_| |_| " << endl;
    cout << endl << endl;
    cout << "test kara" << endl;
}

void GlobalHelp::displayAdminLogo() {
    cout << "----- ADMIN ------" << endl;
    cout << endl;
}

void GlobalHelp::displayBakerLogo() {
    cout << "----- BAKER ------" << endl;
    cout << endl;

}

void GlobalHelp::displaySalesmanLogo() {
    cout << "----- SALESMAN ------" << endl;
    cout << endl;

}

void GlobalHelp::displayCustomerLogo() {
    cout << "----- CUSTOMER ------" << endl;
    cout << endl;

}

void GlobalHelp::displayHomeLogo() {
    cout << "----- MAIN MENU ------" << endl;
    cout << endl;

}
