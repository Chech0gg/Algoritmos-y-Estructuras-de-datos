def bubble_sort(arr):
    global intercambios, comparaciones
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            comparaciones += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                intercambios += 1
                swapped = True
        if not swapped:
            break
    return arr


def selection_sort(arr):
    global intercambios, comparaciones
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            comparaciones += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        if i != min_idx:
            intercambios += 1
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def insertion_sort(arr):
    global intercambios, comparaciones
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0:
            comparaciones += 1
            if arr[j] > key:
                arr[j + 1] = arr[j]
                intercambios += 1
                j -= 1
            else:
                break
        arr[j + 1] = key
    return arr


# Vector de prueba original
arr = [64, 25, 12, 22, 11, 90, 45, 33]

# 1. BUBBLE SORT
intercambios = 0
comparaciones = 0
print("'''''''''' BUBBLE SORT ''''''''''")
print("vector ordenado:", bubble_sort(arr))
print("intercambios:", intercambios)
print("comparaciones:", comparaciones)

intercambios = 0
comparaciones = 0
print("\n'''''''''' SELECTION SORT ''''''''''")
print("vector ordenado:", selection_sort(arr))
print("intercambios:", intercambios)
print("comparaciones:", comparaciones)

intercambios = 0
comparaciones = 0
print("'''''''''' INSERTION SORT ''''''''''")
print("vector ordenado:", insertion_sort(arr))
print("intercambios:", intercambios)
print("comparaciones:", comparaciones)



def partition(arr, low, high):
    pivot = arr[low]  # Elegimos el primer elemento como pivote
    i = low - 1
    j = high + 1

    while True:
        # Mover el índice izquierdo hacia la derecha
        i += 1
        while arr[i] < pivot:
            i += 1

        # Mover el índice derecho hacia la izquierda
        j -= 1
        while arr[j] > pivot:
            j -= 1

        # Si los índices se cruzan, terminamos esta partición
        if i >= j:
            return j

        # Si no se han cruzado, intercambiamos los elementos de lugar
        arr[i], arr[j] = arr[j], arr[i]

def quick_sort(arr, low, high):
    if low < high:
        # Particionamos el arreglo y obtenemos el punto medio
        pi = partition(arr, low, high)
        
        # Ordenamos la mitad izquierda
        quick_sort(arr, low, pi)
        # Ordenamos la mitad derecha
        quick_sort(arr, pi + 1, high)
    return arr

# --- Prueba rápida ---
mi_lista = [33, 11, 22, 90, 64]
print("Antes:", mi_lista)
quick_sort(mi_lista, 0, len(mi_lista) - 1)
print("Después (ordenado en el mismo sitio):", mi_lista)