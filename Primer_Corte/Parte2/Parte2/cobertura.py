# ============================================================
#  Cívica Software  ·  TCK-5510  ·  Severidad P3
#  Sistema: RedAcopio  —  Mapa de cobertura de rutas
#  NO MODIFIQUE la matriz de datos ni el archivo de pruebas.
# ============================================================

# filas = rutas del camion, columnas = zonas del barrio
# cada celda = kilos recogidos por esa ruta en esa zona
cobertura = [
    [5, 0, 3, 0, 2, 4, 0],
    [0, 0, 7, 0, 1, 0, 6],
    [2, 0, 0, 0, 4, 3, 1],
    [0, 0, 5, 0, 0, 8, 2],
]
def total_por_ruta(m):
    """Devuelve una lista con el total recogido por cada ruta (fila)."""
    totales = []
    for fila in m:
        s = 0
        for v in fila:
            s += v
        totales.append(s)
    return totales


def cobertura_por_zona(m):
    """Devuelve una lista con el total recogido en cada zona (columna).
       BUG REPORTADO: la ultima zona nunca aparece en el informe."""
    totales = []
    for j in range(len(m[0])):          # <-- revise este limite
        s = 0
        for i in range(len(m)):
            s += m[i][j]
        totales.append(s)
    return totales


def ruta_mas_productiva(m):
    """Devuelve el INDICE de la ruta que mas kilos recogio en total.
       PENDIENTE: implementar."""
    maximo = m[0][0]
    ruta = 0
    for i in range(len(m)):
        for j in range(len(m[0])):
            if m[i][j] > maximo:
                  maximo = m[i][j]
                  ruta = i
    return ruta


def zonas_sin_cubrir(m):
    """Devuelve cuantas zonas (columnas) quedaron COMPLETAMENTE en cero,
       es decir, ninguna ruta recogio nada alli.
       PENDIENTE: implementar."""
    count = 0
    for j in range(len(m[0])):
        if all(m[i][j] == 0 for i in range(len(m))):
            count += 1
    return count

print("Totales por ruta:", total_por_ruta(cobertura))
print("Totales por zona:", cobertura_por_zona(cobertura))
print ("el dia con mas cobertura fue la ruta:", ruta_mas_productiva(cobertura))
print ("zonas sin cubrir:", zonas_sin_cubrir(cobertura))

# en la parte de totales por zona cambie la condicion de el rango de las columnas ,
# ya que len[m[0]]-1 no imprimia la ultima columna y no cumpliria la condicion
# y creamos s para guardar el registro y un . append para añadir al arrray 
# para el maximo cree la matriz luego recorri todas las opciones de la matriz para encontrar el maximo de la 
# la ruta mas congestionada se verifica el mayor y se compara con el maximo ya guardado
# luego para definir las rutas sic cubrir cramos un contador de dias sin cubrir 
# realizamos unreccorrido de todas las columnas y si las filas de esa columna eraan 0 añadiamos
# 1 al contador y el all verifica si es cirto o no lo que
# necesutamos reconocer que es un dia sin cubrir y
# recorrre todo el codigo utilizando la matriz evaluando fila,columna
