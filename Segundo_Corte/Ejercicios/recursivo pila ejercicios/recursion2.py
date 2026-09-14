nivel = 0
def factorial(n):
    global nivel
    # Imprime visualmente que entramos a la función con sangría según la profundidad
    print("|  " * nivel + f"factorial({n}) entra")
    nivel += 1  # Entramos un nivel más profundo
    
    # Si n es menor o igual a 1, el resultado es 1; si no, multiplica n por el factorial de n-1
    r = 1 if n <= 1 else n * factorial(n - 1)
    
    nivel -= 1  # Salimos de ese nivel de profundidad
    # Imprime el valor que va devolviendo esta función
    print("|  " * nivel + f"factorial({n}) devuelve {r}")
    return r

def fibonacci(n):
    # Los dos primeros casos base de la serie (0 y 1)
    if n <= 1:
        return n
    # Suma los dos resultados anteriores de forma recursiva (ramificación doble)
    return fibonacci(n - 1) + fibonacci(n - 2)

# --- Zona de ejecución y pruebas ---
print("--- traza de la pila de llamadas ---")
r = factorial(15)  # Muestra paso a paso cómo se calcula el factorial
print("Resultado:", r)
print()

print("fibonacci(15) =", fibonacci(15))  # Calcula Fibonacci para 10

# Cronometrar cuánto tarda fibonacci(15)
import time
start_time = time.time()
fibonacci(15)
end_time = time.time()
print("Tiempo de ejecución de fibonacci(15):", end_time - start_time, "segundos")
