from collections import deque
 
def bfs(inicio):
    visitado = [False] * N
    dist  = [-1] * N          # distancia en numero de tramos
    padre = [-1] * N          # de donde llegue: permite reconstruir el camino
    cola = deque([inicio])
    visitado[inicio] = True   # se marca al ENCOLAR, no al sacar
    dist[inicio] = 0
    orden = []
    while cola:
        u = cola.popleft()    # FIFO: sale el primero que entro
        orden.append(u)
        for v in lista[u]:
            if not visitado[v]:
                visitado[v] = True
                dist[v]  = dist[u] + 1
                padre[v] = u
                cola.append(v)
    return orden, dist, padre
