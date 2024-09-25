#ifndef SENSORES_H
#define SENSORES_H

#include <string>
using namespace std;
#include <vector>

class Sensor{        
    private:
        string id;
        string ip;
        string tipo;
    public:
        Sensor(string id, string ip, string tipo);
        virtual vector<float> leer(int pos) = 0;
        virtual void agregar_medicion(vector<float>medicion) = 0;
        string get_tipo();
        string get_id();
        string get_ip();
        int get_mediciones();
    protected:
        int mediciones;
};

class SensorA : public Sensor{
    private:
        vector<float> temperatura;
        vector<float> humedad;
        vector<float> presion;
    public:
        SensorA(string id, string ip);
        vector<float> leer(int pos);
        void agregar_medicion(vector<float>medicion);
};

class SensorB : public Sensor{
    private:
        vector<float> luminosidad;
        vector<float> radiacionUV;
    public:
        SensorB(string id, string ip);
        vector<float> leer(int pos);
        void agregar_medicion(vector<float>medicion);
};

class SensorC : public Sensor{
    private:
        vector<float> velocidad_viento;
    public:
        SensorC(string id, string ip);
        vector<float> leer(int pos);
        void agregar_medicion(vector<float>medicion);
};

#endif