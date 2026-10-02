#Pila monotionica 
#TEMPERATURA
#calculamos cunatos días hasta que la temperatura sea mayor
 
#entrada [73,74,75,71,69,72,76,73]
#salida [1,1,4,2,1,1,0,0]
def dias_temp(arr):
    pila = []
    n = len (arr)
    res = [0] * n
    for i in range(len(arr)):
        while pila and arr[pila[-1]] < arr[i]:
            res[pila.pop()] = i - pila[-1] if pila else 0
        pila.append(i)
    return res
print(dias_temp([73,74,75,71,69,72,76,73]))