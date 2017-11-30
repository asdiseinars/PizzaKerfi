#ifndef WELCOME_H
#define WELCOME_H
#include <iostream>
#include "WelcomeView.h"

using namespace std;


class Welcome
{
    private:
        WelcomeView view;

    public:
        Welcome();
        virtual ~Welcome();
        void initialize();


};

#endif // WELCOME_H
