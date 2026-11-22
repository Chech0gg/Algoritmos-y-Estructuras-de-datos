from collections import deque
NOMBRES = ["CENTRO","NORTE","SUR","ORIENTE","OCCIDENTE",
           "CHAPINERO","USAQUEN","BOSA","VEREDA"]
ARISTAS = [(0,1),(0,2),(0,3),(1,4),(1,5),
           (2,7),(3,6),(5,6),(4,7),(7,8)]
N = 9
lista = [[] for _ in range(N)]
for u, v in ARISTAS:
    lista[u].append(v); lista[v].append(u)
for v in lista: v.sort()

# Versión iterativa de DFS
def dfs_iter(inicio):
    visitado = [False] * N
    pila = [inicio]
    orden = []
    while pila:
        u = pila.pop()
        if visitado[u]:
            continue
        visitado[u] = True
        orden.append(u)
        for v in reversed(lista[u]):
            if not visitado[v]:
                pila.append(v)
    return orden

# Versión de BFS
def bfs(inicio):
    visitado = [False] * N
    cola = [inicio]
    orden = []
    while cola:
        u = cola.pop(0)
        if visitado[u]:
            continue
        visitado[u] = True
        orden.append(u)
        for v in lista[u]:
            if not visitado[v]:
                cola.append(v)
    return orden

# Camino más corto usando BFS
def camino_mas_corto(inicio, destino):
    visitado = [False] * N
    padre = [None] * N
    cola = deque([inicio])
    visitado[inicio] = True
    while cola:
        u = cola.popleft()
        if u == destino:
            break
        for v in lista[u]:
            if not visitado[v]:
                visitado[v] = True
                padre[v] = u
                cola.append(v)
    if not visitado[destino]:
        return None
    camino = []
    u = destino
    while u is not None:
        camino.append(u)
        u = padre[u]
    camino.reverse()
    return camino

print("CAMINO MAS CORTO DE CENTRO A VEREDA:")
camino = camino_mas_corto(0, 8)
if camino is not None:
    print(" -> ".join(NOMBRES[v] for v in camino))
else:
    print("No hay camino disponible.")
print("DFS hacia vereda:")
camino = dfs_iter(8)
if camino is not None:
    print(" -> ".join(NOMBRES[v] for v in camino))
else:
    print("No hay camino disponible.")
print("BFS hacia vereda:")
camino = bfs(8)
if camino is not None:
    print(" -> ".join(NOMBRES[v] for v in camino))
else:
    print("No hay camino disponible.")