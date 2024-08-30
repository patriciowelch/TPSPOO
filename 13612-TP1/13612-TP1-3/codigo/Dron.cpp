#include "Dron.h"

Dron::Dron(int cantidad_de_coordenadas) {
    this->cantidad_de_coordenadas = cantidad_de_coordenadas;
    this->cantidad_de_coordenadas_actuales = 0;
    this->coordenadas = new Coordenada[cantidad_de_coordenadas];
}

void Dron::agregar_coordenada(const Coordenada& c) {
    if(cantidad_de_coordenadas_actuales < cantidad_de_coordenadas) {
        coordenadas[cantidad_de_coordenadas_actuales] = c;
        cantidad_de_coordenadas_actuales++;
    }
}

void Dron::mostrar_coordenadas() const{
    for(int i = 0; i < cantidad_de_coordenadas_actuales; i++) {
        cout << "Coordenada " << i+1 << ": ";
        cout << "X: " << coordenadas[i].get_coordenada().get_x() << " | ";
        cout << "Y: " << coordenadas[i].get_coordenada().get_y() << " | ";
        cout << "Z: " << coordenadas[i].get_coordenada().get_z() << " | ";
        cout << "Tiempo: " << coordenadas[i].get_coordenada().get_tiempo() << " | ";
        cout << "Estado de luz: " << (coordenadas[i].get_coordenada().get_estado_luz() ? "activo" : "inactivo") << " | ";
        cout << "Frecuencia: " << coordenadas[i].get_coordenada().get_frec() << " | ";
        cout << "Color: " << coordenadas[i].get_coordenada().get_color() << endl;
        cout << endl;
    }
}