class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.izq = None
        self.der = None

def preorden(n, salida):
    if n is None: return          # caso base: subarbol vacio
    salida.append(n.dato)         # 1) raiz
    preorden(n.izq, salida)       # 2) izquierda
    preorden(n.der, salida)       # 3) derecha

def inorden(n, salida):
    if n is None: return
    inorden(n.izq, salida)        # 1) izquierda
    salida.append(n.dato)         # 2) raiz
    inorden(n.der, salida)        # 3) derecha

def postorden(n, salida):
    if n is None: return
    postorden(n.izq, salida)      # 1) izquierda
    postorden(n.der, salida)      # 2) derecha
    salida.append(n.dato)         # 3) raiz

def altura(n):
    if n is None: return -1       # arbol vacio: altura -1 (un solo nodo: 0)
    return 1 + max(altura(n.izq), altura(n.der))

def contar(n):
    if n is None: return 0
    return 1 + contar(n.izq) + contar(n.der)

def contar_hojas(n):
    if n is None: return 0
    if n.izq is None and n.der is None: return 1
    return contar_hojas(n.izq) + contar_hojas(n.der)

def por_niveles(raiz):
    if raiz is None: return []
    from collections import deque
    cola = deque([raiz]); salida = []
    while cola:
        n = cola.popleft()
        salida.append(n.dato)
        if n.izq: cola.append(n.izq)
        if n.der: cola.append(n.der)
    return salida
def soniguales(a, b):
    if a is None and b is None: return True
    if a is None or b is None: return False
    return a.dato == b.dato and soniguales(a.izq, b.izq) and soniguales(a.der, b.der)
a = Nodo(10)
a.izq = Nodo(5)
a.der = Nodo(15)

b = Nodo(10)
b.izq = Nodo(5)
b.der = Nodo(15)

print(soniguales(a, b))