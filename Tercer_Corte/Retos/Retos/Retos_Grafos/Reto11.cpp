#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrizALista(const vector<vector<int>>& m) {
    int n = (int)m.size();
    vector<vector<int>> lista(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                lista[i].push_back(j);
            }
        }
    }
    return lista;
}

vector<vector<int>> listaAMatriz(const vector<vector<int>>& l) {
    int n = (int)l.size();
    vector<vector<int>> matriz(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j : l[i]) {
            matriz[i][j] = 1;
        }
    }
    return matriz;
}

bool verificarIdaYVuelta(const vector<vector<int>>& m) {
    vector<vector<int>> reconstruida = listaAMatriz(matrizALista(m));
    return reconstruida == m;
}

int main() {
    int V = 9;
    vector<pair<int, int>> aristas = {
        {0, 1}, {0, 2}, {0, 7}, {0, 8},
        {1, 3}, {1, 4},
        {2, 3},
        {5, 6}, {5, 7},
        {4, 3}
    };

    vector<vector<int>> m(V, vector<int>(V, 0));
    for (auto& p : aristas) {
        m[p.first][p.second] = 1;
        m[p.second][p.first] = 1;
    }

    cout << boolalpha;
    cout << "Ida y vuelta valida: " << verificarIdaYVuelta(m) << "\n";

    vector<vector<int>> l = matrizALista(m);
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int v : l[i]) cout << v << " ";
        cout << "\n";
    }

    return 0;
}