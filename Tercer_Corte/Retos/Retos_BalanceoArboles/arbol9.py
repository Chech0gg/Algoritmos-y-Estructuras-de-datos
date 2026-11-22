#¿Cuándo NO alcanza una rotación? (reto corchador) · Obligatorio Construya un árbol donde,
#después de aplicar la rotación correcta en el nodo desbalanceado más profundo, QUEDE otro
#nodo desbalanceado más arriba. ¿Es posible en una inserción? ¿Y en una eliminación? 
#Pista: En inserción, una sola rotación siempre basta y eso se puede demostrar mirando cómo 
#cambia la altura del subárbol. En eliminación no: la altura puede reducirse y propagar el problema hacia la raíz.
class Nodo:
    def __init__(self, clave, izq=None, der=None):
        self.clave = clave
        self.izq = izq
        self.der = der


def altura(nodo):
    if nodo is None:
        return -1
    a = altura(nodo.izq)
    b = altura(nodo.der)
    return 1 + (a if a > b else b)

def fe(nodo):
    if nodo is None:
        return 0
    return altura(nodo.izq) - altura(nodo.der)
def rotar_izq(x):
    y = x.der
    t2 = y.izq
    y.izq = x
    x.der = t2
    return y
def rotar_der(y):
    x = y.izq
    t2 = x.der
    x.der = y
    y.izq = t2
    return x
def rebalancear_nodo(nodo, estado):
    estado["roto"] = False
    if nodo is None:
        return None

    balance = fe(nodo)
    if balance > 1:
        estado["roto"] = True
        if fe(nodo.izq) < 0:
            nodo.izq = rotar_izq(nodo.izq)
        return rotar_der(nodo)

    if balance < -1:
        estado["roto"] = True
        if fe(nodo.der) > 0:
            nodo.der = rotar_der(nodo.der)
        return rotar_izq(nodo)

    return nodo
def eliminar_solo_primera_rotacion(raiz, clave, estado):
    if raiz is None:
        return None

    if clave < raiz.clave:
        raiz.izq = eliminar_solo_primera_rotacion(raiz.izq, clave, estado)
    elif clave > raiz.clave:
        raiz.der = eliminar_solo_primera_rotacion(raiz.der, clave, estado)
    else:
        if raiz.izq is None:
            return raiz.der
        if raiz.der is None:
            return raiz.izq

        suc = raiz.der
        while suc.izq is not None:
            suc = suc.izq
        raiz.clave = suc.clave
        raiz.der = eliminar_solo_primera_rotacion(raiz.der, suc.clave, estado)

    if not estado["ya_roto"]:
        rebalancear_estado = {"roto": False}
        raiz = rebalancear_nodo(raiz, rebalancear_estado)
        if rebalancear_estado["roto"]:
            estado["ya_roto"] = True
            print(
                f"Rotación aplicada en nodo con clave {raiz.clave} "
                f"(nueva altura de este subárbol: {altura(raiz)})"
            )

    return raiz
def mostrar_fe(nodo):
    if nodo is None:
        return
    print(f"Nodo {nodo.clave} -> alt={altura(nodo)}, FE={fe(nodo)}")
    mostrar_fe(nodo.izq)
    mostrar_fe(nodo.der)

raiz = Nodo(40)
raiz.izq = Nodo(20)
raiz.izq.izq = Nodo(10)
raiz.izq.izq.izq = Nodo(5)

raiz.der = Nodo(60)
raiz.der.izq = Nodo(50)
raiz.der.der = Nodo(80)
raiz.der.der.der = Nodo(90)

estado = {"ya_roto": False}
raiz = eliminar_solo_primera_rotacion(raiz, 50, estado)

print("\nEstado tras aplicar SOLO la primera rotación:")
mostrar_fe(raiz)