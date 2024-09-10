import Simulador

class cli:
    def __init__(self):
        self._simulador = Simulador.Simulador()
    def ejecutar(self):
        while True:
            print("")
            self.menu()
            try:
                opcion = int(input("Ingrese una opcion: "))
            except ValueError:
                print("Debe ingresar un numero entero")
                continue
            if opcion == 1:
                while True:
                    try:
                        cantidad_datos = int(input("Ingrese la cantidad de datos a generar: "))
                        if cantidad_datos < 1:
                            raise ValueError
                        self._simulador.generar_datos(cantidad_datos)
                        print("Datos generados")
                        break
                    except ValueError:
                        print("Debe ingresar un numero entero mayor a 0")
                        continue
                    except Exception as e:
                        print(e)
            elif opcion == 2:
                try:
                    if self._simulador.get_temperatura_max() == 0:
                        raise Exception("No hay datos")
                    self._simulador.listar_datos()
                except Exception as e:
                    print(e)
            elif opcion == 3:
                try:
                    if self._simulador.get_temperatura_max() == 0:
                        raise Exception("No hay datos")
                    print(f"Temperatura maxima: {self._simulador.get_temperatura_max()}")
                except Exception as e:
                    print(e)
            elif opcion == 4:
                try:
                    print(f"Presion promedio: {self._simulador.get_presion_prom()}")
                except ZeroDivisionError:
                    print("No hay datos")
                except Exception as e:
                    print(e)
            elif opcion == 5:
                break
            else:
                print("Opcion incorrecta")
    def menu(self):
        print("1. Generar datos")
        print("2. Listar datos")
        print("3. Mostrar temperatura maxima")
        print("4. Mostrar presion promedio")
        print("5. Salir")

    