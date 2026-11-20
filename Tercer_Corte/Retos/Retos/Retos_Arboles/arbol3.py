# ¿Son iguales? (reto corchador) Escriba sonIguales(a, b) que devuelva verdadero si dos árboles tienen la misma forma Y
#  los mismos datos en las mismas posiciones.
# Pruébelo con el árbol original contra su propio espejo: debe dar falso.
class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.izq = None
        self.der = None
def soniguales(a, b):
    if a is None and b is None: return True
    if a is None or b is None: return False
    return a.dato == b.dato and soniguales(a.izq, b.izq) and soniguales(a.der, b.der)
a = Nodo(4)
a.izq = Nodo(2)
a.der = Nodo(6)

b = Nodo(4)
b.izq = Nodo(2)
b.der = Nodo(6)

def espejo(nodo):
    if nodo is None:
        return None
    nodo.izq, nodo.der = nodo.der, nodo.izq
    espejo(nodo.izq)
    espejo(nodo.der)
    return nodo
def mismo(nodo):
    if nodo is None:
        return None
    nuevo = Nodo(nodo.dato)
    nuevo.izq = mismo(nodo.izq)
    nuevo.der = mismo(nodo.der)
    return nuevo

print(soniguales(a, b))
c = espejo(mismo(a))
print(soniguales(a, c))  