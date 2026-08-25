izq = 0
der = 100
intentos = 0
suma = 0
numero = (input("tu numero es mayor que : " + str(suma) + "? (Si/No): "))
for i in range(7):  # Suponiendo un máximo de 7 intentos
    if numero == "Si" or numero == "si":
        izq = suma - 1
    elif numero == "No" or numero == "no":
        der = suma + 1
        suma = (izq + der)/2
        intentos =+ 1
