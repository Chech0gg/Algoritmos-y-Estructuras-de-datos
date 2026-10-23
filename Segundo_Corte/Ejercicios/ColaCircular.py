class ColaCircular:
    def __init__(self, cap):
        self.cap = cap
        self.datos = [None] * cap
        self.frente = 0
        self.n = 0
 
    def encolar(self, x):                     # O(1)
        if self.n == self.cap:
            return False                      # llena: no crece
        self.datos[(self.frente + self.n) % self.cap] = x   # el módulo da la vuelta
        self.n += 1
        return True
 
    def desencolar(self):                     # O(1)
        if self.n == 0:
            return None
        x = self.datos[self.frente]
        self.datos[self.frente] = None        # buena práctica: soltar la referencia
        self.frente = (self.frente + 1) % self.cap
        self.n -= 1
        return x
 
    def ver_frente(self):
        return None if self.n == 0 else self.datos[self.frente]
 
    def vacia(self):
        return self.n == 0
 
    def lleno(self):
        return self.n == self.cap
 
    def orden_logico(self):                   # como la "ve" la cola
        return [self.datos[(self.frente + i) % self.cap] for i in range(self.n)]
