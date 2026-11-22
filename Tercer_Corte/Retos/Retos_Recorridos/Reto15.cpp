#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int N = 10;
string nombre[N] = { "Centro", "Norte", "Sur", "Este", "Oeste",
                     "Hospital", "Escuela", "Mercado", "Parque", "Puerto" };

vector<int> ady[N];
int dist[N];

void agregarArista(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
}

void bfs(int origen) {
    for (int i = 0; i < N; i++) dist[i] = -1;
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
                cola.push(v);
            }
        }
    }
}

// Minutos que tarda en caer TODA la red si la falla empieza en origen
// (es la excentricidad del vertice)
int minutosEnCaer(int origen) {
    bfs(origen);
    int maximo = 0;
    for (int i = 0; i < N; i++)
        if (dist[i] > maximo) maximo = dist[i];
    return maximo;
}

int main() {
    agregarArista(0, 1); agregarArista(0, 2); agregarArista(0, 3);
    agregarArista(0, 4); agregarArista(1, 5); agregarArista(1, 6);
    agregarArista(5, 6); agregarArista(2, 7); agregarArista(3, 7);
    agregarArista(4, 8); agregarArista(8, 9);

    // Parte 1: falla que empieza en un punto
    int inicio = 5;  // Hospital
    bfs(inicio);
    cout << "La falla empieza en " << nombre[inicio] << ":\n";
    for (int i = 0; i < N; i++)
        cout << "  " << nombre[i] << " cae en el minuto " << dist[i] << "\n";
    cout << "Toda la red cae en " << minutosEnCaer(inicio) << " minutos.\n\n";

    // Parte 2: probar todos los puntos de inicio
    int minutos[N];
    int peor = 0, mejor = 0;   // peor = cae mas rapido, mejor = cae mas lento
    cout << "Minutos para que caiga toda la red segun donde empiece la falla:\n";
    for (int v = 0; v < N; v++) {
        minutos[v] = minutosEnCaer(v);
        cout << "  " << nombre[v] << ": " << minutos[v] << " minutos\n";
        if (minutos[v] < minutos[peor])  peor = v;
        if (minutos[v] > minutos[mejor]) mejor = v;
    }

    cout << "\nDonde MENOS conviene que empiece la falla: " << nombre[peor]
         << " (tumba la red en " << minutos[peor] << " minutos). Es el centro de la red.\n";
    cout << "Donde la falla tarda MAS en propagarse: " << nombre[mejor]
         << " (" << minutos[mejor] << " minutos). Es el punto mas periferico.\n";
    return 0;
}
