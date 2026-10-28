#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Nodo {
public:
    string dato;
    Nodo* izq;
    Nodo* der;

    Nodo(string val) {
        dato = val;
        izq = nullptr;
        der = nullptr;
    }
};

void preorden(Nodo* n, vector<string>& salida) {
    if (n == nullptr) return;
    salida.push_back(n->dato);
    preorden(n->izq, salida);
    preorden(n->der, salida);
}

void inorden(Nodo* n, vector<string>& salida) {
    if (n == nullptr) return;
    inorden(n->izq, salida);
    salida.push_back(n->dato);
    inorden(n->der, salida);
}

void postorden(Nodo* n, vector<string>& salida) {
    if (n == nullptr) return;
    postorden(n->izq, salida);
    postorden(n->der, salida);
    salida.push_back(n->dato);
}

int altura(Nodo* n) {
    if (n == nullptr) return -1;
    return 1 + max(altura(n->izq), altura(n->der));
}

int contar(Nodo* n) {
    if (n == nullptr) return 0;
    return 1 + contar(n->izq) + contar(n->der);
}

int contar_hojas(Nodo* n) {
    if (n == nullptr) return 0;
    if (n->izq == nullptr && n->der == nullptr) return 1;
    return contar_hojas(n->izq) + contar_hojas(n->der);
}

vector<string> por_niveles(Nodo* raiz) {
    if (raiz == nullptr) return {};
    vector<string> salida;
    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* n = cola.front();
        cola.pop();
        salida.push_back(n->dato);
        if (n->izq != nullptr) cola.push(n->izq);
        if (n->der != nullptr) cola.push(n->der);
    }
    return salida;
}

void espejo(Nodo* nodo) {
    if (nodo == nullptr) return;
    espejo(nodo->izq);
    espejo(nodo->der);
    swap(nodo->izq, nodo->der);
}
int main() {
    // Construcción del árbol
    Nodo* raiz = new Nodo("CATALOGO");
    raiz->izq = new Nodo("HERRAMIENTA"); 
    raiz->der = new Nodo("LIBRO");
    raiz->izq->izq = new Nodo("TALADRO");  
    raiz->izq->der = new Nodo("SIERRA");
    raiz->der->izq = new Nodo("ARTE");     
    raiz->der->der = new Nodo("TECNICO");
    raiz->der->der->der = new Nodo("REDES");
    espejo(raiz);
    vector<string> niveles = por_niveles(raiz);
    cout << "Por niveles (espejo): ";
    for (size_t i = 0; i < niveles.size(); ++i) {
        cout << niveles[i] << (i + 1 < niveles.size() ? " -> " : "");
    }
    cout << endl;

    return 0;
}