#
#Preguntas

#En una cola sobre lista enlazada, saco el último elemento. ¿Qué dos referencias tengo que actualizar y por qué?
#En una cola circular de capacidad cinco, el frente está en tres y hay cuatro elementos. ¿En qué posición se guarda el siguiente que encole?
#Quiero deshacer las últimas tres operaciones. ¿Pila o cola? ¿Por qué?
#Quiero atender por orden de llegada. ¿Pila o cola?

#1
#En una cola sobre lista enlazada, si saco el último elemento, tengo que actualizar la referencia al último nodo
# y la referencia al penúltimo nodo (el nuevo último nodo). Esto es necesario porque el último nodo ha sido eliminado 
# y la cola debe mantener correctamente la referencia al nuevo último nodo. por lo tanto debes actualizar
#  el frente y el final de la cola.
#Frente (inicio): el elemento que lleva más tiempo esperando. Es el siguiente que va a salir cuando desencoles.(primer elemento en la cola)
# Final: el último elemento que llegó. Detrás de él se coloca el próximo que encoles.

#2
#En una cola circular de capacidad cinco, si el frente está en tres y hay cuatro elementos, el siguiente que encole se guardará en la posición (3 + 4) % 5 = 2. Esto se debe a que en una cola circular, las posiciones se calculan usando el operador módulo para envolver alrededor del final del arreglo.

#3
#Deshacer las últimas tres operaciones: pila
#Una pila funciona como una torre de platos: el último que pones es el primero que sacas. Al deshacer, siempre quieres revertir
#  lo más reciente primero. Si guardas las operaciones en una pila, sacar tres veces te da justo las últimas tres, de la más
# nueva a la más vieja. Con una cola saldría primero la operación más antigua, que es lo contrario de lo que necesitas.

#4. Atender por orden de llegada: cola
#Una cola funciona como la fila de un banco: el primero que llega es el primero que se atiende. Los nuevos se ponen al final
#  y se atiende desde el frente, así nadie se salta a nadie. Con una pila atenderías primero al último que llegó, lo cual 
# sería injusto para quienes llevan más tiempo esperando.

capacidad = 5
cola = [None] * capacidad   # 5 posiciones vacías
frente = 3
cantidad = 4

# Los 4 elementos que ya están ocupan las posiciones 3, 4, 0 y 1
cola[3] = "A"   # el primero en la fila (el frente)
cola[4] = "B"
cola[0] = "C"   # aquí ya dio la vuelta
cola[1] = "D"

# ¿Dónde va el siguiente?
siguiente = (frente + cantidad) % capacidad
print(siguiente)            # 2

cola[siguiente] = "E"       # encolamos
cantidad += 1
print(cola)