#include "GlobalHelp.h"

void GlobalHelp::clearScreen() {

    system("cls");
}

void GlobalHelp::displayLogo() {
    cout << "\e[1m" << "  _____ _                _  ___ _       _                 " << "\e[0m" << endl;
    cout << "\e[1m" << " |  __ (_)              | |/ (_) |     | |                " << "\e[0m" << endl;
    cout << "\e[1m" << " | |__) | __________ _  | ' / _| |_ ___| |__   ___ _ __   " << "\e[0m" << endl;
    cout << "\e[1m" << " |  ___/ |_  /_  / _` | |  < | | __| __| '_   / _  '_   | " << "\e[0m" << endl;
    cout << "\e[1m" << " | |   | |/ / / / (_| | | .  | | || (__| | | |  __/ | | | " << "\e[0m" << endl;
    cout << "\e[1m" << " |_|   |_/___/___|__,_| |_||_|_|___|___|_| |_||___|_| |_| " << "\e[0m" << endl;
    cout << endl << endl;
}

void GlobalHelp::displayAdminLogo() {
    cout << "\e[1m" << "----- ADMIN ------" << "\e[0m" << endl;
    cout << endl;
}

void GlobalHelp::displayBakerLogo() {
    cout << "\e[1m" << "----- BAKER ------" << "\e[0m"<< endl;
    cout << endl;

}

void GlobalHelp::displaySalesmanLogo() {
    cout << "\e[1m" << "----- SALESMAN ------" << "\e[0m"<< endl;
    cout << endl;

}

void GlobalHelp::displayDeliveryLogo() {
    cout << "\e[1m" << "----- DELIVERY ------" << "\e[0m" << endl;
    cout << endl;

}

void GlobalHelp::displayHomeLogo() {
    cout << "\e[1m" << "----- MAIN MENU ------" << "\e[0m" << endl;
    cout << endl;

}
