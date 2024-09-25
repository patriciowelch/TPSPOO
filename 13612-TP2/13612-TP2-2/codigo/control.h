#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Control {
    private:
        string origen;
        string destino;
    public:
        void setOrigen(string origen);
        void setDestino(string destino);
        void transformar();
};

#endif