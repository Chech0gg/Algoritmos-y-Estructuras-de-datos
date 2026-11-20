#centro ->norte
# norte ->occidente
#centro-> sur
#centro ->oriente
# norte -> chapinero
# sur -> bosa
# oriente -> usaquen
# chapinero -> usaquen
# occidente -> bosa
# bosa -> vereda
# vereda -> norte
# bosa -> chapinero
# chapinero -> vereda
#sur -> usaquen
# usaquen -> vereda
# norte ->vereda 
# chapinero -> bosa
# chapinero -> sur

NOMBRES = ["CENTRO", "NORTE", "SUR", "ORIENTE", "OCCIDENTE", "CHAPINERO", "USAQUEN", "BOSA", "VEREDA"]

# Lista de aristas limpiada para evitar redundancias en grafo no dirigido
ARISTAS = [
    (0,1), (0,2), (0,3),  (1,4), (1,5), (1,8),  (2,7), (2,4), (3,6), (4,5), (4,7),        
    (5,6), (5,7), (5,8), 
    (7,8)             
]

N = len(NOMBRES)

# ---------- Representación 1: Matriz de Adyacencia ----------
matriz = [[0]*N for _ in range(N)]
for u, v in ARISTAS:
    matriz[u][v] = 1
    matriz[v][u] = 1  # Grafo no dirigido: matriz simétrica

print("=== MATRIZ DE ADYACENCIA ===")
print("             " + " ".join(f"{n[:3]:>4}" for n in NOMBRES))
for i in range(N):
    print(f"{NOMBRES[i]:>11} " + " ".join(f"{matriz[i][j]:>4}" for j in range(N)))

# ---------- Representación 2: Lista de Adyacencia ----------
lista = [set() for _ in range(N)]
for u, v in ARISTAS:
    lista[u].add(v)
    lista[v].add(u)

# Convertir los sets a listas ordenadas
lista = [sorted(list( vecinos )) for vecinos in lista]

print("\n=== LISTA DE ADYACENCIA ===")
for i in range(N):
    print(f"  {NOMBRES[i]:>10} -> {', '.join(NOMBRES[j] for j in lista[i])}")

# ---------- Grados y Validación ----------
print("\n=== GRADO DE CADA VÉRTICE ===")
for i in range(N):
    g_mat = sum(matriz[i])       
    g_lis = len(lista[i])        
    assert g_mat == g_lis, f"Error en el vértice {NOMBRES[i]}"
    print(f"  {NOMBRES[i]:>10}: {g_lis} conexiones")

# ---------- Enfoque Exclusivo en OCCIDENTE ----------
idx_occidente = NOMBRES.index("OCCIDENTE")
print(f"\nOCCIDENTE")
print(f"Vértice: {NOMBRES[idx_occidente]}")
print(f"Grado: {len(lista[idx_occidente])}")
print(f"Conecta directamente con: {', '.join(NOMBRES[j] for j in lista[idx_occidente])}")

# ---------- Costos y Densidad ----------
aristas = len(ARISTAS)
print(f"\n=== ESTADÍSTICAS DEL GRAFO ===")
print(f"V = {N} vértices, E = {aristas} aristas")
densidad = (2 * aristas) / (N * (N - 1))
print(f"Densidad = {densidad:.2f} -> Grafo {'DENSO: conviene matriz' if densidad > 0.5 else 'DISPERSO: conviene lista'}")

# ---------- Consulta de arista ----------
def hay_via_matriz(u, v): return matriz[u][v] == 1
def hay_via_lista(u, v):  return v in lista[u]
for u, v in [
(1,4), (2,4),  (4,5), (4,7),        
                
]:
    print(f"  ¿{NOMBRES[u]} conecta con {NOMBRES[v]}? matriz={hay_via_matriz(u,v)}  lista={hay_via_lista(u,v)}")

