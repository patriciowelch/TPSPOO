#include "simulador.h"
#include <windows.h>

Simulador::Simulador(vector<Sensor*> sensores){
    srand(time(NULL));
    int cantidad_sensores = sensores.size();
    while(true){
        if(_kbhit()){
            break;
        }
        for(int i = 0; i < cantidad_sensores; i++){
            if(sensores[i]->get_tipo() == "A"){
                vector<float> medicion;
                medicion.push_back(rand()%50);
                medicion.push_back(rand()%100);
                medicion.push_back(rand()%1000);
                sensores[i]->agregar_medicion(medicion);
            }else if(sensores[i]->get_tipo() == "B"){
                vector<float> medicion;
                medicion.push_back(rand()%1000);
                medicion.push_back(rand()%10);
                sensores[i]->agregar_medicion(medicion);
            }else if(sensores[i]->get_tipo() == "C"){
                vector<float> medicion;
                medicion.push_back(rand()%100);
                sensores[i]->agregar_medicion(medicion);
            }
        }
        Sleep(1000);
    }
}