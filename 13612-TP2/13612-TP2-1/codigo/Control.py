import serial

class Control:
    def __init__(self):
        self._puerto = None
        self._baudrate = None
        self._timeout = None
        self._serial = serial.Serial()
    def set_parametros(self, puerto:str, baudrate:int, timeout:float=1):
        if puerto == "" or baudrate == "":
            raise Exception("Error: Puerto y Baudrate no pueden ser vacios")
        self._puerto = puerto
        self._baudrate = baudrate
        self._timeout = timeout
        pass
    def iniciar_conexion(self):
        if self._serial.is_open==False:
            self._serial = serial.Serial(self._puerto, self._baudrate, timeout=self._timeout)
        pass
    def cortar_conexion(self):
        self._serial.close()
        pass
    def recibir_datos_en(self, tipo:str):
        if self._serial.is_open==False:
            raise Exception("Error: No se ha iniciado la conexión")
        if tipo not in ["x", "j", "c"]:
            raise Exception("Error: Formato no válido")
        #limpiar buffer
        while self._serial.in_waiting>0:
            self._serial.readline()
        self._serial.write(tipo.encode())
        texto = ""
        while self._serial.in_waiting==0:
            pass
        while self._serial.in_waiting>0:
            texto += self._serial.readline().decode()
            #quitar el ultimo caracter que es un salto de linea
        return texto
    def escribir_datos_en(self, tipo:str, nombre_archivo:str):
        if self._serial.is_open==False:
            raise Exception("Error: No se ha iniciado la conexión")
        if tipo not in ["x", "j", "c"]:
            raise Exception("Error: Formato no válido")
        while self._serial.in_waiting>0:
            self._serial.readline()
        self._serial.write(tipo.encode())
        with open("C://Users//pato//Documents//UNIVERSIDAD//8S//POO//TPSPOO//13612-TP2//13612-TP2-1//anexo//"+nombre_archivo+".csv", "a") as archivo:
            archivo.write(self.recibir_datos_en("c"))
        pass
    def cortar_conexion(self):
        self._serial.close()
        pass