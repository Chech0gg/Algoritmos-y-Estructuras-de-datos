class TablaHash:
    def __init__(self, capacidad=8):
        self.cap = capacidad
        self.cubetas = [[] for _ in range(self.cap)]
        self.n=0
    def factor_carga(self):
        return self.n / self.cap
    def _hash(self, clave):
        h = 0
        for c in str(clave):
            h = (h * 31 + ord(c)) % self.cap
        return h
    def insertar(self, clave, valor):
        if self.factor_carga() > 0.75:
            self._redimensionar()
        i = self._hash(clave)
        for par in self.cubetas[i]:
            if par[0] == clave:
                par[1] = valor          # ACTUALIZA, no duplica
                return
        self.cubetas[i].append([clave, valor])
        self.n += 1
    def buscar(self, clave):
        i = self._hash(clave)
        for k, v in self.cubetas[i]:    # recorre SOLO esa cubeta
            if k == clave:
                return v
        return None
    def eliminar(self, clave):
        i = self._hash(clave)
        for idx, (k, _) in enumerate(self.cubetas[i]):
            if k == clave:
                self.cubetas[i].pop(idx)
                self.n -= 1
                return True
        return False
    def _redimensionar(self):
        print("Redimensionando...")  # Para ver cuándo se redimensiona
        viejas = self.cubetas
        self.cap *= 2
        self.cubetas = [[] for _ in range(self.cap)]
        self.n = 0
        for cubeta in viejas:
            for clave, valor in cubeta:
                self.insertar(clave, valor)

v = {
    "EST-2026-0101": "Ana Torres",
    "EST-2026-0102": "Carlos Rojas",
    "EST-2026-0103": "Diego Pardo",
    "EST-2026-0104": "Sofia Mejia",
    "EST-2026-0105": "Juan Gomez",
    "EST-2026-0106": "Maria Lopez",
    "EST-2026-0107": "Pedro Ruiz",
    "EST-2026-0108": "Camila Diaz",
    "EST-2026-0109": "Luis Herrera",
    "EST-2026-0110": "Valentina Cruz",
    "EST-2026-0111": "Andres Vega",
    "EST-2026-0112": "Laura Castro"
}
tabla = TablaHash()
for clave,valor in v.items():
    tabla.insertar(clave, valor)
print("''''''''Buscar EST-2026-0107''''''''''''''")
print(tabla.buscar("EST-2026-0107"))

print("''''''''Eliminar EST-2026-0107''''''''''''''")
tabla.eliminar("EST-2026-0107")
print(tabla.buscar("EST-2026-0107"))
print(tabla._redimensionar())