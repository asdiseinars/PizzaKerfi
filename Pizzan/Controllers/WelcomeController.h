#ifndef WELCOMECONTROLLER_H
#define WELCOMECONTROLLER_H
#include "WelcomeView.h"
#include <iostream>

using namespace std;


class WelcomeController
{
    private:
         WelcomeView view;

    public:
        WelcomeController();
        virtual ~WelcomeController();
        void initialize();

};

#endif // WELCOMECONTROLLER_H
