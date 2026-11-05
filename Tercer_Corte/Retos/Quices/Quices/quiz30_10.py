#Reto: Rotacion Manual Escriba un pequeño programa que lea por teclado tres claves en el orden en que se insertarían, 
# construya el árbol SIN balancear, diagnostique cuál de los cuatro casos es (o si está equilibrado) y aplique la rotación correcta. 
# Debe imprimir el árbol antes y después. Pista: El diagnóstico sale de dos números: el fe del nodo y el fe de su hijo del lado pesado.
#  No necesita más.
#  Resultado esperado: Con 30, 10, 20 debe diagnosticar LR. Con 10, 20, 30 debe diagnosticar RR. Con 10, 30, 20 debe diagnosticar RL.
class Nodo:
    def __init__(self, c):
        self.clave = c
        self.izq = None
        self.der = None
        self.alt = 0
        self.fe = 0
def Insertar(raiz, clave):
    if raiz is None:
        return Nodo(clave)
    if clave < raiz.clave:
        raiz.izq = Insertar(raiz.izq, clave)
    else:
        raiz.der = Insertar(raiz.der, clave)
    return raiz

def Altura(nodo):
    if nodo is None:
        return -1
    return nodo.alt

def ActualizarAlturaYFE(nodo):
    if nodo is None:
        return
    nodo.alt = max(Altura(nodo.izq), Altura(nodo.der)) + 1
    nodo.fe = Altura(nodo.izq) - Altura(nodo.der)

def RotacionIzquierda(z):
    y = z.der
    T2 = y.izq
    y.izq = z
    z.der = T2
    ActualizarAlturaYFE(z)
    ActualizarAlturaYFE(y)
    return y

def RotacionDerecha(z):
    y = z.izq
    T3 = y.der
    y.der = z
    z.izq = T3
    ActualizarAlturaYFE(z)
    ActualizarAlturaYFE(y)
    return y
def imprimirarbol(raiz, nivel=0):
    if raiz is not None:
        imprimirarbol(raiz.der, nivel + 1)
        print(' ' * 4 * nivel + '->', raiz.clave)
        imprimirarbol(raiz.izq, nivel + 1)
def DiagnosticarCaso(raiz):
    if raiz is None:
        return "Arbol vacio"
    ActualizarAlturaYFE(raiz)
    if raiz.fe == 0:
        return "Equilibrado"
    if raiz.fe > 1:
        if raiz.izq.fe >= 0:
            return "LL"
        else:
            return "LR"
    if raiz.fe < -1:
        if raiz.der.fe <= 0:
            return "RR"
        else:
            return "RL"
    return "Equilibrado"
print("Ingrese las claves:")
x = int(input("Clave 1: "))
y = int(input("Clave 2: "))
z = int(input("Clave 3: "))

raiz = None
raiz = Insertar(raiz, x)
raiz = Insertar(raiz, y)
raiz = Insertar(raiz, z)

print("Arbol antes de la rotacion:")
imprimirarbol(raiz)
caso = DiagnosticarCaso(raiz)
print("Caso diagnostico:", caso)
if caso == "LL":
    raiz = RotacionDerecha(raiz)
elif caso == "RR":
    raiz = RotacionIzquierda(raiz)
elif caso == "LR":
    raiz.izq = RotacionIzquierda(raiz.izq)
    raiz = RotacionDerecha(raiz)
elif caso == "RL":
    raiz.der = RotacionDerecha(raiz.der)
    raiz = RotacionIzquierda(raiz)

print("Arbol despues de la rotacion:")
imprimirarbol(raiz)