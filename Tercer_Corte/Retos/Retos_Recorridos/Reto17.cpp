#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 7;
string materia[N] = { "Matematicas Basicas", "Programacion I", "Programacion II",
                      "Estructuras de Datos", "Algoritmos", "Bases de Datos",
                      "Ingenieria de Software" };

vector<int> ady[N];
int estado[N];
int padre[N];
bool hayCiclo = false;

// Devuelve true si encontro un ciclo
bool dfs(int u) {
    estado[u] = 1;   // en proceso
    for (int i = 0; i < (int)ady[u].size(); i++) {
        int v = ady[u][i];
        if (estado[v] == 0) {
            padre[v] = u;
            if (dfs(v)) return true;
        }
        else if (estado[v] == 1) {
            // v esta en proceso: encontramos el ciclo v -> ... -> u -> v
            // Se reconstruye subiendo por los padres desde u hasta v
            vector<int> ciclo;
            int x = u;
            while (x != v) {
                ciclo.push_back(x);
                x = padre[x];
            }
            ciclo.push_back(v);

            cout << "CICLO ENCONTRADO! Este plan de estudios es imposible:\n  ";
            for (int k = (int)ciclo.size() - 1; k >= 0; k--)
                cout << materia[ciclo[k]] << " -> ";
            cout << materia[v] << "\n";
            cout << "Ninguna de esas " << ciclo.size()
                 << " materias se puede cursar primero.\n";
            return true;
        }
    }
    estado[u] = 2;   // terminado
    return false;
}

int main() {
    ady[0].push_back(1); // Mat. Basicas  -> Prog I
    ady[1].push_back(2); // Prog I        -> Prog II
    ady[2].push_back(3); // Prog II       -> Estructuras
    ady[3].push_back(4); // Estructuras   -> Algoritmos
    ady[3].push_back(5); // Estructuras   -> Bases de Datos
    ady[4].push_back(6); // Algoritmos    -> Ing. Software
    ady[5].push_back(6); // Bases de Datos-> Ing. Software
    ady[6].push_back(2); // CICLO A PROPOSITO: Ing. Software -> Prog II

    for (int i = 0; i < N; i++) { estado[i] = 0; padre[i] = -1; }

    bool encontrado = false;
    for (int i = 0; i < N && !encontrado; i++)
        if (estado[i] == 0)
            encontrado = dfs(i);

    if (!encontrado)
        cout << "El plan de estudios no tiene ciclos. Es valido.\n";

    return 0;
}