#include "Coordenada.h"

Coordenada::Coordenada() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->tiempo = 0;
    this->estado_luz = false;
    this->frec = 0;
    this->color = "#000000";
}

Coordenada::Coordenada(float x, float y, float z, float tiempo, bool estado_luz, float frec, string color) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->tiempo = tiempo;
    this->estado_luz = estado_luz;
    this->frec = frec;
    this->color = color;
}

Coordenada Coordenada::get_coordenada() {
    return *this;
}

float Coordenada::get_x() const {
    return x;
}

float Coordenada::get_y() const {
    return y;
}

float Coordenada::get_z() const {
    return z;
}

float Coordenada::get_tiempo() const {
    return tiempo;
}

bool Coordenada::get_estado_luz() const {
    return estado_luz;
}

float Coordenada::get_frec() const {
    return frec;
}

string Coordenada::get_color() const {
    return color;
}