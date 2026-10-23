# ============================================================
#  Prueba corta · Segundo corte · EJERCICIO 1  (25 puntos)
#  Tema: recursion y exploracion de caminos
#  Sistema: TurnoJusto — calculo de rutas de atencion
#
#  NO MODIFIQUE el archivo pruebas_e1.py
#  Ejecute:   python3 pruebas_e1.py
# ============================================================


def suma_impares(n):
    """Devuelve la suma de todos los numeros impares desde 1 hasta n (incluido).
       Ejemplos:  suma_impares(5) -> 9     (1 + 3 + 5)
                  suma_impares(0) -> 0     (no hay impares)

       DEFECTO REPORTADO: con ciertas entradas el programa se cae.
       Revise el caso base."""
    if n == 1:
        return 1
    if n == 0: # en este apartado se maneja el caso base para n igual a 0 ya que if no se coloca el codigo falla y su
# entrada no ira a recursion ademas debemos retornar 0 ya que ya que hay demaciadsos numeros menores o iguales a 0 y
# el codigo no acabaria por lo que se genersa esa salida
        return 0
    if n % 2 == 0:
        return suma_impares(n - 1)
    return n + suma_impares(n - 1)

def contar_caminos(f, c):
    """Devuelve cuantos caminos distintos hay desde la casilla superior
       izquierda hasta la inferior derecha de una cuadricula de f filas
       por c columnas, avanzando solo a la DERECHA o hacia ABAJO.

       Ejemplo: contar_caminos(3, 3) -> 6

       PENDIENTE: implementar. Debe ser recursiva: no use ciclos ni listas."""
    if f == 1 or c == 1: # uso el caso base el cual si es una cuadricula de 1x1 no habran mas que un solo camino posible
        return 1
    return contar_caminos(f - 1, c) + contar_caminos(f, c - 1) #depende del caso base ya que usamos backtracking para explorar 
#todos los caminos posibles por lo cual si se digitan los diferentes valores de fyc se forma la "cuadricula la cual 
# representa todos los caminos posibles"
# ademas llamamos la funcion para que se ejecute y nos devuelva el numero de caminos posibles en la cuadricula especificada y se 
#restan las filas o columnas según corresponda para explorar todos los caminos posibles y se suman las funciones 