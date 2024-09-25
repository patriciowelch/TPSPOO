#include "cli.h"
#include "control.cpp"

CLI::CLI(){
    while(1){
        int opcion = this->menu();
        if(opcion == 1){
            string origen;
            string destino;
            cout<<"Ingrese nombre de origen:"<<endl;
            cin>>origen;
            this->control.setOrigen(origen);
            cout<<"Ingrese nombre de destino:"<<endl;
            cin>>destino;
            this->control.setDestino(destino);
            this->control.transformar();
        }
        if(opcion == 2){
            break;
        }
    }
}

int CLI::menu(){
    int opcion;
    cout<<"1. Transferir Datos CSV a XML"<<endl;
    cout<<"2. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    return opcion;
}