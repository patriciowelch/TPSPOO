import medicion
import pickle
import cli
import random as rd
import os

cli = cli.cli()
path_o = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir))

while True:
    try:
        opcion = cli.menu()
        if opcion == 1:
            [cantidad, nombre] = cli.generar()
            mediciones = []
            for i in range(cantidad):
                #el primer y segundo dato flotante el tercero entero truncar al segundo decimal
                mediciones.append(medicion.Medicion(round(rd.uniform(0, 100), 2), round(rd.uniform(0, 1000), 2), rd.randint(0, 100)))
            #obtener path superior
            path = os.path.join(path_o,"anexo",nombre)
            with open(path+".pkl", "wb") as f:
                pickle.dump(mediciones, f)
            cli.datos_generados(path)
        if opcion == 2:
            [nombre, mostrar_vprom] = cli.seleccionar_archivo()
            path = os.path.join(path_o,"anexo",nombre)
            with open(path+".pkl", "rb") as f:
                mediciones = pickle.load(f)
            for medicion in mediciones:
                cli.imprimir(str(medicion))
            if mostrar_vprom == "s":
                vprom = sum([medicion._velocidad for medicion in mediciones])/len(mediciones)
                cli.imprimir(f"Promedio de velocidad: {vprom}")
        if opcion == 3:
            pass
        if opcion == 4:
            cli.cerrar()
            break
    except Exception as e:
        print(e)
