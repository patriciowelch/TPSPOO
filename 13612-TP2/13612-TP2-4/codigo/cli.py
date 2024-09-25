class cli:
    def menu(self):
        print()
        print("1. Generar Datos y Guardar")
        print("2. Visualizar Datos")
        print("3. Buscar Medición Mayor Altitud")
        print("4. Salir")
        opcion = input("Ingrese una opción: ")
        if opcion.isdigit() and int(opcion) in range(1, 5):
            return int(opcion)
        else:
            raise Exception("Opción inválida")
        
    def generar(self):
        cantidad = input("Ingrese la cantidad de mediciones a generar: ")
        nombre = input("Ingrese el nombre del archivo: ")
        if cantidad.isdigit():
            cantidad = int(cantidad)
        else:
            raise Exception("Cantidad inválida")
        if not nombre:
            raise Exception("Nombre inválido")
        print("Generando...")
        return [cantidad, nombre]
    def visualizar(self):
        print("Visualizando...")
        return 0
    def buscar(self):
        print("Buscando...")
        return 0
    def cerrar(self):
        print("Cerrando...")
        return 0
    def datos_generados(self,path:str):
        print(f"Datos generados y guardados en {path}")
        return 0
    def seleccionar_archivo(self):
        nombre = input("Ingrese el nombre del archivo: ")
        mostrar_vprom = input("¿Desea mostrar el promedio de velocidad? (s/n): ")

        if not nombre:
            raise Exception("Nombre inválido")
        if mostrar_vprom.lower() == "s" or mostrar_vprom.lower() == "n":
            pass
        else:
            raise Exception("Opción inválida")
        print("Visualizando...")
        return [nombre, mostrar_vprom]
    def imprimir(self, mensaje:str):
        print(mensaje)
        return 0