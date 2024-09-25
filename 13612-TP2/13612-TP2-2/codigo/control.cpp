#include "control.h"

void Control::setOrigen(string origen){
    this->origen = "C://Users//pato//Documents//UNIVERSIDAD//8S//POO//TPSPOO//13612-TP2//13612-TP2-2//anexo//"+origen;
}

void Control::setDestino(string destino){
    this->destino = "C://Users//pato//Documents//UNIVERSIDAD//8S//POO//TPSPOO//13612-TP2//13612-TP2-2//anexo//"+destino;
}

void Control::transformar(){
    cout<<"Transformando "<<this->origen<<" a "<<this->destino<<endl;
    ifstream CSV(this->origen);
    ofstream XML(this->destino);
    string linea;
    while(getline(CSV, linea)){
        XML<<"<fila>"<<linea<<"</fila>"<<endl;
    }
    CSV.close();
    XML.close();
}