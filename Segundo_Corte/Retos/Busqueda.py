def binaria_recursiva(v, x, izq=0, der=None):
    if der is None:
        der = len(v) - 1

    # Si los límites se cruzan, no se encontró el elemento.
    # 'izq' indica exactamente dónde debería insertarse para mantener el orden.
    if izq > der:
        return izq

    medio = (izq + der) // 2

    # Si el valor del medio es mayor o igual a x, seguimos buscando hacia la izquierda
    # para asegurar que encontramos la primera aparición de los repetidos.
    if v[medio] >= x:
        resultado = binaria_recursiva(v, x, izq, medio - 1)
        if v[medio] == x:
            return medio if resultado == -1 or v[resultado] != x else resultado
        return resultado
    else:
        return binaria_recursiva(v, x, medio + 1, der)


# Ejemplo de uso
v = [1, 3, 3, 3, 5, 7, 44, 53, 99]

# 1. Buscar un elemento repetido (debe devolver el primer índice, que es 1)
print("Buscar 3 (repetido):", binaria_recursiva(v, 3))

# 2. Buscar un elemento que no está (ej: 6, debería ir en el índice 5, antes del 7)
print("Buscar 6 (no está, posición de inserción):", binaria_recursiva(v, 6))