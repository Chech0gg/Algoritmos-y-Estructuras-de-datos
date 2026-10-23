def g(n):
    c = 0
    i = 1
    while i < n:
        for j in range(n):
            c += 1
        i *= 2
    return c
print(g(8))  
#El while se ejecuta mientras i < n con i = 1, 2, 4, 8, ... (potencias de 2). Cantidad de vueltas =
#⌈log₂ n⌉ (para n ≥ 1). El for interno siempre hace n vueltas, sin depender de i.
#Total = n · ⌈log₂ n⌉. Complejidad: O(n log n). Comprobación: n = 8 → i = 1, 2, 4 (tres vueltas)
#→ 3 · 8 = 24 = 8 · log₂ 8. ✔ Con n = 9 → i = 1, 2, 4, 8 (cuatro vueltas) → 36 = 9 · ⌈log₂ 9⌉. ✔
#Por qué importa el tipo de condición: si fuera i <= n , para n = 8 habría una vuelta más.
#Cuando pidan la expresión exacta, lee con cuidado < o <= .
