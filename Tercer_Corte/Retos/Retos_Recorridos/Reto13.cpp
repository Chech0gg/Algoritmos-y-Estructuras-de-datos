#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int N = 11;
string nombre[N] = { "Centro", "Norte", "Sur", "Este", "Oeste",
                     "Hospital", "Escuela", "Mercado", "Parque", "Puerto",
                     "Bodega" };   // Bodega no tiene conexiones (para probar el caso sin ruta)

vector<int> ady[N];

void agregarArista(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
}

void ruta(int origen, int destino) {
    cout << "Ruta de " << nombre[origen] << " a " << nombre[destino] << ": ";


    if (origen == destino) {
        cout << "ya esta en el destino (0 tramos).\n";
        return;
    }

    int dist[N], padre[N];
    for (int i = 0; i < N; i++) { dist[i] = -1; padre[i] = -1; }
    queue<int> cola;
    dist[origen] = 0;
    cola.push(origen);

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        for (int i = 0; i < (int)ady[u].size(); i++) {
            int v = ady[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                padre[v] = u;
                cola.push(v);
            }
        }
    }

    if (dist[destino] == -1) {
        cout << "NO existe ninguna ruta. " << nombre[destino]
             << " no esta conectado con " << nombre[origen] << ".\n";
        return;
    }

    // Caso 1: ruta normal -> reconstruir el camino al reves con los padres
    vector<int> camino;
    for (int x = destino; x != -1; x = padre[x])
        camino.push_back(x);

    for (int k = (int)camino.size() - 1; k >= 0; k--) {
        cout << nombre[camino[k]];
        if (k > 0) cout << " -> ";
    }
    cout << "  (" << dist[destino] << " tramos)\n";
}

int main() {
    agregarArista(0, 1); agregarArista(0, 2); agregarArista(0, 3);
    agregarArista(0, 4); agregarArista(1, 5); agregarArista(1, 6);
    agregarArista(5, 6); agregarArista(2, 7); agregarArista(3, 7);
    agregarArista(4, 8); agregarArista(8, 9);

    ruta(5, 9);    // Hospital -> Puerto   (ruta normal)
    ruta(7, 6);    // Mercado  -> Escuela  (ruta normal)
    ruta(3, 3);    // Este     -> Este     (origen = destino)
    ruta(0, 10);   // Centro   -> Bodega   (inalcanzable)
    return 0;
}
