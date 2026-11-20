# ============================================================
#  analisis.py · CASO B · PARTE F del parcial  (10 puntos)
#  PrestaLab — Prestamo de equipos de laboratorio
#
#  VERIFICACION CRUZADA
#  Esta es la MISMA logica de Sistema::mejorSeleccion, escrita en el otro
#  lenguaje. El verificador compara los dos resultados: si no coinciden,
#  uno de los dos esta mal y el parcial no cierra.
#
#  MODIFIQUE SOLO ESTE ARCHIVO.  NO TOQUE pruebas.py
# ============================================================


def mejor_seleccion(codigos, pesos, valores, capacidad):
    """Devuelve la lista ORDENADA de codigos de la seleccion de mayor
       valor total que no pasa de 'capacidad'.

       codigos[i], pesos[i] y valores[i] describen el mismo punto.
       Cada punto se lleva o no se lleva. Si hay empate en valor, la
       seleccion con MENOS puntos.

       Debe dar exactamente el mismo resultado que la version en C++.

       PENDIENTE: implementar con recursion de tomar / no tomar y poda."""
pass

def mejor_seleccion_(codigos, pesos, valores, capacidad):
    def rec(i, capacidad_restante):
        if i == len(codigos):
            return 0, []
        if pesos[i] > capacidad_restante:
            return rec(i + 1, capacidad_restante)
        tomar_valor, tomar_lista = rec(i + 1, capacidad_restante - pesos[i])
        tomar_valor += valores[i]
        no_tomar_valor, no_tomar_lista = rec(i + 1, capacidad_restante)
        if tomar_valor > no_tomar_valor or (tomar_valor == no_tomar_valor and len(tomar_lista) < len(no_tomar_lista)):
            return tomar_valor, [codigos[i]] + tomar_lista
        return no_tomar_valor, no_tomar_lista

    _, seleccion = rec(0, capacidad)
    return seleccion

