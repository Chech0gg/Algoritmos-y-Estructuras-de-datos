#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#include <iostream>

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val, Nodo* izq = nullptr, Nodo* der = nullptr)
        : valor(val), izquierdo(izq), derecho(der) {}
};

Nodo* espejo(Nodo* nodo) {
    if (nodo == nullptr) {
        return nullptr;
    }

    Nodo* temp = nodo->izquierdo;
    nodo->izquierdo = nodo->derecho;
    nodo->derecho = temp;

    espejo(nodo->izquierdo);
    espejo(nodo->derecho);

    return nodo;
}

void imprimirInorden(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }

    imprimirInorden(nodo->izquierdo);
    cout << nodo->valor << " ";
    imprimirInorden(nodo->derecho);
}

void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberarArbol(nodo->izquierdo);
    liberarArbol(nodo->derecho);
    delete nodo;
}

int main() {
    Nodo* raiz = new Nodo(
        4,
        new Nodo(2, new Nodo(1), new Nodo(3)),
        new Nodo(6, new Nodo(5), new Nodo(7))
    );

    cout << "Inorden original: ";
    imprimirInorden(raiz);
    cout << "\n";

    espejo(raiz);

    cout << "Inorden espejado: ";
    imprimirInorden(raiz);
    cout << "\n";

    liberarArbol(raiz);
    return 0;
}