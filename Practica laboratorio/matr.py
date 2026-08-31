# ==========================================
# 1. DEFINICIÓN DE DATOS (MATRIZ)
# ==========================================
# Creamos una lista de listas (matriz de 4 filas x 6 columnas)
# Cada fila representa un Punto de Acopio (0 a 3)
# Cada columna representa un Día de la semana (0 a 5)
recoleccion = [
    [120.5, 80.0,   0.0, 150.2, 200.0, 90.5],  # Fila 0: Punto 1
    [ 95.0, 110.0, 85.5,   0.0, 130.0, 75.0],  # Fila 1: Punto 2
    [  0.0, 140.0, 160.0, 175.5, 210.0,  0.0],  # Fila 2: Punto 3
    [100.0,  90.0, 105.0,  80.0, 120.0, 60.0]   # Fila 3: Punto 4
]

# ==========================================
# 2. PREPARACIÓN DE VARIABLES
# ==========================================
# Lista de 4 ceros para acumular la suma de cada punto
total_puntos = [0.0, 0.0, 0.0, 0.0]

# Lista de 6 ceros para acumular la suma de cada día
total_dias = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

# Contador para registrar cuántas casillas valen 0.0
dias_sin_operacion = 0


# ==========================================
# 3. RECORRIDO DE LA MATRIZ (SUMAR Y CONTAR)
# ==========================================
# Recorremos las filas (i va de 0 a 3)
for i in range(4):
    
    # Recorremos las columnas (j va de 0 a 5)
    for j in range(6):
        
        # Extraemos el peso en la posición actual
        peso = recoleccion[i][j]
        
        # Sumamos el peso al acumulador de ese punto (fila i)
        total_puntos[i] = total_puntos[i] + peso
        
        # Sumamos el peso al acumulador de ese día (columna j)
        total_dias[j] = total_dias[j] + peso
        
        # Evaluamos si el punto no operó en ese día
        if peso == 0.0:
            dias_sin_operacion = dias_sin_operacion + 1


# ==========================================
# 4. BÚSQUEDA DEL MÁXIMO (Punto más productivo)
# ==========================================
# Asumimos que el primer punto (índice 0) tiene el valor más alto
max_punto = total_puntos[0]
pos_max_punto = 0

# Comparamos contra los puntos restantes (del 1 al 3)
for i in range(1, 4):
    # Si encontramos un valor mayor, actualizamos nuestro máximo
    if total_puntos[i] > max_punto:
        max_punto = total_puntos[i]
        pos_max_punto = i  # Guardamos la posición del nuevo máximo


# ==========================================
# 5. BÚSQUEDA DEL MÍNIMO (Día de menor recolección)
# ==========================================
# Asumimos que el primer día (índice 0) tiene el valor más bajo
min_dia = total_dias[0]
pos_min_dia = 0

# Comparamos contra los días restantes (del 1 al 5)
for j in range(1, 6):
    # Si encontramos un valor menor, actualizamos nuestro mínimo
    if total_dias[j] < min_dia:
        min_dia = total_dias[j]
        pos_min_dia = j  # Guardamos la posición del nuevo mínimo


# ==========================================
# 6. IMPRESIÓN DEL INFORME
# ==========================================
print("=== INFORME DE RECICLAJE COMUNITARIO ===")

# Mostramos el total de cada punto (sumamos +1 al índice para mostrar 'Punto 1' en vez de 'Punto 0')
print("\nTotal por punto de acopio:")
for i in range(4):
    print("Punto", i + 1, ":", total_puntos[i], "kg")

# Mostramos el total de cada día
print("\nTotal por dia:")
for j in range(6):
    print("Dia", j + 1, ":", total_dias[j], "kg")

# Mostramos los resultados finales calculados
print("\nPunto mas productivo: Punto", pos_max_punto + 1, "con", max_punto, "kg")
print("Dia de menor recoleccion: Dia", pos_min_dia + 1, "con", min_dia, "kg")
print("Registros sin operacion (0 kg):", dias_sin_operacion)