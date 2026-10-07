# Paso 1 Laestructura de datos hash
class TablaHash:
    def __init__(self, capacidad=8):
        self.cap = capacidad
        self.cubetas = [[] for _ in range(self.cap)]
        self.n=0
    def _hash(self, clave):
        h = 0
        for c in str(clave):
            h = (h * 31 + ord(c)) % self.cap
        return h
    def insertar(self, clave, valor):
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
        
        #Con los 8 códigos REC-001, REC-002, REC-003, EQ-100, 
        # EQ-101, PA-007, PA-008, EST-42
        #mostrar distribución de cubetas y factor de carga
        #buscar un código y mostrar su valor
        #buscar un código que no existe y mostrar el resultado
        #actualizar un código y mostrar el resultado
        #eliminar un código y mostrar el resultado
        #distribución de cubetas y factor de carga después de eliminar 
        # un código
        # revisar si hay colisiones y mostrar la lista 
        # enlazada de esa cubeta
v = {"REC-001": "Valor 1", "REC-002": "Valor 2", "REC-003": "Valor 3", "EQ-100": "Valor 4", "EQ-101": "Valor 5", "PA-007": "Valor 6", "PA-008": "Valor 7", "EST-42": "Valor 8"}
tabla = TablaHash()
for clave, valor in v.items():
    tabla.insertar(clave, valor)
print("Distribución de cubetas y factor de carga:")
for i, cubeta in enumerate(tabla.cubetas):
    print(f"Cubeta {i}: {cubeta}")
print(f"Factor de carga: {tabla.n / tabla.cap}")
print(tabla._hash("REC-001"))
print(tabla._hash("REC-002"))
print(tabla._hash("REC-003"))
print(tabla._hash("EQ-100"))
print(tabla._hash("EQ-101"))
print(tabla._hash("PA-007"))
print(tabla._hash("PA-008"))
print(tabla._hash("EST-42"))
print(tabla.buscar("REC-001"))
print(tabla.buscar("NO-EXISTE"))
tabla.insertar("REC-001", "Valor 1 actualizado")
print(tabla.buscar("REC-001"))
tabla.eliminar("REC-001")
print(tabla.buscar("REC-001"))
print("Distribución de cubetas y factor de carga después de eliminar REC-001:")
for i, cubeta in enumerate(tabla.cubetas):
    print(f"Cubeta {i}: {cubeta}")
print(f"Factor de carga: {tabla.n / tabla.cap}")

# Revisar si hay colisiones y mostrar la lista enlazada de esa cubeta
print("Colisiones y listas enlazadas de cada cubeta:")
for i, cubeta in enumerate(tabla.cubetas):
    if len(cubeta) > 1:
        print(f"Cubeta {i} tiene colisiones: {cubeta}")
