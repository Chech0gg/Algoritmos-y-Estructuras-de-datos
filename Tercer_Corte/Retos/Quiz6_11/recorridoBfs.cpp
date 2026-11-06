#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int N = 9;
vector<string> NOMBRES = {
    "CENTRO", "NORTE", "SUR", "ORIENTE", "OCCIDENTE",
    "CHAPINERO", "USAQUEN", "BOSA", "VEREDA"
};

vector<pair<int, int>> ARISTAS = {
    {0,1}, {0,2}, {0,3}, {1,4}, {1,5},
    {2,7}, {3,6}, {5,6}, {4,7}, {7,8}
};

vector<vector<int>> lista(N);

// Versión iterativa de DFS
vector<int> dfs_iter(int inicio) {
    vector<bool> visitado(N, false);
    stack<int> pila;
    pila.push(inicio);
    vector<int> orden;
    
    while (!pila.empty()) {
        int u = pila.top();
        pila.pop();
        
        if (visitado[u]) {
            continue;
        }
        visitado[u] = true;
        orden.push_back(u);
        
        // Recorrer en orden inverso para igualar el comportamiento del DFS recursivo
        for (auto it = lista[u].rbegin(); it != lista[u].rend(); ++it) {
            int v = *it;
            if (!visitado[v]) {
                pila.push(v);
            }
        }
    }
    return orden;
}

// Versión de BFS
vector<int> bfs(int inicio) {
    vector<bool> visitado(N, false);
    queue<int> cola;
    cola.push(inicio);
    vector<int> orden;
    
    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        
        if (visitado[u]) {
            continue;
        }
        visitado[u] = true;
        orden.push_back(u);
        
        for (int v : lista[u]) {
            if (!visitado[v]) {
                cola.push(v);
            }
        }
    }
    return orden;
}

// Camino más corto usando BFS
vector<int> camino_mas_corto(int inicio, int destino) {
    vector<bool> visitado(N, false);
    vector<int> padre(N, -1);
    queue<int> cola;
    
    cola.push(inicio);
    visitado[inicio] = true;
    
    bool encontrado = false;
    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        
        if (u == destino) {
            encontrado = true;
            break;
        }
        
        for (int v : lista[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                padre[v] = u;
                cola.push(v);
            }
        }
    }
    
    if (!encontrado) {
        return {}; // Vector vacío si no hay camino
    }
    
    vector<int> camino;
    int u = destino;
    while (u != -1) {
        camino.push_back(u);
        u = padre[u];
    }
    reverse(camino.begin(), camino.end());
    return camino;
}

int main() {
    // Construir la lista de adyacencia
    for (const auto& arista : ARISTAS) {
        int u = arista.first;
        int v = arista.second;
        lista[u].push_back(v);
        lista[v].push_back(u);
    }
    
    // Ordenar los vecinos
    for (int i = 0; i < N; ++i) {
        sort(lista[i].begin(), lista[i].end());
    }

    // 1. Camino más corto de CENTRO (0) a VEREDA (8)
    cout << "CAMINO MAS CORTO DE CENTRO A VEREDA:\n";
    vector<int> camino_corto = camino_mas_corto(0, 8);
    if (!camino_corto.empty()) {
        for (size_t i = 0; i < camino_corto.size(); ++i) {
            cout << NOMBRES[camino_corto[i]] << (i + 1 < camino_corto.size() ? " -> " : "");
        }
        cout << "\n";
    } else {
        cout << "No hay camino disponible.\n";
    }

    // 2. DFS hacia vereda (iniciando en el nodo 8)
    cout << "DFS hacia vereda:\n";
    vector<int> camino_dfs = dfs_iter(8);
    if (!camino_dfs.empty()) {
        for (size_t i = 0; i < camino_dfs.size(); ++i) {
            cout << NOMBRES[camino_dfs[i]] << (i + 1 < camino_dfs.size() ? " -> " : "");
        }
        cout << "\n";
    } else {
        cout << "No hay camino disponible.\n";
    }

    // 3. BFS hacia vereda (iniciando en el nodo 8)
    cout << "BFS hacia vereda:\n";
    vector<int> camino_bfs = bfs(8);
    if (!camino_bfs.empty()) {
        for (size_t i = 0; i < camino_bfs.size(); ++i) {
            cout << NOMBRES[camino_bfs[i]] << (i + 1 < camino_bfs.size() ? " -> " : "");
        }
        cout << "\n";
    } else {
        cout << "No hay camino disponible.\n";
    }

    return 0;
}s