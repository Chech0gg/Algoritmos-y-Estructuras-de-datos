matriz = [
    [1,2,3],
    [4,5,6]
]
n = len(matriz)
for i in range(n):
    for j in range(0, n):
    matriz[j][n-1-i]= matriz[i][j]
    print("La matriz rotada es:" + str(matriz[i][j]))
