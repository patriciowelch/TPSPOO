from Dato import *
import random

class Simulador:
	def __init__(self):
		self._datos = []
		self._temperatura_max = 0
		self._presion_prom = 0
		self._cantidad_datos = 0
	def generar_datos(self, cantidad_datos: int):
		self._cantidad_datos = cantidad_datos
		for i in range(self._cantidad_datos):
			dato = Dato(random.uniform(-10, 40), random.uniform(900, 1100), random.randint(0, 100))
			self._datos.append(dato)
	def listar_datos(self):
		for dato in self._datos:
			print(dato.__str__())
	def get_temperatura_max(self):
		self._temperatura_max = 0
		for dato in self._datos:
			if dato.get_Temperatura() > self._temperatura_max:
				self._temperatura_max = dato.get_Temperatura()
		return self._temperatura_max
	def get_presion_prom(self):
		self._presion_prom = 0
		for dato in self._datos:
			self._presion_prom += dato.get_Presion()
		self._presion_prom /= len(self._datos)
		return self._presion_prom