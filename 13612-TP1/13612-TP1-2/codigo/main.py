import random as rd

class Matriz:
    def __init__(self, filas, columnas):
        self._filas = filas
        self._columnas = columnas
        self._matriz = [[0 for _ in range(self._columnas)] for _ in range(self._filas)]
    def llenar(self):
        for i in range(self._filas):
            for j in range(self._columnas):
                self._matriz[i][j] = rd.randint(0, 9)
    def mostrar(self):
        for i in range(self._filas):
            for j in range(self._columnas):
                print(self._matriz[i][j], end = " ")
            print()
    def liberar(self):
        del self._matriz

m = Matriz(7, 10)
m.llenar()
m.mostrar()
m.liberar()