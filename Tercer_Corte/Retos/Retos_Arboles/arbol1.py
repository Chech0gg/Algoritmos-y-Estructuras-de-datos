#El catálogo que se imprime solo Escriba una función imprimirJerarquia(nodo, nivel) que recorra el árbol en preorden e 
#imprima cada nombre con dos espacios de sangría por nivel, de modo que el resultado se vea como un índice de documento. 
# Debe funcionar para cualquier árbol, no solo para el del ejemplo.
class Nodo:

  def __init__(self, dato):
    self.dato = dato
    self.izq = None
    self.der = None

def Jerarquia(nodo, nivel=0):
  if nodo is None:
    return
  print("  " * (nivel * 2) + str(nodo.dato))
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
