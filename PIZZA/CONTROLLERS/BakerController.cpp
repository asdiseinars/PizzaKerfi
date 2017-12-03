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
    displayBakerUI();

    char selection = '\0';
    cin >> selection;

    if(selection == '1'){
        clearScreen();
        displayLogo();
        displayBakerOrdersUI();
    }

    else if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
