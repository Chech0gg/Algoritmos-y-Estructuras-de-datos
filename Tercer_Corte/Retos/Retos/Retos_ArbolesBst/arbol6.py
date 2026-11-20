# El detector de impostores (reto corchador)
# Escriba esBST(nodo) que determine si un árbol binario cualquiera cumple la invariante. 
# Luego constrúyale este contraejemplo: raíz 50, hijo izquierdo 30, y como hijo DERECHO del 30 ponga un 60.
#  Si su función dice que es un BST, está mal. Pista: Comparar cada nodo solo con sus dos hijos no basta. Cada nodo tiene un rango
#  permitido que se va estrechando al bajar; pásele a la recursión los límites mínimo y máximo admisibles.
# Resultado esperado: El contraejemplo debe dar falso, porque el 60 está en el subárbol izquierdo del 50 y es mayor que 50.
class Nodo:
    def __init__(self, clave, izq=None, der=None):
        self.clave = clave
        self.izq = izq
        self.der = der
def esbst_rango(nodo, minimo, maximo):
    if nodo is None:
        return True
    if minimo is not None and nodo.clave <= minimo:
        return False
    if maximo is not None and nodo.clave >= maximo:
        return False
    return esbst_rango(nodo.izq, minimo, nodo.clave) and esbst_rango(
        nodo.der, nodo.clave, maximo
    )
def esBST(nodo):
    return esbst_rango(nodo, None, None)

impostor = Nodo(50, Nodo(30, None, Nodo(60)), None)
print("¿Es BST el contraejemplo?:", esBST(impostor))  

valido = Nodo(50, Nodo(30, Nodo(20), Nodo(40)), Nodo(70))
print("¿Es BST el árbol válido?:", esBST(valido))