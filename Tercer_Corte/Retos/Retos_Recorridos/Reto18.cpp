#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

const int MAXN = 25;
vector<int> ady[MAXN];
bool visitado[MAXN];
vector<int> camino, mejorCamino;
long long llamadas = 0;

void limpiarGrafo() {
    for (int i = 0; i < MAXN; i++) ady[i].clear();
}

void agregarArista(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
}

void buscar(int u, int destino) {
    llamadas++;
    visitado[u] = true;
    camino.push_back(u);

    if (u == destino) {
        if (camino.size() > mejorCamino.size())
            mejorCamino = camino;
    }
    else {
        for (int i = 0; i < (int)ady[u].size(); i++) {
            int v = ady[u][i];
            if (!visitado[v])
                buscar(v, destino);
        }
    }

    visitado[u] = false;   // DESMARCAR al regresar (backtracking)
    camino.pop_back();
}

void caminoMasLargo(int n, int origen, int destino) {
    for (int i = 0; i < n; i++) visitado[i] = false;
    camino.clear();
    mejorCamino.clear();
    llamadas = 0;
    buscar(origen, destino);
}

// Crea una red de prueba con n vertices.
// Regla fija para que siempre salga la misma red (unas 2 de cada 5 parejas se conectan).
void crearRedPrueba(int n) {
    limpiarGrafo();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((i * 7 + j * 3) % 5 < 2)
                agregarArista(i, j);
}

int main() {
    // ---------- 1. Prueba sobre la red del proyecto ----------
    string nombre[10] = { "Centro", "Norte", "Sur", "Este", "Oeste",
                          "Hospital", "Escuela", "Mercado", "Parque", "Puerto" };
    limpiarGrafo();
    agregarArista(0, 1); agregarArista(0, 2); agregarArista(0, 3);
    agregarArista(0, 4); agregarArista(1, 5); agregarArista(1, 6);
    agregarArista(5, 6); agregarArista(2, 7); agregarArista(3, 7);
    agregarArista(4, 8); agregarArista(8, 9);

    caminoMasLargo(10, 5, 9);   // de Hospital a Puerto
    cout << "Camino mas largo de Hospital a Puerto:\n  ";
    for (int i = 0; i < (int)mejorCamino.size(); i++)
        cout << nombre[mejorCamino[i]] << " ";
    cout << "\n  (" << mejorCamino.size() - 1 << " tramos)\n\n";

    // ---------- 2. Medir tiempos ----------
    int tamanos[3] = { 9, 15, 20 };
    for (int k = 0; k < 3; k++) {
        int n = tamanos[k];
        crearRedPrueba(n);
        cout << "Red con " << n << " vertices... " << flush;

        clock_t inicio = clock();
        caminoMasLargo(n, 0, n - 1);
        double segundos = double(clock() - inicio) / CLOCKS_PER_SEC;

        cout << "camino de " << mejorCamino.size() - 1 << " tramos, "
             << llamadas << " llamadas, " << segundos << " segundos\n";
    }
    return 0;
}
