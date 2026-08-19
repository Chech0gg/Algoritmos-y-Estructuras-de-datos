  
Matriz =[
    [4,6,1,5,2,5],
    [9,4,6,8,1,6],
    [3,5,7,2,8,3],
    [1,4,6,2,3,7],
    [5,7,9,1,4,8]]
maximo = Matriz[0][0]
minimo = Matriz[0][0]
filamax = 0
columna = 0
for fila in Matriz:
    for elemento in fila:
        if elemento > maximo:
            maximo = elemento
        if elemento < minimo:
            minimo = elemento

print(f"Franja mas conjestionada: {maximo}")
for fila in range(len(Matriz)):
    for columna in range(len(Matriz[fila])):
        if Matriz[fila][columna] == maximo:
            maximo == Matriz[fila][columna]
            filamax = fila
            columna = columna
print(f"el dia mas congestionado fue de : {maximo} personas y se encuentra en la fila {filamax} y columna {columna}")
for fila in range(len(Matriz)):
    for columna in range(len(Matriz[fila])):
        if Matriz[fila][columna] < 5:
            totall = Matriz[fila][columna]
            print(f"Dias menos congestionados: {totall} personas y se encuentra en la fila {fila} y columna {columna}")