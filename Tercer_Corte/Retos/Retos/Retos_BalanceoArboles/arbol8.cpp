#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int clave;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) {
        clave = val;
        izq = nullptr;
        der = nullptr;
    }
};

Nodo* insertar(Nodo* nodo, int clave) {
    if (nodo == nullptr) return new Nodo(clave);
    if (clave < nodo->clave) {
        nodo->izq = insertar(nodo->izq, clave);
    } else {
        nodo->der = insertar(nodo->der, clave);
    }
    return nodo;
}

int altura(Nodo* nodo) {
    if (nodo == nullptr) return -1;
    int izq = altura(nodo->izq);
    int der = altura(nodo->der);
    return 1 + (izq > der ? izq : der);
}
void liberar(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberar(nodo->izq);
    liberar(nodo->der);
    delete nodo;
}
void probarOrdenes(vector<int>& disponibles, vector<int>& actual, int& validos, vector<int>& ejemplo) {
    if (disponibles.empty()) {
        Nodo* raiz = nullptr;
        for (int clave : actual) {
            raiz = insertar(raiz, clave);
        }

        if (altura(raiz) == 2) {
            validos++;
            if (ejemplo.empty()) {
                ejemplo = actual;
            }
        }

        liberar(raiz);
        return;
    }

    for (int i = 0; i < (int)disponibles.size(); i++) {
        int elegido = disponibles[i];
        vector<int> resto = disponibles;
        resto.erase(resto.begin() + i);

        actual.push_back(elegido);
        probarOrdenes(resto, actual, validos, ejemplo);
        actual.pop_back();
    }
}

int main() {
    vector<int> claves = {1, 2, 3, 4, 5, 6, 7};
    vector<int> actual;
    vector<int> ejemplo;
    int validos = 0;

    probarOrdenes(claves, actual, validos, ejemplo);

    cout << "Ordenes validos de altura 2: " << validos << "\n";
    cout << "Ejemplo valido: ";
    for (int x : ejemplo) cout << x << " ";
    cout << "\n";
    Nodo* peor = nullptr;
    for (int x : {1, 2, 3, 4, 5, 6, 7}) {
        peor = insertar(peor, x);
    }
    cout << "Peor orden [1..7] -> altura: " << altura(peor) << "\n";

    liberar(peor);
    return 0;
}