#la pila monotonica la entendi como una forma de tener un orden en una lista , ya la pila cumple una fucion la de mantener un orden especifico mientras se agregan o eliminan elementos ahora este ejercicio guarda os indices de endonde se produce un dia mas caluroso 
#-- Pila Monotonica Temperaturas diarias Para cada día, calculamos cuántos días hay que esperar hasta que haga más calor. Es el mismo patrón del ejemplo 1, pero la respuesta es una distancia en lugar de un valor.
#Entrada: [73, 74, 75, 71, 69, 72, 76, 73] Salida: [1, 1, 4, 2, 1, 1, 0, 0]
v = [73, 74, 75, 71, 69, 72, 76, 73]
def temp(v): # defini la funcion para poder resokver el problema de las temperaturas diarias
    n = len(v) # obtenemos la cantidad de dias de la lista de temperaturas con len()
    res = [0] * n #Inicializa todas las respuestas en cero
    pila = [] #creamos la pila para almacenar los indices de los dias mientras buscamos un dia mas caluroso
    for i in range(n):
        while pila and v[i] > v[pila[-1]]:
            indice = pila.pop() 
            res[indice] = i - indice # Calcula la diferencia de días entre el día actual y el día almacenado en la pila
        pila.append(i)
    return res # Devuelve la lista con la cantidad de días que hay que esperar para un día más caluroso
print(temp(v))