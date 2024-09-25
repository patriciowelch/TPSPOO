#include "sensores.h"

Sensor::Sensor(string id, string ip, string tipo){
    this->id = id;
    this->ip = ip;
    this->tipo = tipo;
    this->mediciones = 0;
}

string Sensor::get_tipo(){
    return this->tipo;
}

string Sensor::get_id(){
    return this->id;
}

string Sensor::get_ip(){
    return this->ip;
}

int Sensor::get_mediciones(){
    return this->mediciones;
}

SensorA::SensorA(string id, string ip) : Sensor(id, ip, "A"){
    this->temperatura.push_back(0.0);
    this->humedad.push_back(0.0);
    this->presion.push_back(0.0);
}

vector<float> SensorA::leer(int pos){
    vector<float> mediciones;
    mediciones.push_back(this->temperatura[pos]);
    mediciones.push_back(this->humedad[pos]);
    mediciones.push_back(this->presion[pos]);
    return mediciones;
}

void SensorA::agregar_medicion(vector<float>medicion){
    this->temperatura.push_back(medicion[0]);
    this->humedad.push_back(medicion[1]);
    this->presion.push_back(medicion[2]);
    this->mediciones++;
}

SensorB::SensorB(string id, string ip) : Sensor(id, ip, "B"){
    this->luminosidad.push_back(0.0);
    this->radiacionUV.push_back(0.0);
}

vector<float> SensorB::leer(int pos){
    vector<float> mediciones;
    mediciones.push_back(this->luminosidad[pos]);
    mediciones.push_back(this->radiacionUV[pos]);
    return mediciones;
}

void SensorB::agregar_medicion(vector<float>medicion){
    this->luminosidad.push_back(medicion[0]);
    this->radiacionUV.push_back(medicion[1]);
    this->mediciones++;
}

SensorC::SensorC(string id, string ip) : Sensor(id, ip, "C"){
    this->velocidad_viento.push_back(0.0);
}

vector<float> SensorC::leer(int pos){
    vector<float> mediciones;
    mediciones.push_back(this->velocidad_viento[pos]);
    return mediciones;
}

void SensorC::agregar_medicion(vector<float>medicion){
    this->velocidad_viento.push_back(medicion[0]);
    this->mediciones++;
}