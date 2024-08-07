#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

class Matriz{
    private:
        int filas;
        int columnas;
        int **A;
    public:
        Matriz(int nfilas, int ncolumnas);
        void crear();
        void llenar();
        void mostrar();
        void liberar();
};

Matriz::Matriz(int nfilas, int ncolumnas){
    this->filas = nfilas;
    this->columnas = ncolumnas;
}

void Matriz::crear(){
    this->A = new int*[this->filas];
    for(int i=0; i<this->filas; i++){
        this->A[i] = new int[this->columnas];
    }
}

void Matriz::llenar(){
    for(int i=0; i<this->filas; i++){
        for(int j=0; j<this->columnas; j++){
            this->A[i][j] =rand()%10;
        }
    }
}

void Matriz::mostrar(){
    for(int i=0; i<this->filas; i++){
        for(int j=0; j<this->columnas; j++){
            cout<<this->A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Matriz::liberar(){
    for(int i=0; i<this->filas; i++){
        delete[] this->A[i];
    }
    delete[] this->A;
}


int main(void){
    srand(time(NULL));
    Matriz M(6,10);
    M.crear();
    M.llenar();
    M.mostrar();
    M.liberar();
    return 0;
}