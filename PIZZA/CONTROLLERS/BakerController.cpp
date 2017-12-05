#include "BakerController.h"

BakerController::BakerController()
{
    //ctor
}

BakerController::~BakerController()
{
    //dtor
}

void BakerController::init(){
    displayLogo();
    displayBakerLogo();
    displayBakerUI();

    char selection = '\0';
    cin >> selection;

    if(selection == '1'){
        clearScreen();
        displayLogo();
        displayBakerLogo();
        displayBakerOrdersUI();
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
