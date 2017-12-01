#ifndef HOME_H
#define HOME_H
#include "HomeUI.h"
#include <iostream>

using namespace std;

class Home
{
    private:
        HomeUI homeui;

    public:
        Home();
        void initialize();
};

#endif // HOME_H
