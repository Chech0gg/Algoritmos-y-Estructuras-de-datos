#include <iostream>
#include <vector>
#include <string>
using namespace std;

int buscarIndice(const vector<string>& zonas, const string& nombre) {
    for (int i = 0; i < (int)zonas.size(); i++) {
        if (zonas[i] == nombre) return i;
    }
    return -1;
}

bool existeAristaMatriz(const vector<vector<int>>& matriz, int u, int v) {
    return matriz[u][v] == 1;
}

bool existeAristaLista(const vector<vector<int>>& lista, int u, int v) {
    for (int vec : lista[u]) {
        if (vec == v) return true;
    }
    return false;
}

int main() {
    vector<string> zonas = {
        "CENTRO", "NORTE", "CHAPINERO", "USAQUEN",
        "SUBA", "KENNEDY", "BOSA", "FONTIBON", "TEUSAQUILLO"
    };
    int V = 9;

    vector<pair<string, string>> aristas = {
        {"CENTRO", "NORTE"},
        {"CENTRO", "CHAPINERO"},
        {"CENTRO", "FONTIBON"},
        {"CENTRO", "TEUSAQUILLO"},
        {"NORTE", "USAQUEN"},
        {"NORTE", "SUBA"},
        {"CHAPINERO", "USAQUEN"},
        {"CHAPINERO", "TEUSAQUILLO"},
        {"KENNEDY", "BOSA"},
        {"KENNEDY", "FONTIBON"}
    };
    int E = 10;

    vector<vector<int>> matriz(V, vector<int>(V, 0));
    vector<vector<int>> lista(V);

    for (auto& p : aristas) {
        int u = buscarIndice(zonas, p.first);
        int v = buscarIndice(zonas, p.second);
        matriz[u][v] = 1;
        matriz[v][u] = 1;
        lista[u].push_back(v);
        lista[v].push_back(u);
    }

    double densidad = (2.0 * E) / (V * (V - 1));

    cout << "V = " << V << ", E = " << E << "\n";
    cout << "Matriz: " << (V * V) << " casillas\n";
    cout << "Lista: " << (2 * E) << " referencias\n";
    cout << "Densidad: " << densidad << " -> grafo DISPERSO (conviene lista)\n";

    vector<pair<string, string>> consultas = {
        {"CENTRO", "NORTE"},
        {"CENTRO", "BOSA"},
        {"CHAPINERO", "USAQUEN"}
    };

    for (auto& c : consultas) {
        int u = buscarIndice(zonas, c.first);
        int v = buscarIndice(zonas, c.second);
        cout << c.first << " con " << c.second
             << " -> matriz=" << existeAristaMatriz(matriz, u, v)
             << " lista=" << existeAristaLista(lista, u, v) << "\n";
    }

    return 0;
}