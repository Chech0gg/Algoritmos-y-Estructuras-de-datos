matriz = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
suma = 0
suma2 = 0       

for i in range(len(matriz)):
        suma += matriz[i][i]
        suma2 += matriz[i][(len(matriz)) - 1 - i]#remplaze el valor paara encontrar la suma de la diagonal principal
print(f"La suma de la diagonal principal es: {suma}")
print(f"La suma de la diagonal secundaria es: {suma2}")
if suma == suma2:
    print("Valido")
else:
    print("No es valido")