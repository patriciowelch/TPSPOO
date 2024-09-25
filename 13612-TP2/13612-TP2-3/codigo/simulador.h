#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <ctime>
#include "control.h" 
#include <vector>
#include <conio.h>
using namespace std;

class Simulador {
public:
    Simulador(vector<Sensor*> sensores);
};

#endif