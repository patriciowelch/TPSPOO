from Dato import *
import random

class Simulador:
	def __init__(self):
		self._datos = []
		self._temperatura_max = 0
		self._presion_prom = 0
	def generar_datos(self, N: int):
		for i in range(N):
			dato = Dato(random.uniform(-10, 40), random.uniform(900, 1100), random.randint(0, 100))
			self.datos.append(dato)
	def listar_datos(self):
		for dato in self.datos:
			print(dato.__str__())
	def get_temperatura_max(self):
		self.temperatura_max = 0
		for dato in self.datos:
			if dato.get_Temperatura() > self.temperatura_max:
				self.temperatura_max = dato.get_Temperatura()
		return self.temperatura_max
	def get_presion_prom(self):
		self.presion_prom = 0
		for dato in self.datos:
			self.presion_prom += dato.get_Presion()
		self.presion_prom /= len(self.datos)
		return self.presion_prom



