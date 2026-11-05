def rotarDerecha(y):
    x = y.izq
    B = x.der
    x.der = y            # 1) y pasa a ser hijo derecho de x
    y.izq = B            # 2) B se cuelga de y
    recalc(y); recalc(x) # 3) primero el que BAJA, luego el que SUBE
    return x             # x es la nueva raiz del subarbol
 
def rotarIzquierda(x):
    y = x.der
    B = y.izq
    y.izq = x
    x.der = B
    recalc(x); recalc(y)
    return y