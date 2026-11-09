# ============================================================
#  Laboratorio integrador · Corte 3 · RETO 1  (25 puntos)
#  Sesiones 35 y 36 — Arboles binarios y BST
#  Sistema: RedAcopio — indice de recursos por codigo
#
#  MODIFIQUE SOLO ESTE ARCHIVO.  NO TOQUE pruebas_r1.py
#  Ejecute:   python3 pruebas_r1.py Estudiante : Sergio Rios
# ============================================================


class Nodo:
    def __init__(self, codigo, nombre):
        self.codigo = codigo
        self.nombre = nombre
        self.izq = None
        self.der = None


def insertar(n, codigo, nombre):
    if n is None:
        return Nodo(codigo, nombre)
    if codigo < n.codigo:
        n.izq = insertar(n.izq, codigo, nombre)
    elif codigo > n.codigo:
        n.der = insertar(n.der, codigo, nombre)
    return n
    pass



def inorden(n, salida):
    """Ya implementado: recorre izquierda, raiz, derecha."""
    if n is None:
        return
    inorden(n.izq, salida)
    salida.append(n.codigo)
    inorden(n.der, salida)


def altura(n):
    if n is None:
        return -1
    return 1 + max(altura(n.izq), altura(n.der))
    pass


def buscar(n, codigo):
    """Devuelve (nodo, comparaciones). Si no esta, el nodo es None.
       Debe bajar comparando, NO recorrer todo el arbol.

       PENDIENTE: implementar."""
    comparaciones = 0
    actual = n
    while actual is not None:
        comparaciones += 1
        if codigo == actual.codigo:
            return actual, comparaciones
        elif codigo < actual.codigo:
            actual = actual.izq
        elif codigo > actual.codigo:
            actual = actual.der
        else:
            None
    return None, comparaciones

def minimo(n):
    """Ya implementado: el extremo izquierdo."""
    while n.izq is not None:
        n = n.izq
    return n
n = None
DATOS = [(450,"Taladro"), (220,"Proyector"), (780,"Carpa"), (130,"Megafono"),
         (310,"Mesa"),   (640,"Bascula"),   (890,"Carretilla"), (275,"Extension")]
for codigo, nombre in DATOS:
    n = insertar(n, codigo, nombre)

salida = []
inorden(n, salida)
print(salida)
print(altura(n))
print(buscar(n, 310))
print(buscar(n, 999))
