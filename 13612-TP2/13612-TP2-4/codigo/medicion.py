class Medicion:
    def __init__(self, velocidad: float, distancia: float, altitud: int):
        self._velocidad = velocidad
        self._distancia = distancia
        self._altitud = altitud
    def __str__(self):
        return f"Velocidad: {self._velocidad} m/s, Distancia: {self._distancia} m, Altitud: {self._altitud} m"