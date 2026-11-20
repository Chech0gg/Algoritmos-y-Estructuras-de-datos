#Rotacion Manual Escriba un pequeño programa que lea por teclado tres claves en el orden en que se insertarían,
#construya el árbol SIN balancear, diagnostique cuál de los cuatro casos es (o si está equilibrado) y 
#aplique la rotación correcta. Debe imprimir el árbol antes y después. Pista: El diagnóstico sale de dos números:
#el fe del nodo y el fe de su hijo del lado pesado. No necesita más. 
#Resultado esperado: Con 30, 10, 20 debe diagnosticar LR. Con 10, 20, 30 debe diagnosticar RR. Con 10, 30, 20 debe diagnosticar RL.
class Nodo:
    def __init__(self, clave, izq=None, der=None):
        self.clave = clave
        self.izq = izq
        self.der = der


def insertar_abb(nodo, clave):
    if nodo is None:
        return Nodo(clave)
    if clave < nodo.clave:
        nodo.izq = insertar_abb(nodo.izq, clave)
    elif clave > nodo.clave:
        nodo.der = insertar_abb(nodo.der, clave)
    return nodo


def altura(nodo):
    if nodo is None:
        return 0
    return 1 + max(altura(nodo.izq), altura(nodo.der))


def factor_equilibrio(nodo):
    if nodo is None:
        return 0
    return altura(nodo.izq) - altura(nodo.der)


def rotar_derecha(y):
    x = y.izq
    t2 = x.der
    x.der = y
    y.izq = t2
    return x


def rotar_izquierda(x):
    y = x.der
    t2 = y.izq
    y.izq = x
    x.der = t2
    return y


def imprimir_arbol(nodo, nivel=0, rama="Raíz"):
    if nodo is None:
        return
    print("    " * nivel + f"{rama}: {nodo.clave} (FE={factor_equilibrio(nodo)})")
    imprimir_arbol(nodo.izq, nivel + 1, "I")
    imprimir_arbol(nodo.der, nivel + 1, "D")


def balancear_si_necesario(raiz):
    if raiz is None:
        return None

    fe = factor_equilibrio(raiz)

    if fe > 1:
        fe_hijo = factor_equilibrio(raiz.izq)
        print(f"Diagnóstico: FE(nodo)={fe}, FE(izq)={fe_hijo} -> ", end="")
        if fe_hijo >= 0:
            print("LL (Rotación simple a la derecha)")
            return rotar_derecha(raiz)
        else:
            print("LR (Rotación izquierda en hijo izq + rotación derecha en nodo)")
            raiz.izq = rotar_izquierda(raiz.izq)
            return rotar_derecha(raiz)

    if fe < -1:
        fe_hijo = factor_equilibrio(raiz.der)
        print(f"Diagnóstico: FE(nodo)={fe}, FE(der)={fe_hijo} -> ", end="")
        if fe_hijo <= 0:
            print("RR (Rotación simple a la izquierda)")
            return rotar_izquierda(raiz)
        else:
            print("RL (Rotación derecha en hijo der + rotación izquierda en nodo)")
            raiz.der = rotar_derecha(raiz.der)
            return rotar_izquierda(raiz)

    print(f"Diagnóstico: FE(nodo)={fe} -> Equilibrado (sin rotación)")
    return raiz


entrada = input("Ingrese tres claves separadas por espacio: ").split()
if len(entrada) == 3:
    claves = [int(x) for x in entrada]

    raiz = None
    for c in claves:
        raiz = insertar_abb(raiz, c)

    print("\n--- Árbol ANTES ---")
    imprimir_arbol(raiz)

    print()
    raiz = balancear_si_necesario(raiz)

    print("\n--- Árbol DESPUÉS ---")
    imprimir_arbol(raiz)
else:
    print("Debe ingresar exactamente tres claves.")