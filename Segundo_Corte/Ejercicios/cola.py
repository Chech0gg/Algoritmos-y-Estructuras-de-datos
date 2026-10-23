class Cola:
    class _Nodo:
        __slots__ = ("dato", "siguiente")
 
        def __init__(self, dato):
            self.dato = dato
            self.siguiente = None
 
    def __init__(self):
        self.frente = None   # por aquí se SALE
        self.final = None    # por aquí se ENTRA
        self.n = 0           # contador redundante: tamaño en O(1)
 
    def encolar(self, x):                     # O(1)
        nuevo = self._Nodo(x)
        if self.final is None:                # cola vacía: ambos apuntan al nuevo
            self.frente = self.final = nuevo
        else:
            self.final.siguiente = nuevo
            self.final = nuevo
        self.n += 1
 
    def desencolar(self):                     # O(1)
        if self.frente is None:
            return None
        x = self.frente.dato
        self.frente = self.frente.siguiente
        if self.frente is None:               # <- EL CASO QUE SE OLVIDA
            self.final = None
        self.n -= 1
        return x
 
    def ver_frente(self):                     # O(1) — mirar sin sacar
        return None if self.frente is None else self.frente.dato
 
    def vacia(self):
        return self.n == 0
 
    def __len__(self):
        return self.n
 
    def __str__(self):                        # O(n), solo para depurar
        partes, actual = [], self.frente
        while actual:
            partes.append(str(actual.dato))
            actual = actual.siguiente
        return "frente -> [" + ", ".join(partes) + "] <- final"
