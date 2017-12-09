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
    cout << "Your location is " << yourLocation << endl;
    displayBakerOrderUI();
    modifyBakerOrders();
}


void BakerController::modifyBakerOrders() {

}





