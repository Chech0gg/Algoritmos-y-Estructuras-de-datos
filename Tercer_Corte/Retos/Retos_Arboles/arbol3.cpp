#include <iostream>
#include<vector>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) {
        dato = val;
        izq = nullptr;
        der = nullptr;
    }
};

bool sonIguales(Nodo* a, Nodo* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->dato == b->dato && sonIguales(a->izq, b->izq) && sonIguales(a->der, b->der);
}

Nodo* espejo(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;
    Nodo* temp = nodo->izq;
    nodo->izq = nodo->der;
    nodo->der = temp;

    espejo(nodo->izq);
    espejo(nodo->der);
    return nodo;
}

Nodo* mismo(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;
    Nodo* nuevo = new Nodo(nodo->dato);
    nuevo->izq = mismo(nodo->izq);
    nuevo->der = mismo(nodo->der);
    return nuevo;
}

void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izq);
    liberarArbol(nodo->der);
    delete nodo;
}

int main() {
    Nodo* a = new Nodo(4);
    a->izq = new Nodo(2);
    a->der = new Nodo(6);

    Nodo* b = new Nodo(4);
    b->izq = new Nodo(2);
    b->der = new Nodo(6);

    cout << boolalpha;
    cout << sonIguales(a, b) << "\n";  // true

    Nodo* c = espejo(mismo(a));
    cout << sonIguales(a, c) << "\n";  // false

    liberarArbol(a);
    liberarArbol(b);
    liberarArbol(c);
    return 0;
}