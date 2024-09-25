#include "control.h"

void Control::cargarSensores(){
    wchar_t path_c[MAX_PATH];
    GetModuleFileNameW(NULL, path_c, MAX_PATH);
    wstring wpath(path_c);
    string path(wpath.begin(), wpath.end());
    path = path.substr(0, path.find_last_of("\\"));
    path = path.substr(0, path.find_last_of("\\"));
    path+="\\anexo\\config.cfg";
    ifstream archivo(path);
    string linea;
    if(!archivo.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }
    while(getline(archivo, linea)){
        string id = linea.substr(0, linea.find(" "));
        linea = linea.substr(linea.find(" ")+1);
        string ip = linea.substr(0, linea.find(" "));
        linea = linea.substr(linea.find(" ")+1);
        string tipo = linea;
        if(tipo == "A"){
            SensorA* sensor = new SensorA(id, ip);
            this->sensores.push_back(sensor);
        }else if(tipo == "B"){
            SensorB* sensor = new SensorB(id, ip);
            this->sensores.push_back(sensor);
        }else if(tipo == "C"){
            SensorC* sensor = new SensorC(id, ip);
            this->sensores.push_back(sensor);
        }
    }
    archivo.close();
}

void Control::simular(){
    Simulador simulador(this->sensores);
}

string Control::ultimos5(){
    string toreturn="";
    for(int i = 0; i < this->sensores.size(); i++){
        toreturn+="Sensor "+this->sensores[i]->get_id()+" "+this->sensores[i]->get_ip()+" "+this->sensores[i]->get_tipo()+"\n";
        int c_mediciones=this->sensores[i]->get_mediciones();
        for(int j = c_mediciones; j > c_mediciones-5; j--){
            if(j<0){
                break;
            }
            vector<float> mediciones = this->sensores[i]->leer(j);
            toreturn+="Medicion "+to_string(j)+": ";
            if(this->sensores[i]->get_tipo() == "A"){
                toreturn+="Temperatura: "+to_string(mediciones[0])+" Humedad: "+to_string(mediciones[1])+" Presion: "+to_string(mediciones[2])+"\n";
            }else if(this->sensores[i]->get_tipo() == "B"){
                toreturn+="Luminosidad: "+to_string(mediciones[0])+" Radiacion UV: "+to_string(mediciones[1])+"\n";
            }else if(this->sensores[i]->get_tipo() == "C"){
                toreturn+="Velocidad del viento: "+to_string(mediciones[0])+"\n";
            }else{
                toreturn+="Tipo de sensor no reconocido\n";
            }
        }
        toreturn+="\n";
    }
    return toreturn;
}