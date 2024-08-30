class Dato:
	def __init__(self, Temperatura: float, Presion: float, Humedad: int):
		self._Temperatura = Temperatura
		self._Presion = Presion
		self._Humedad = Humedad
	def get_Temperatura(self):
		return self._Temperatura
	def get_Presion(self):
		return self._Presion
	def get_Humedad(self):
		return self._Humedad
	def __str__(self):
		return f"Temperatura: {self._Temperatura}, Presion: {self._Presion}, Humedad: {self._Humedad}"



