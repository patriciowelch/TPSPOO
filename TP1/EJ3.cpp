#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Coordenada {
private:
    int x;
    int y;
    int z;
    int tiempo;
    bool estado_luz;
public:
    Coordenada(int x, int y, int z, int tiempo, bool estado_luz) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->tiempo = tiempo;
        this->estado_luz = estado_luz;
    }
    void mostrar() const {
        cout << "Coordenada: " << x << " " << y << " " << z << " " << tiempo << " " << (estado_luz ? "true" : "false") << endl;
    }
};

class Dron {
private:
    vector<Coordenada> coordenadas;
public:
    void agregar_coordenada(const Coordenada& c) {
        coordenadas.push_back(c);
    }

    void mostrar_coordenadas() const {
        for (const auto& coord : coordenadas) {
            coord.mostrar();
        }
    }
};

int main() {
    Dron dron;
    string path = "G://Otros ordenadores//Mi PC//UNIVERSIDAD//8S//POO//TPSPOO//TP1//coords.txt";
    ifstream archivo(path.c_str());
    if (archivo.is_open()) {
        cout << "Archivo Abierto" << endl;
        int x, y, z, tiempo;
        x=1;
        bool estado_luz;
        while (archivo >> x >> y >> z >> tiempo >> estado_luz) {
            Coordenada c(x, y, z, tiempo, estado_luz);
            dron.agregar_coordenada(c);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    dron.mostrar_coordenadas();
    return 0;
}