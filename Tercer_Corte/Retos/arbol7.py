class Nodo:
    def __init__(self, c):
        self.clave = c; self.izq = None; self.der = None; self.alt = 0

def insertar(n, clave):
    if n is None: return Nodo(clave)
    if clave < n.clave:
        n.izq = insertar(n.izq, clave)
    elif clave > n.clave:
        n.der = insertar(n.der, clave)
    recalc(n)
    if fe(n) == 2:
        if fe(n.izq) < 0:
            n.izq = rotarIzquierda(n.izq)
        return rotarDerecha(n)
    if fe(n) == -2:
        if fe(n.der) > 0:
            n.der = rotarDerecha(n.der)
        return rotarIzquierda(n)
    return n

def buscar(n, clave, pasos=None):
    if pasos is not None:
        pasos.append("vacio" if n is None else str(n.clave))
    if n is None or n.clave == clave: return n
    return buscar(n.izq, clave, pasos) if clave < n.clave else buscar(n.der, clave, pasos)
        
def alt(n):  return -1 if n is None else n.alt
def fe(n):   return 0 if n is None else alt(n.izq) - alt(n.der)   # factor de equilibrio
def recalc(n): n.alt = 1 + max(alt(n.izq), alt(n.der))   
def rotarDerecha(y):
    x= y.izq; B=x.der
    x.der=y; y.izq=B
    recalc(y);recalc(x)
    return x

def rotarIzquierda(x):
    y=x.der; B=y.izq
    y.izq=x; x.der=B
    recalc(x);recalc(y)
    return y

def inorden(n,s):
    if n is None:return
    inorden(n.izq,s);s.append(n.clave);inorden(n.der,s)
    
def preorden(n,s):
    if n is None:return
    s.append(f"{n.clave}(fe={fe(n)})"); preorden(n.izq,s);preorden(n.der,s)

def ver(titulo,raiz):
    s=[]; preorden(raiz,s)
    t=[]; inorden(raiz,t)
    print(f"{titulo:22s} preorden: {''.join(s)}")
    print(f"{'':22s} inorden: {t} altura={alt(raiz)}")

def leerclaves(n):
    raiz = None
    for _ in range(n):
        clave = int(input("Ingrese la clave del nodo: "))
        raiz = insertar(raiz, clave)
    return raiz

def tipo_rotacion(n):
    if fe(n) == 2:
        if fe(n.izq) < 0:
            return "RL"
        return "LL"
    if fe(n) == -2:
        if fe(n.der) > 0:
            return "LR"
        return "RR"
    return "Balanceado"


print("Arbol sin Balancear ")
n = int(input("Ingrese el número de nodos: "))
raiz = leerclaves(n)
ver("Árbol AVL", raiz)
print(f"Tipo de rotación: {tipo_rotacion(raiz)}")
