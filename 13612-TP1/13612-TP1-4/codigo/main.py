import Simulador

simulador = Simulador.Simulador()
simulador.generar_datos(10)
simulador.listar_datos()
print("Temperatura máxima: ", simulador.get_temperatura_max())
print("Presión promedio: ", simulador.get_presion_prom())