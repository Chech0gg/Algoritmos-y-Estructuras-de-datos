#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>

using namespace std;

int main() {
    // Definición de nombres y aristas
    vector<string> NOMBRES = {"CENTRO", "NORTE", "SUR", "ORIENTE", "OCCIDENTE", "CHAPINERO", "USAQUEN", "BOSA", "VEREDA"};

    vector<pair<int, int>> ARISTAS = {
        {0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {1,8}, 
        {2,7}, {2,4}, {3,6}, {4,5}, {4,7}, {5,6}, 
        {5,7}, {5,8}, {7,8}
    };

    int N = NOMBRES.size();

    // ---------- Representación 1: Matriz de Adyacencia ----------
    vector<vector<int>> matriz(N, vector<int>(N, 0));
    for (const auto& edge : ARISTAS) {
        int u = edge.first;
        int v = edge.second;
        matriz[u][v] = 1;
        matriz[v][u] = 1; // Grafo no dirigido: matriz simétrica
    }

    cout << "=== MATRIZ DE ADYACENCIA ===" << endl;
    cout << setw(11) << " ";
    for (const string& n : NOMBRES) {
        cout << setw(4) << n.substr(0, 3);
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        cout << setw(11) << NOMBRES[i] << " ";
        for (int j = 0; j < N; ++j) {
            cout << setw(4) << matriz[i][j];
        }
        cout << endl;
    }

    // ---------- Representación 2: Lista de Adyacencia ----------
    vector<vector<int>> lista(N);
    for (const auto& edge : ARISTAS) {
        lista[edge.first].push_back(edge.second);
        lista[edge.second].push_back(edge.first);
    }

    // Ordenar y eliminar duplicados para evitar fallos en el assert
    for (int i = 0; i < N; ++i) {
        sort(lista[i].begin(), lista[i].end());
        lista[i].erase(unique(lista[i].begin(), lista[i].end()), lista[i].end());
    }

    cout << "\n=== LISTA DE ADYACENCIA ===" << endl;
    for (int i = 0; i < N; ++i) {
        cout << setw(10) << NOMBRES[i] << " -> ";
        for (size_t j = 0; j < lista[i].size(); ++j) {
            cout << NOMBRES[lista[i][j]];
            if (j + 1 < lista[i].size()) cout << ", ";
        }
        cout << endl;
    }

    // ---------- Grados y Validación ----------
    cout << "\n=== GRADO DE CADA VÉRTICE ===" << endl;
    for (int i = 0; i < N; ++i) {
        int g_mat = 0;
        for (int j = 0; j < N; ++j) {
            g_mat += matriz[i][j];
        }
        int g_lis = lista[i].size();
        assert(g_mat == g_lis); // Validación de consistencia
        cout << setw(11) << NOMBRES[i] << ": " << g_lis << endl;
    }

    // ---------- Enfoque Exclusivo en OCCIDENTE ----------
    int idx_occidente = -1;
    for (int i = 0; i < N; ++i) {
        if (NOMBRES[i] == "OCCIDENTE") {
            idx_occidente = i;
            break;
        }
    }

    cout << "\nOCCIDENTE" << endl;
    cout << "Vértice: " << NOMBRES[idx_occidente] << endl;
    cout << "Grado: " << lista[idx_occidente].size() << endl;
    cout << "Conecta directamente con: ";
    for (size_t j = 0; j < lista[idx_occidente].size(); ++j) {
        cout << NOMBRES[lista[idx_occidente][j]];
        if (j + 1 < lista[idx_occidente].size()) cout << ", ";
    }
    cout << endl;

    // ---------- Costos y Densidad ----------
    int aristas_count = ARISTAS.size();
    cout << "\n=== ESTADÍSTICAS DEL GRAFO ===" << endl;
    cout << "V = " << N << " vértices, E = " << aristas_count << " aristas" << endl;
    double densidad = (2.0 * aristas_count) / (N * (N - 1));
    cout << fixed << setprecision(2);
    cout << "Densidad = " << densidad << " -> Grafo " 
         << (densidad > 0.5 ? "DENSO: conviene matriz" : "DISPERSO: conviene lista") << endl;

    // ---------- Consulta de arista ----------
    auto hay_via_matriz = [&](int u, int v) { return matriz[u][v] == 1; };
    auto hay_via_lista = [&](int u, int v) { 
        return find(lista[u].begin(), lista[u].end(), v) != lista[u].end(); 
    };

    cout << "\n=== CONSULTAS DE ARISTAS ===" << endl;
    vector<pair<int, int>> consultas = {{1,4}, {2,4}, {4,5}, {4,7}};
    for (const auto& q : consultas) {
        int u = q.first;
        int v = q.second;
        cout << "  ¿" << NOMBRES[u] << " conecta con " << NOMBRES[v] << "? "
             << "matriz=" << (hay_via_matriz(u, v) ? "true" : "false") << "  "
             << "lista=" << (hay_via_lista(u, v) ? "true" : "false") << endl;
    }

    return 0;
}