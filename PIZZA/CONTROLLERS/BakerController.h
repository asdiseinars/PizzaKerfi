#ifndef BAKERCONTROLLER_H
#define BAKERCONTROLLER_H
#include "BakerUI.h"
#include <iostream>
#include "HomeController.h"
#include "GlobalHelp.h"

using namespace GlobalHelp;
using namespace std;
using namespace BakerUI;


class BakerController
{
    private:

    public:
        BakerController();
        virtual ~BakerController();
        void init();



};

#endif // BAKERCONTROLLER_H
