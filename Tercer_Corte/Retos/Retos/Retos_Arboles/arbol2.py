
# El espejo Escriba espejo(nodo) que intercambie el hijo 
# izquierdo y el derecho de TODOS los nodos del árbol.
# Luego imprima el inorden del árbol original y el del árbol espejado.
class Nodo:
    def __init__(self, valor, izquierdo=None, derecho=None):
        self.valor = valor
        self.izquierdo = izquierdo
        self.derecho = derecho
def espejo(nodo):
    if nodo is None:
        return None
    nodo.izquierdo, nodo.derecho = nodo.derecho, nodo.izquierdo
    espejo(nodo.izquierdo)
    espejo(nodo.derecho)
    return nodo
def inorden(nodo):
    if nodo is None:
        return []
    return inorden(nodo.izquierdo) + [nodo.valor] + inorden(nodo.derecho)
def imprimir_inorden(nodo):
    if nodo is None:
        return
    imprimir_inorden(nodo.izquierdo)  
    print(nodo.valor, end=" ")        
    imprimir_inorden(nodo.derecho)  
raiz = Nodo(
    4,
    Nodo(2, Nodo(1), Nodo(3)),
    Nodo(6, Nodo(5), Nodo(7)),
)
print("Inorden original:", end=" ")
imprimir_inorden(raiz)
espejo(raiz)
print("Inorden espejado:", end=" ")
imprimir_inorden(raiz)
