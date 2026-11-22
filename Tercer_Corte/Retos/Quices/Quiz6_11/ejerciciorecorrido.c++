#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 9;
vector<string> NOMBRES = {
    "CENTRO", "NORTE", "SUR", "ORIENTE", "OCCIDENTE",
    "CHAPINERO", "USAQUEN", "BOSA", "VEREDA"
};

// ---------- DFS recursivo ----------
void dfs_rec(int u, const vector<vector<int>>& grafo, vector<bool>& visitado, vector<int>& orden, int prof = 0, vector<string>* traza = nullptr) {
    visitado[u] = true;
    orden.push_back(u);
    
    if (traza != nullptr) {
        string indent(prof * 2, ' ');
        traza->push_back(indent + "entra " + NOMBRES[u]);
    }
    
    for (int v : grafo[u]) {
        if (!visitado[v]) {
            dfs_rec(v, grafo, visitado, orden, prof + 1, traza);
        } else if (traza != nullptr) {
            string indent((prof + 1) * 2, ' ');
            traza->push_back(indent + NOMBRES[v] + " ya visitado, no entra");
        }
    }
    
    if (traza != nullptr) {
        string indent(prof * 2, ' ');
        traza->push_back(indent + "sale  " + NOMBRES[u]);
    }
}

// ---------- DFS iterativo con pila ----------
vector<int> dfs_iter(int inicio, const vector<vector<int>>& grafo) {
    vector<bool> visitado(N, false);
    vector<int> orden;
    stack<int> pila;
    pila.push(inicio);
    
    while (!pila.empty()) {
        int u = pila.top();
        pila.pop();
        
        if (visitado[u]) continue;
        visitado[u] = true;
        orden.push_back(u);
        
        // Recorrer en orden inverso para igualar el comportamiento del DFS recursivo
        for (auto it = grafo[u].rbegin(); it != grafo[u].rend(); ++it) {
            int v = *it;
            if (!visitado[v]) {
                pila.push(v);
            }
        }
    }
    return orden;
}

// ---------- Aplicacion 1: componentes conexas ----------
void dfs_comp(int u, const vector<vector<int>>& grafo, vector<bool>& vis, vector<int>& o) {
    vis[u] = true;
    o.push_back(u);
    for (int v : grafo[u]) {
        if (!vis[v]) {
            dfs_comp(v, grafo, vis, o);
        }
    }
}

vector<vector<string>> obtener_componentes(const vector<vector<int>>& grafo) {
    vector<bool> visitado(N, false);
    vector<vector<string>> comps;
    
    for (int s = 0; s < N; ++s) {
        if (!visitado[s]) {
            vector<int> o;
            dfs_comp(s, grafo, visitado, o);
            vector<string> comp_nombres;
            for (int i : o) {
                comp_nombres.push_back(NOMBRES[i]);
            }
            comps.push_back(comp_nombres);
        }
    }
    return comps;
}

// ---------- Aplicacion 2: deteccion de ciclo ----------
bool explorar_ciclo(int u, int padre, const vector<vector<int>>& grafo, vector<bool>& visitado) {
    visitado[u] = true;
    for (int v : grafo[u]) {
        if (!visitado[v]) {
            if (explorar_ciclo(v, u, grafo, visitado)) return true;
        } else if (v != padre) {
            return true;
        }
    }
    return false;
}

bool hay_ciclo(const vector<vector<int>>& grafo) {
    vector<bool> visitado(N, false);
    for (int s = 0; s < N; ++s) {
        if (!visitado[s] && explorar_ciclo(s, -1, grafo, visitado)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Definición de aristas originales
    vector<pair<int, int>> ARISTAS = {
        {0,1}, {0,2}, {0,3}, {1,4}, {1,5},
        {2,7}, {3,6}, {5,6}, {4,7}, {7,8}
    };
    
    vector<vector<int>> lista(N);
    for (const auto& arista : ARISTAS) {
        int u = arista.first;
        int v = arista.second;
        lista[u].push_back(v);
        lista[v].push_back(u);
    }
    
    // Ordenar vecinos
    for (int i = 0; i < N; ++i) {
        sort(lista[i].begin(), lista[i].end());
    }
    
    // ---------- Ejecución DFS recursivo ----------
    vector<bool> vis(N, false);
    vector<int> orden;
    vector<string> traza;
    dfs_rec(0, lista, vis, orden, 0, &traza);
    
    cout << "DFS RECURSIVO desde CENTRO\n";
    for (const string& t : traza) {
        cout << "  " << t << "\n";
    }
    cout << "  orden de visita: ";
    for (size_t i = 0; i < orden.size(); ++i) {
        cout << NOMBRES[orden[i]] << (i + 1 < orden.size() ? " -> " : "");
    }
    cout << "\n\n";
    
    // ---------- Ejecución DFS iterativo ----------
    cout << "DFS ITERATIVO (con pila explicita) desde CENTRO\n";
    vector<int> orden_iter = dfs_iter(0, lista);
    cout << "  orden de visita: ";
    for (size_t i = 0; i < orden_iter.size(); ++i) {
        cout << NOMBRES[orden_iter[i]] << (i + 1 < orden_iter.size() ? " -> " : "");
    }
    cout << "\n\n";
    
    // ---------- Componentes conexas (red completa) ----------
    cout << "COMPONENTES CONEXAS de la red completa: ";
    vector<vector<string>> comps = obtener_componentes(lista);
    cout << "[";
    for (size_t i = 0; i < comps.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < comps[i].size(); ++j) {
            cout << "\"" << comps[i][j] << "\"" << (j + 1 < comps[i].size() ? ", " : "");
        }
        cout << "]" << (i + 1 < comps.size() ? ", " : "");
    }
    cout << "]\n";
    
    // ---------- Red con tramos cortados ----------
    vector<vector<int>> lista_rota(N);
    vector<pair<int, int>> aristas_rotas = {{0,1}, {0,2}, {3,6}};
    for (const auto& arista : aristas_rotas) {
        int u = arista.first;
        int v = arista.second;
        lista_rota[u].push_back(v);
        lista_rota[v].push_back(u);
    }
    for (int i = 0; i < N; ++i) {
        sort(lista_rota[i].begin(), lista_rota[i].end());
    }
    
    cout << "COMPONENTES de una red con tramos cortados: ";
    vector<vector<string>> comps_rota = obtener_componentes(lista_rota);
    cout << "[";
    for (size_t i = 0; i < comps_rota.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < comps_rota[i].size(); ++j) {
            cout << "\"" << comps_rota[i][j] << "\"" << (j + 1 < comps_rota[i].size() ? ", " : "");
        }
        cout << "]" << (i + 1 < comps_rota[i].size() ? ", " : "");
    }
    cout << "]\n";
    
    // ---------- Detección de ciclo ----------
    cout << "¿La red tiene algun circuito?: " << (hay_ciclo(lista) ? "True" : "False") << "\n";
    
    return 0;
}