#include <iostream>
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

int contarNodos(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarNodos(nodo->izq) + contarNodos(nodo->der);
}

void enRango(Nodo* nodo, int a, int b, int& visitados) {
    if (nodo == nullptr) return;

    visitados++;

    // Poda izquierda: solo hay valores >= a en la izquierda si clave > a
    if (nodo->clave > a) {
        enRango(nodo->izq, a, b, visitados);
    }

    // Imprimir si la clave está dentro del rango [a, b]
    if (nodo->clave >= a && nodo->clave <= b) {
        cout << nodo->clave << " ";
    }

    // Poda derecha: solo hay valores <= b en la derecha si clave < b
    if (nodo->clave < b) {
        enRango(nodo->der, a, b, visitados);
    }
}

void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izq);
    liberarArbol(nodo->der);
    delete nodo;
}

int main() {
    // Árbol ABB de ejemplo (8 nodos)
    Nodo* raiz = new Nodo(50);
    raiz->izq = new Nodo(35);
    raiz->der = new Nodo(70);
    raiz->izq->izq = new Nodo(20);
    raiz->izq->der = new Nodo(40);
    raiz->der->izq = new Nodo(60);
    raiz->der->der = new Nodo(80);
    raiz->izq->izq->der = new Nodo(30);

    int a = 35;
    int b = 65;
    int visitados = 0;
    int total = contarNodos(raiz);

    cout << "Claves en [" << a << ", " << b << "]: ";
    enRango(raiz, a, b, visitados);
    cout << "\n";

    cout << "Nodos visitados: " << visitados << " de " << total << "\n";
    if (visitados < total) {
        cout << "Poda efectiva: se visitaron menos nodos que el total del arbol.\n";
    }

    liberarArbol(raiz);
    return 0;
}