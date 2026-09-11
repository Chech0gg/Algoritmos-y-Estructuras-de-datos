v = [1, 3, 3, 4, 5, 7, 44, 53, 99]
x = int(input("ingrese el numero a buscar: "))


def binaria(v, x, comparaciones=0):
    izq, der = 0, len(v) - 1
    while izq <= der:
        medio = (izq + der) // 2
        comparaciones += 1
        if v[medio] == x:
            return medio, comparaciones
        elif v[medio] < x:
            izq = medio + 1
        else:
            der = medio - 1
    return -1, comparaciones


def secuencial(v, x, comparaciones1=0):
    for i in range(len(v)):
        comparaciones1 += 1
        if v[i] == x:
            return i, comparaciones1
    return -1, comparaciones1


# Primero definimos v y x, luego llamamos a las funciones capturando ambos valores
indice_bin, comparaciones_binaria = binaria(v, x, 0)
indice_sec, comparaciones_secuencial = secuencial(v, x, 0)

print("el elemento", x, "se encuentra en el indice :", indice_bin)
print("el numero de comparaciones realizadas en la busqueda binaria es:", comparaciones_binaria)
print("el elemento", x, "se encuentra en el indice :", indice_sec)
print("el numero de comparaciones realizadas en la busqueda secuencial es:", comparaciones_secuencial)