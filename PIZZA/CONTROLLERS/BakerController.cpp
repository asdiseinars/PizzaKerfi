#include "BakerController.h"

BakerController::BakerController() {
    //ctor
}

void BakerController::init() {
    displayLogo();
    displayBakerLogo();

    string yourLocation = globalController.chooseLocation();

    clearScreen();
    displayLogo();
    displayBakerLogo();
    cout << "\033[4m" << "Your location is " << yourLocation << "\033[0m" << endl << endl;
    displayBakerOrderUI();
    modifyBakerOrders();
}


void BakerController::modifyBakerOrders() {

}





