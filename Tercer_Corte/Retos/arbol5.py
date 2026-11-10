class Nodo:
    def __init__(self, clave, nombre=""):
        self.clave = clave; self.nombre = nombre
        self.izq = None; self.der = None
        
def insertar(n, clave, nombre=""):
    if n is None: return Nodo(clave, nombre)
    if clave < n.clave: n.izq = insertar(n.izq, clave, nombre)   # el retorno se REENGANCHA
    elif clave > n.clave: n.der = insertar(n.der, clave, nombre)
     # clave repetida: no se inserta
    return n

def buscar(n, clave, pasos=None):
    if pasos is not None: pasos.append("vacio" if n is None else str(n.clave))
    if n is None or n.clave == clave: return n
    return buscar(n.izq, clave, pasos) if clave < n.clave else buscar(n.der, clave, pasos)

def minimo(n):
    while n.izq is not None: n=n.izq
    return n
 
def maximo(n):
    while n.der is not None: n = n.der
    return n
 
def eliminar(n, clave):
    if n is None: return None
    if clave < n.clave: n.izq = eliminar(n.izq, clave)
    elif clave > n.clave: n.der = eliminar(n.der, clave)
    else: #encontramos el nodo a eliminar
        if n.izq is None: return n.der
        if n.der is None: return n.izq
        suc=minimo(n.der)
        n.clave,n.nombre=suc.clave,suc.nombre
        n.der=eliminar(n.der,suc.clave)
    return n
def inorden(n, s):
    if n is None: return
    inorden(n.izq, s); s.append(n.clave); inorden(n.der, s)
    
def altura(n):
    if n is None: return -1
    return 1 + max(altura(n.izq), altura(n.der))

def espejoNodo(n):
    if n is None: return None
    n.izq, n.der = espejoNodo(n.der), espejoNodo(n.izq)
    return n

print("El arbol inorden es :")
raiz = insertar(None, 50)
raiz = insertar(raiz, 30)
raiz = insertar(raiz, 70)
raiz = insertar(raiz, 20)
raiz = insertar(raiz, 40)
raiz = insertar(raiz, 60)
raiz = insertar(raiz, 80)
s = []
inorden(raiz, s)
print(s)
raiz = espejoNodo(raiz)
print("El arbol inorden espejo es :")
s = []
inorden(raiz, s)
print(s)