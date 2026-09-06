# ============================================================
#  Cívica Software  ·  TCK-4420  ·  Severidad P3
#  Sistema: RedAcopio  —  Reporte de ocupación
#  NO MODIFIQUE la seccion de datos ni el archivo de pruebas.
# ============================================================

# filas = puntos de acopio, columnas = dias de la semana
ocupacion = [
    [4, 2, 6, 1, 3, 0],
    [0, 5, 5, 2, 7, 1],
    [8, 1, 0, 4, 2, 6],
    [3, 3, 3, 0, 0, 5],
]


def total_por_punto(m):
    """Devuelve una lista con el total recogido por cada punto (fila)."""
    totales = []
    for fila in m:
        s = 0
        for v in fila:
            s += v
        totales.append(s)
    return totales


def total_por_dia(m):
    """Devuelve una lista con el total recogido cada dia (columna).
       BUG REPORTADO: entrega totales incorrectos."""
    totales = []
    for j in range(len(m[0])):         #se cambian las filas por columnas para que se ejecute correctamente el proceso, ademas que se cambio el rango para que desde el primer elemeento sea validada la operacion

        s = 0
        for i in range(len(m)):        #el rango de la matriz se cambio para que pueda pasar por todas listas  
            s += m[i][j]                # se crea el array que tenga la suma por dia rrecoriendo de i siendo estas las filas para saber siu total
        totales.append(s)               # se usa metodo .append para añadir los elementos al vector
    return totales


def dia_mas_flojo(m):
    """Devuelve el indice del dia con MENOR recoleccion total.
       PENDIENTE: implementar."""
    minimo = float("inf")  # Inicializar con infinito para que no nos copile el error al ejecutar el for con el minimo
    dia_minimo = 0
    for j in range(len(m[0])): #realizamos un bucle para recorrer las columnas de la matriz
        s = 0
        for i in range(len(m)):# realizamos un bucle para recorrer las filas de la matriz
            s += m[i][j]
        if s < minimo:  #sacamos el minimo con ayuda de la variable s que pasa por toda matriz y encontramos el dia menos congestionao
            minimo = s          #se encuentra cual es la columna menos congestionada 
            dia_minimo = j      #recorremos la mariz para hallar este dia con la suma de cada dia y se verifica cual es 
    return dia_minimo


def puntos_inactivos(m):
    """Devuelve cuántos registros están en 0 (el punto no operó ese día)."""
    total_puntosin = 0   # se inicializa un contador para que añada las variables
    for i in range(len(m)):   # se recorren la filas y colunmas con un ciclo for
        for j in range(len(m[0])): 
            if m[i][j] == 0:           # si la mariz es equivalente a 0 se añade 1 para la suma de total de puntos inactivos
                total_puntosin += 1
    return total_puntosin



print("El total de cada punto es:", total_por_punto(ocupacion))
print("El total de cada día es:", total_por_dia(ocupacion))
print("El dia mas flojo es:", dia_mas_flojo(ocupacion))
print("Puntos inactivos:", puntos_inactivos(ocupacion))