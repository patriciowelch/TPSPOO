import random as rd

class Matriz:
    def __init__(self, filas, columnas):
        self.filas = filas
        self.columnas = columnas
        self.matriz = [[0 for _ in range(columnas)] for _ in range(filas)]
    def llenar(self):
        for i in range(self.filas):
            for j in range(self.columnas):
                self.matriz[i][j] = rd.randint(0, 100)
    def mostrar(self):
        for i in range(self.filas):
            for j in range(self.columnas):
                print(self.matriz[i][j], end = " ")
            print()
    def liberar(self):
        del self.matriz

m = Matriz(6, 10)
m.llenar()
m.mostrar()
m.liberar()