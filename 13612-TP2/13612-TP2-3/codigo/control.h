#ifndef CONTROL_H
#define CONTROL_H

#include <fstream>
#include <iostream>
#include <string>
#include "sensores.h"
#include "sensores.cpp"
#include "simulador.h"
#include "simulador.cpp"
#include "windows.h"
#include <vector>
using namespace std;

class Control{
    private:
        vector<Sensor*> sensores;
    public:
        void cargarSensores();
        void simular();
        string ultimos5();
};

#endif