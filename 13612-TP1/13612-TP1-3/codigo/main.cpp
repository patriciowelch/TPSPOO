#include <iostream>
#include <fstream>
using namespace std;
#include "Coordenada.h"
#include "Coordenada.cpp"
#include "Dron.h"
#include "Dron.cpp"

int main() {
    string path = "C://Users//pato//Documents//UNIVERSIDAD//8S//POO//TPSPOO//13612-TP1//13612-TP1-3//anexo//coords.txt";
    ifstream archivo(path.c_str());
    int cant=0;
    string nl;
    if(archivo.is_open()){
        while(getline(archivo,nl)){
            cant++;
        }
    }
    archivo.close();
    archivo.open(path.c_str());
    if(archivo.is_open()){
        Dron dron(cant);
        float x, y, z, tiempo,frec;
        bool estado_luz;
        string color;
        string linea;
        while(getline(archivo,linea)){
            while(linea.find(",")!=string::npos){
                linea.replace(linea.find(","),1,".");
            }
            x = stof(linea.substr(0, linea.find(";")));
            linea=linea.substr(linea.find(";")+1);
            y=stof(linea.substr(0,linea.find(";")));
            linea=linea.substr(linea.find(";")+1);
            z=stof(linea.substr(0,linea.find(";")));
            linea=linea.substr(linea.find(";")+1);
            tiempo=stof(linea.substr(0,linea.find(";")));
            linea=linea.substr(linea.find(";")+1);
            estado_luz=linea.substr(0,linea.find(";"))=="activo";
            linea=linea.substr(linea.find(";")+1);
            frec=stof(linea.substr(0,linea.find(";")));
            linea=linea.substr(linea.find(";")+1);
            color="#"+linea;
            Coordenada c(x,y,z,tiempo,estado_luz,frec,color);
            dron.agregar_coordenada(c);
        }
        archivo.close();
        dron.mostrar_coordenadas();
    }
    return 0;
}