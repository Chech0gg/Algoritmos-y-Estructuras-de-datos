void dfsRec(int u, vector<bool>& vis, vector<int>& orden) {
    vis[u] = true;              // el hilo de Ariadna
    orden.push_back(u);
    for (int v : lista[u])
        if (!vis[v]) dfsRec(v, vis, orden);
}


// version iterativa
vector<int> dfsIter(int inicio) {
    vector<bool> vis(N, false);
    vector<int> pila{inicio}, orden;
    while (!pila.empty()) {
        int u = pila.back(); pila.pop_back();   // LIFO
        if (vis[u]) continue;                    // pudo entrar dos veces
        vis[u] = true;
        orden.push_back(u);
        for (auto it = lista[u].rbegin(); it != lista[u].rend(); ++it)
            if (!vis[*it]) pila.push_back(*it);
    }
    return orden;
    /*
