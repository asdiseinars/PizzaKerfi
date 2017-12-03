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
    displayBakerUI();
    char selection = '\0';
    cout << "Insert option" << endl;
    cin >> selection;

    if (selection == 'b') {
        HomeController home;
        home.init();
    }
}
