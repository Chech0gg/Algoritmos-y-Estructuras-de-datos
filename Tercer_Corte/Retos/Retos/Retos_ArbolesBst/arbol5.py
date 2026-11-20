# El rango · Obligatorio Escriba enRango(nodo, a, b) que imprima todas las claves entre a y b, ambas incluidas, en orden ascendente.
# La gracia está en que NO debe visitar todo el árbol: si la clave del nodo es menor que a, no tiene sentido bajar por la izquierda. 
# Pista: Es un inorden con dos podas. Agregue un contador de nodos visitados y compare contra el total del árbol: debe ser menor
# Resultado esperado: Con el árbol del ejemplo y el rango [35, 65], debe imprimir 35, 40, 50, 60 visitando menos de 8 nodos.
class Nodo:
    def __init__(self, clave, izq=None, der=None):
        self.clave = clave
        self.izq = izq
        self.der = der
def contar_nodos(nodo):
    if nodo is None:
        return 0
    return 1 + contar_nodos(nodo.izq) + contar_nodos(nodo.der)
def en_rango(nodo, a, b, estado):
    if nodo is None:
        return
    estado["visitados"] += 1
    if nodo.clave > a:
        en_rango(nodo.izq, a, b, estado)
    if a <= nodo.clave <= b:
        print(nodo.clave, end=" ")
    if nodo.clave < b:
        en_rango(nodo.der, a, b, estado)
raiz = Nodo(
    50,
    Nodo(35, Nodo(20, None, Nodo(30)), Nodo(40)),
    Nodo(70, Nodo(60), Nodo(80)),
)
a, b = 35, 65
estado = {"visitados": 0}
total = contar_nodos(raiz)

print(f"Claves en [{a}, {b}]: ", end="")
en_rango(raiz, a, b, estado)
print()

visitados = estado["visitados"]
print(f"Nodos visitados: {visitados} de {total}")
if visitados < total:
    print("Poda efectiva: se visitaron menos nodos que el total del árbol.")

