def buscar(v, x):
    izq, der = 0, len(v) - 1
    while izq <= der:
        medio = (izq + der) // 2
        if v[medio] == x:
            return medio
        elif v[medio] < x:
            izq = medio + 1 # (1)
        else:
            der = medio - 1
    return -1
v = [8, 15, 23, 31, 42, 56, 64, 77, 89, 91]
x = int(input("Ingrese el valor a buscar: "))
resultado = buscar(v, x)
if resultado != -1:
    print("Elemento encontrado en el indice", resultado)
else:
    print("Elemento no encontrado")