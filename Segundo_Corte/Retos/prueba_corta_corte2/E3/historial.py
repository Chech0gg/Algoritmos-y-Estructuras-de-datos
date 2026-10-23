# ============================================================
#  Prueba corta · Segundo corte · EJERCICIO 3  (25 puntos)
#  Tema: pilas
#  Sistema: PrestaLab — historial de acciones del operador
#
#  NO MODIFIQUE el archivo pruebas_e3.py
#  Ejecute:   python3 pruebas_e3.py
# ============================================================


def historial_final(acciones):
    """Recibe una lista de cadenas. Cada cadena distinta de "DESHACER"
       se agrega al historial. La cadena "DESHACER" retira la ultima
       accion registrada; si el historial esta vacio, se IGNORA sin error.

       Devuelve el historial resultante como lista, de la accion mas
       antigua a la mas reciente.

       DEFECTO REPORTADO: el programa se cae cuando llega un "DESHACER"
       y el historial esta vacio."""
    pila = []
    for a in acciones:
        if a == "DESHACER" and pila != []: #inclui como referencia cuando al lista este vacia y cuando sea diferente de vacia  
            # es decir solo se encuentra "Deshacer" , esot realiza la misma funcion solo que el codigo identifica el 
            #defecto reportado se evita al verificar que la pila no este vacia antes de hacer pop por lo cual si esta vacia con 
            #continue el codigo seguira ejecutando la funcion solo que no se hace pop si la pila esta vacia
            pila.pop()
        elif a == "DESHACER" and pila == []:            # <-- revise
            continue
        else:
            pila.append(a)
    return pila


def profundidad_maxima(acciones):
    """Devuelve el mayor numero de acciones que el historial llego a
       tener en algun momento del recorrido.

       Ejemplo: ["a", "b", "DESHACER", "c"] -> 2
                (el historial llego a tener 2 elementos: a y b)

       PENDIENTE: implementar."""
    pila = []
    max_profundidad = 0
    for a in acciones:
        if a == "DESHACER" and pila != []:
            pila.pop()
        elif a == "DESHACER" and pila == []:
            continue
        else:
            pila.append(a) #utilize la misma  ejecucion de la parte anterios ya que tienen la misma funcionabilidad para cuando 
            # la lista no tenga elemento y solo este el deshacer, ya que en ese caso no se hace pop y se evita el error
            if len(pila) > max_profundidad: #recorremos la cantidad de elementos en la pila para actualizar la profundidad maxima
                # y  comparamos la longitud actual de la pila con el maximo registrado y actualizamos si es mayor asi cada vez 
                #hasta lograr el resultado esperaado
                max_profundidad = len(pila)
    return max_profundidad