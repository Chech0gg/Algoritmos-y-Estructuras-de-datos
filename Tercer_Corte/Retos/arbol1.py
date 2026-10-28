class Nodo:

  def __init__(self, dato):
    self.dato = dato
    self.izq = None
    self.der = None


def preorden(n, salida):
  if n is None:
    return
  salida.append(n.dato)
  preorden(n.izq, salida)
  preorden(n.der, salida)


def inorden(n, salida):
  if n is None:
    return
  inorden(n.izq, salida)
  salida.append(n.dato)
  inorden(n.der, salida)


def postorden(n, salida):
  if n is None:
    return
  postorden(n.izq, salida)
  postorden(n.der, salida)
  salida.append(n.dato)


def altura(n):
  if n is None:
    return -1
  return 1 + max(altura(n.izq), altura(n.der))


def contar(n):
  if n is None:
    return 0
  return 1 + contar(n.izq) + contar(n.der)


def contar_hojas(n):
  if n is None:
    return 0
  if n.izq is None and n.der is None:
    return 1
  return contar_hojas(n.izq) + contar_hojas(n.der)


def por_niveles(raiz):
  if raiz is None:
    return []
  from collections import deque

  cola = deque([raiz])
  salida = []
  while cola:
    n = cola.popleft()
    salida.append(n.dato)
    if n.izq:
      cola.append(n.izq)
    if n.der:
      cola.append(n.der)
  return salida

# realizo la funcion para imprimir la jerarquía del árbol
# mostrando cada nodo con su nivel de profundidad en el árbol
def Jerarquia(nodo, nivel=0):
  if nodo is None:
    return
  print(" " * (nivel * 2) + str(nodo.dato))
  Jerarquia(nodo.izq, nivel + 1)
  Jerarquia(nodo.der, nivel + 1)

raiz = Nodo("CATALOGO")
raiz.izq = Nodo("HERRAMIENTA")
raiz.der = Nodo("LIBRO")
raiz.izq.izq = Nodo("TALADRO")
raiz.izq.der = Nodo("SIERRA")
raiz.der.izq = Nodo("ARTE")
raiz.der.der = Nodo("TECNICO")
raiz.der.der.der = Nodo("REDES")
Jerarquia(raiz)
