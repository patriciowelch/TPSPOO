#include "cli.h"
#include "control.cpp"

CLI::CLI(){
    while(1){
        int opcion = this->menu();
        if(opcion == 1){
            this->control.cargarSensores();
        }
        if(opcion == 2){
            cout<<"Simulando..."<<endl;
            cout<<"Presione cualquier tecla para terminar..."<<endl;
            this->control.simular();
        }
        if(opcion == 3){
            cout<<this->control.ultimos5();
            break;
        }
    }
}

int CLI::menu(){
    int opcion;
    cout<<"1. Cargar sensores"<<endl;
    cout<<"2. Simular"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    return opcion;
}