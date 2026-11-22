#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 10;
string nombre[N] = { "Centro", "Norte", "Sur", "Este", "Oeste",
                     "Hospital", "Escuela", "Mercado", "Parque", "Puerto" };

vector<int> ady[N];     // lista de adyacencia
int zona[N];            // zona[v] = numero de la zona de v (-1 = sin visitar)

void agregarArista(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
}

void quitarArista(int a, int b) {
    for (int i = 0; i < (int)ady[a].size(); i++)
        if (ady[a][i] == b) { ady[a].erase(ady[a].begin() + i); break; }
    for (int i = 0; i < (int)ady[b].size(); i++)
        if (ady[b][i] == a) { ady[b].erase(ady[b].begin() + i); break; }
}

// DFS: marca a v y a todos los que se alcanzan desde v con el numero z
void dfs(int v, int z) {
    zona[v] = z;
    for (int i = 0; i < (int)ady[v].size(); i++) {
        int w = ady[v][i];
        if (zona[w] == -1)
            dfs(w, z);
    }
}

void informe() {
    // 1. Recorrer y numerar zonas
    for (int v = 0; v < N; v++) zona[v] = -1;
    int totalZonas = 0;
    for (int v = 0; v < N; v++) {
        if (zona[v] == -1) {
            totalZonas++;
            dfs(v, totalZonas);
        }
    }

    // 2. Escribir el informe
    if (totalZonas == 1)
        cout << "La red esta completamente conectada: es una sola zona.\n";
    else
        cout << "La red esta partida en " << totalZonas << " zonas.\n";

    int zonaMayor = 1, tamMayor = 0;
    for (int z = 1; z <= totalZonas; z++) {
        int tam = 0;
        bool tieneCentro = false;
        cout << "  Zona " << z << ": ";
        for (int v = 0; v < N; v++) {
            if (zona[v] == z) {
                cout << nombre[v] << "  ";
                tam++;
                if (v == 0) tieneCentro = true;   // el vertice 0 es el Centro
            }
        }
        cout << "\n     -> tiene " << tam << " puntos";
        if (tieneCentro) cout << " y contiene al Centro.\n";
        else             cout << " y NO tiene conexion con el Centro.\n";

        if (tam > tamMayor) { tamMayor = tam; zonaMayor = z; }
    }
    cout << "La zona mas grande es la zona " << zonaMayor
         << " con " << tamMayor << " puntos.\n\n";
}

int main() {
    agregarArista(0, 1); // Centro - Norte
    agregarArista(0, 2); // Centro - Sur
    agregarArista(0, 3); // Centro - Este
    agregarArista(0, 4); // Centro - Oeste
    agregarArista(1, 5); // Norte - Hospital
    agregarArista(1, 6); // Norte - Escuela
    agregarArista(5, 6); // Hospital - Escuela
    agregarArista(2, 7); // Sur - Mercado
    agregarArista(3, 7); // Este - Mercado
    agregarArista(4, 8); // Oeste - Parque
    agregarArista(8, 9); // Parque - Puerto

    cout << "===== INFORME 1: red original =====\n";
    informe();

    cout << "Se eliminan a proposito: Centro-Oeste y Parque-Puerto\n\n";
    quitarArista(0, 4);
    quitarArista(8, 9);

    cout << "===== INFORME 2: red con dos aristas menos =====\n";
    informe();

    return 0;
}