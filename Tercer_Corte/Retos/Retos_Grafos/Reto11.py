def matrizALista(m):
    n = len(m)
    lista = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if m[i][j]:
                lista[i].append(j)
    return lista


def listaAMatriz(l):
    n = len(l)
    matriz = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in l[i]:
            matriz[i][j] = 1
    return matriz


def verificarIdaYVuelta(m):
    reconstruida = listaAMatriz(matrizALista(m))
    return reconstruida == m


# Ejemplo con V = 9 vértices (0..8) y E = 10 aristas no dirigidas
# 0:CENTRO, 1:NORTE, 2:CHAPINERO, 3:USAQUEN, 4:SUBA, 5:KENNEDY, 6:BOSA, 7:FONTIBON, 8:TEUSAQUILLO
V = 9
aristas = [
    (0, 1), (0, 2), (0, 7), (0, 8),
    (1, 3), (1, 4),
    (2, 3),
    (5, 6), (5, 7),
    (4, 3)
]

m = [[0] * V for _ in range(V)]
for u, v in aristas:
    m[u][v] = 1
    m[v][u] = 1

print("Ida y vuelta válida:", verificarIdaYVuelta(m))
l = matrizALista(m)
print("Lista de adyacencia:", l)