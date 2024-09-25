import Control

class cli:
    def __init__(self, control: Control):
        self._control = control
        while True:
            if self.menu()==0:
                break
    def menu(self):
        print()
        print("1. Ingresar Parametros")
        print("2. Iniciar Conexión")
        print("3. Recibir Datos y Ver")
        print("4. Recibir Datos y Escribir")
        print("5. Salir")
        opcion = input("Ingrese una opcion: ")
        try:
            if opcion == "1":
                self.ingresar_parametros()
            elif opcion == "2":
                self.conectar()
            elif opcion == "3":
                self.recibir_datos()
            elif opcion == "4":
                self.recibir_datos(True)
            elif opcion == "5":
                return self.cerrar()
        except Exception as e:
            print(e)
            print("Acción no realizada, vuelva a intentar")
    def conectar(self):
        print("Conectando...")
        self._control.iniciar_conexion()
        pass
    def ingresar_parametros(self): 
        puerto = input("Ingrese el puerto: ")
        baudrate = input("Ingrese el baudrate: ")
        self._control.set_parametros(puerto, baudrate)
        pass
    def recibir_datos(self, escritura: bool = False):
        formato = input("Ingrese el formato a recibir: ")
        print("Recibiendo datos...")
        if escritura:
            nombre_archivo = input("Ingrese el nombre del archivo: ")
            self._control.escribir_datos_en(formato, nombre_archivo)
        else:
            print(self._control.recibir_datos_en(formato))
        pass
    def cerrar(self):
        print("Cerrando...")
        self._control.cortar_conexion()
        return 0