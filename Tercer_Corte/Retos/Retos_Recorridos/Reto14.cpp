#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;

const int N = 10;
string nombre[N] = { "Centro", "Norte", "Sur", "Este", "Oeste",
                     "Hospital", "Escuela", "Mercado", "Parque", "Puerto" };

vector<int> ady[N];
int dist[N][N];   // dist[a][b] = menor numero de tramos de a a b

void agregarArista(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);
}

// Llena la fila dist[origen][...]
void bfs(int origen) {
    for (int i = 0; i < N; i++) dist[origen][i] = -1;
    queue<int> cola;
    dist[origen][origen] = 0;
    cola.push(origen);
    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        for (int i = 0; i < (int)ady[u].size(); i++) {
            int v = ady[u][i];
            if (dist[origen][v] == -1) {
                dist[origen][v] = dist[origen][u] + 1;
                cola.push(v);
            }
        }
    }
}

int main() {
    agregarArista(0, 1); agregarArista(0, 2); agregarArista(0, 3);
    agregarArista(0, 4); agregarArista(1, 5); agregarArista(1, 6);
    agregarArista(5, 6); agregarArista(2, 7); agregarArista(3, 7);
    agregarArista(4, 8); agregarArista(8, 9);

    for (int v = 0; v < N; v++)
        bfs(v);

    // Imprimir la tabla
    cout << "Tabla de distancias (numero de tramos):\n\n" << setw(10) << " ";
    for (int j = 0; j < N; j++) cout << setw(9) << nombre[j];
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << setw(10) << nombre[i];
        for (int j = 0; j < N; j++) cout << setw(9) << dist[i][j];
        cout << "\n";
    }

    // Buscar el diametro
    int diametro = 0, a = 0, b = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (dist[i][j] > diametro) {
                diametro = dist[i][j];
                a = i;
                b = j;
            }

    cout << "\nDiametro de la red: " << diametro << " tramos\n";
    cout << "Lo producen los puntos " << nombre[a] << " y " << nombre[b] << ".\n";
    cout << "\nInterpretacion: en el peor caso, un envio necesita " << diametro
         << " tramos para cruzar la red.\nPara cualquier pareja de puntos el "
            "tiempo de entrega nunca sera peor que eso.\n";
    return 0;
}
