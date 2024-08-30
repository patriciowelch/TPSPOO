#ifndef DRON_H
#define DRON_H

#include "Coordenada.h"

class Dron {///Clase que representa un dron
private:
    Coordenada *coordenadas;
    int cantidad_de_coordenadas;
    int cantidad_de_coordenadas_actuales;
public:
    Dron(int cantidad_de_coordenadas);///Constructor con parametros
    void agregar_coordenada(const Coordenada& c);///Metodo que agrega una coordenada al dron
    void mostrar_coordenadas() const;///Metodo que muestra las coordenadas del dron
};

#endif