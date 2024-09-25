#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string>
#include "control.h"
using namespace std;

class CLI {
    private:
        Control control;
    public:
        CLI();
        int menu();
};

#endif