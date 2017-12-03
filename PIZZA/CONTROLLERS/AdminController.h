#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"

using namespace GlobalHelp;
using namespace AdminUI;

class AdminController
{
    private:
    public:
        AdminController();
        virtual ~AdminController();
        void init();
};

#endif // ADMINCONTROLLER_H
