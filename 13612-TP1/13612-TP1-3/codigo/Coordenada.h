#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
#include <string>
using namespace std;

class Coordenada {///Clase que representa una coordenada en el espacio
private:
    float x;
    float y;
    float z;
    float tiempo;
    bool estado_luz;
    float frec;
    string color;
public:
    Coordenada();///Constructor por defecto
    Coordenada(float x, float y, float z, float tiempo, bool estado_luz, float frec, string color);///Constructor con parametros
    Coordenada get_coordenada();///Metodo que retorna la coordenada
    float get_x() const;
    float get_y() const;
    float get_z() const;
    float get_tiempo() const;
    bool get_estado_luz() const;
    float get_frec() const;
    string get_color() const;
};

#endif
