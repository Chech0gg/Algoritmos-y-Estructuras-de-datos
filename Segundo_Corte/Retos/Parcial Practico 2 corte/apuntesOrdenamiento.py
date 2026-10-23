#Extra C-1 (medio). Aplica Selección al arreglo [42, 17, 93, 8, 55, 31]. Muestra el arreglo tras
#cada pasada y compara con los costos de Inserción.
#Solución. Pasada 1: mínimo de todo = 8 (posición 3), se intercambia con la posición 0 → [8,
#17, 93, 42, 55, 31]. Pasada 2: el mínimo del resto es 17, ya está en su lugar → igual. Pasada 3:
#mínimo del resto = 31 (posición 5), se intercambia con 93 → [8, 17, 31, 42, 55, 93]. Pasada 4:
#42 ya está bien. Pasada 5: 55 ya está bien. Listo. Comparaciones: siempre 5 + 4 + 3 + 2 + 1 =
#15, sin importar los datos. Intercambios reales: 2. Inserción hizo 11 comparaciones y 8
#desplazamientos con el mismo arreglo: Inserción se adapta a los datos, Selección no.
#Extra C-2 (medio). ¿Cuántas comparaciones hace Inserción con [1, 2, 3, 4, 5, 6] y con [6, 5,
#4, 3, 2, 1]?
#Solución. Ordenado: en cada pasada hay una sola comparación y es falsa → n - 1 = 5. En
#orden inverso: la pasada i compara con los i elementos anteriores, todos mayores → 1 + 2 +
#3 + 4 + 5 = n(n-1)/2 = 15. Es la diferencia entre el mejor caso O(n) y el peor O(n²).
#Extra C-3 (difícil). Partición de Quick Sort (esquema de Lomuto, pivote = último
#elemento) sobre [8, 3, 7, 1, 5]. Muestra el arreglo y el índice que devuelve.
#Guía de estudio - Algoritmos y Estructura de Datos (Segundo corte)
#Page 13 of 31
#def particionar(v, lo, hi):
#    pivote = v[hi]
#    i = lo - 1
#    for j in range(lo, hi):
#        if v[j] <= pivote:
#            i += 1
#            v[i], v[j] = v[j], v[i]
#    v[i + 1], v[hi] = v[hi], v[i + 1]
#    return i + 1
##Solución. Pivote = 5, i = -1. j = 0: 8 no es <= 5. j = 1: 3 <= 5 → i = 0, intercambia v[0] y v[1] → [3,
#8, 7, 1, 5]. j = 2: 7 no. j = 3: 1 <= 5 → i = 1, intercambia v[1] y v[3] → [3, 1, 7, 8, 5]. Fin del ciclo: se
#intercambia v[i+1] = v[2] con el pivote → [3, 1, 5, 8, 7], devuelve 2. El 5 queda en su posición
#final; a su izquierda todo es menor (3, 1) y a su derecha todo es mayor (8, 7). Luego se
#repite sobre [3, 1] y [8, 7].
#Extra C-4 (medio). Traza Merge Sort sobre [38, 27, 43, 3, 9, 82, 10].
#Solución. División: [38, 27, 43, 3] y [9, 82, 10] → [38, 27], [43, 3], [9], [82, 10] → hojas de un
#elemento. Fusiones hacia arriba: [38, 27] → [27, 38]; [43, 3] → [3, 43]; [82, 10] → [10, 82]; [9]
#10, 82] → [3, 9, 10, 27, 38, 43, 82]. Son 3 niveles de división (⌈log₂ 7⌉ = 3), y en cada nivel se
#procesan los 7 elementos.
