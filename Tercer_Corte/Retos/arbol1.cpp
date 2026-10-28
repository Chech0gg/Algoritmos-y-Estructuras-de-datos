#include <iostream>
#include <string>

using namespace std;

// Definición de la estructura del Nodo
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

void imprimirJerarquia(Nodo* nodo, int nivel = 0) {
    if (nodo == nullptr) {
        return;
    }
    cout << string(nivel * 2, ' ') << nodo->dato << endl;
    imprimirJerarquia(nodo->izq, nivel + 1);
    imprimirJerarquia(nodo->der, nivel + 1);
}

int main() {
    Nodo* raiz = new Nodo("CATALOGO");
    raiz->izq = new Nodo("HERRAMIENTA");
    raiz->der = new Nodo("LIBRO");
    raiz->izq->izq = new Nodo("TALADRO");
    raiz->izq->der = new Nodo("SIERRA");
    raiz->der->izq = new Nodo("ARTE");
    raiz->der->der = new Nodo("TECNICO");
    raiz->der->der->der = new Nodo("REDES");

    imprimirJerarquia(raiz);

    return 0;
}