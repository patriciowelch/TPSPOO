#ifndef CLI_H
#define CLI_H

#include "control.h"
#include <iostream>
#include <string>
using namespace std;

class CLI {
    private:
        Control control;
    public:
        CLI();
        int menu();
};

#endif