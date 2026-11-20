class nodo:
    def __init__(self, nombre):
        self.nombre = nombre
def existe_arista_matriz(matriz, u, v):
    return matriz[u][v] != 0


def existe_arista_lista(lista, u, v):
    return v in lista[u]


def densidad_grafo(V, E, dirigido=False):
    if V <= 1:
        return 0.0
    if dirigido:
        return E / (V * (V - 1))
    return (2 * E) / (V * (V - 1))


# V = 9, E = 10
# 0: CENTRO, 1: NORTE, 2: CHAPINERO, 3: USAQUEN, 4: SUBA, 5: KENNEDY, 6: BOSA, 7: FONTIBON, 8: TEUSAQUILLO
zonas = [
    "CENTRO", "NORTE", "CHAPINERO", "USAQUEN",
    "SUBA", "KENNEDY", "BOSA", "FONTIBON", "TEUSAQUILLO"
]
idx = {nombre: i for i, nombre in enumerate(zonas)}

V = len(zonas)
aristas = [
    ("CENTRO", "NORTE"),
    ("CENTRO", "CHAPINERO"),
    ("CENTRO", "FONTIBON"),
    ("CENTRO", "TEUSAQUILLO"),
    ("NORTE", "USAQUEN"),
    ("NORTE", "SUBA"),
    ("CHAPINERO", "USAQUEN"),
    ("CHAPINERO", "TEUSAQUILLO"),
    ("KENNEDY", "BOSA"),
    ("KENNEDY", "FONTIBON"),
]
E = len(aristas)

matriz = [[0] * V for _ in range(V)]
lista = [[] for _ in range(V)]

for u_nom, v_nom in aristas:
    u, v = idx[u_nom], idx[v_nom]
    matriz[u][v] = 1
    matriz[v][u] = 1
    lista[u].append(v)
    lista[v].append(u)

print(f"V = {V}, E = {E}")
print(f"Celdas matriz: {V * V}, Referencias lista: {2 * E}")
print(f"Densidad: {densidad_grafo(V, E):.2f} -> Grafo DISPERSO (conviene lista)")

consultas = [
    ("CENTRO", "NORTE"),
    ("CENTRO", "BOSA"),
    ("CHAPINERO", "USAQUEN"),
]

for u_nom, v_nom in consultas:
    u, v = idx[u_nom], idx[v_nom]
    m_res = existe_arista_matriz(matriz, u, v)
    l_res = existe_arista_lista(lista, u, v)
    print(f"¿{u_nom} conecta con {v_nom}? matriz={m_res} lista={l_res}")