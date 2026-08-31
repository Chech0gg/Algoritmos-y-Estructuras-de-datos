# 1. CREACIÓN DEL ARREGLO CON ALIASING (PROBLEMA DE COPIA POR REFERENCIA)
# [0] * 2 crea la lista [0, 0].
# Al multiplicar esa lista por 2 (* 2), Python NO crea dos filas independientes.
# En su lugar, crea una lista que contiene DOS REFERENCIAS a la MISMA lista [0, 0] en memoria.
m = [[0] * 2] * 2

# 2. MODIFICACIÓN DE UN ELEMENTO
# Como la fila 0 (m[0]) y la fila 1 (m[1]) apuntan a la misma ubicación en memoria,
# cambiar el valor de m[0][0] a 7 también altera a m[1][0].
m[0][0] = 7

# 3. IMPRESIÓN DEL RESULTADO
# Imprime [[7, 0], [7, 0]] porque ambas filas son, en realidad, el mismo objeto.
print(m)