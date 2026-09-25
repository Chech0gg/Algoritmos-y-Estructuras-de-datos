#for i in range(n):
# for j in range (i):
#es O(n^2) porq la segunda funcion del ciclo recorre la misma funcion n solo que una vez menos, a las 2 depender de n se convierte en O(n^2)

#for i in range(n):
#    j = n
#    while j > 1:
#        j = j//2
#es O(n log n) porq el ciclo interno reduce j a la mitad en cada iteracion, y el ciclo externo depende de n.
def insertion_sort_por_edad(personas):
    for i in range(1, len(personas)):
        actual = personas[i]
        j = i - 1
        while j >= 0 and personas[j]["edad"] > actual["edad"]:
            personas[j + 1] = personas[j]
            j -= 1
        personas[j + 1] = actual
# en la secuencia de la lista de personas con su edad se puede determinar la complejidad de recorrerla, que sería O(n) ya que se necesita visitar cada elemento una vez.
# pero si utlizo el insert sort para ordenar la lista, la complejidad eo sería O(n^2) ya que cada inserción puede requerir desplazar todos los elementos anteriores. por lo que se demoraria mucho mas lal realizar el proceso pero seria la manera 
# la funcion insertion_sort_por_edad tiene una complejidad de O(n^2) ya que el for para recorrer la lista el cual son las personas y un while para comparacion con la edad de la persona actual, el while para desplazar los elementos anteriores pueden llegar a ejecutarse n veces cada uno en el peor de los casos.
# En resumen, recorrer la lista tiene complejidad O(n) ya que no se modifica y se visita cada elemento una vez, mientras que ordenar la lista con insertion sort tiene complejidad O(n^2)
