class Nodo:
    def __init__(self, clave):
        self.clave = clave
        self.izq = None
        self.der = None
def insertar(n, clave):
    if n is None:                     # llegamos a un hueco: aqui va
        return Nodo(clave)
    if clave < n.clave:
        n.izq = insertar(n.izq, clave)   # el retorno se REENGANCHA
    elif clave > n.clave:
        n.der = insertar(n.der, clave)
    return n
m=[10,21,1,3,12,]
raiz=None
for c in m:
    raiz=insertar(raiz,c)
Nodo(raiz)