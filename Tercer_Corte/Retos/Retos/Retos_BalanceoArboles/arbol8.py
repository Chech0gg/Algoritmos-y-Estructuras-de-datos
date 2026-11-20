#El orden maldito · Obligatorio
#Encuentre un orden de inserción de las siete claves 1 a 7 que
#produzca un BST perfectamente equilibrado (altura 2) sin aplicar ninguna rotación. 
#Después encuentre el peor orden posible. Explique qué tienen en común todos los órdenes que dan altura 2. 
#Pista: Piense en qué clave tiene que llegar primero para que el árbol quede partido por la mitad. 
#Luego repita el razonamiento en cada mitad. Resultado esperado: Hay varios órdenes válidos. 
#Todos empiezan por el 4. Cuente cuántos son: la respuesta es un número sorprendentemente grande
class Nodo:
    def __init__(self, clave, izq=None, der=None):
        self.clave = clave
        self.izq = izq
        self.der = der
def insertar(nodo, clave):
    if nodo is None:
        return Nodo(clave)
    if clave < nodo.clave:
        nodo.izq = insertar(nodo.izq, clave)
    else:
        nodo.der = insertar(nodo.der, clave)
    return nodo
def altura(nodo):
    if nodo is None:
        return -1
    izq = altura(nodo.izq)
    der = altura(nodo.der)
    return 1 + (izq if izq > der else der)
def probar_ordenes(disponibles, actual, encontrados):
    if not disponibles:
        raiz = None
        for clave in actual:
            raiz = insertar(raiz, clave)

        if altura(raiz) == 2:
            encontrados.append(list(actual))
        return

    for i in range(len(disponibles)):
        elegido = disponibles[i]
        resto = disponibles[:i] + disponibles[i + 1 :]
        actual.append(elegido)
        probar_ordenes(resto, actual, encontrados)
        actual.pop()
claves = [1, 2, 3, 4, 5, 6, 7]
validos = []
probar_ordenes(claves, [], validos)

print("Órdenes válidos de altura 2:", len(validos)) 
print("Ejemplo válido:", validos[0])

peor = None
for x in [1, 2, 3, 4, 5, 6, 7]:
    peor = insertar(peor, x)
print("Peor orden [1..7] -> altura:", altura(peor))