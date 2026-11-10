#include <queue>
 
void bfs(int inicio, vector<int>& orden, vector<int>& dist, vector<int>& padre) {
    vector<bool> vis(N, false);
    dist.assign(N, -1); padre.assign(N, -1); orden.clear();
    queue<int> cola;
    cola.push(inicio); vis[inicio] = true; dist[inicio] = 0;
    while (!cola.empty()) {
        int u = cola.front(); cola.pop();    // FIFO
        orden.push_back(u);
        for (int v : lista[u]) if (!vis[v]) {
            vis[v]   = true;                 // se marca al ENCOLAR
            dist[v]  = dist[u] + 1;
            padre[v] = u;
            cola.push(v);
        }
    }
}
