#include <iostream>
#include <algorithm>
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

Nodo* insertarABB(Nodo* nodo, int clave) {
    if (nodo == nullptr) return new Nodo(clave);
    if (clave < nodo->clave) {
        nodo->izq = insertarABB(nodo->izq, clave);
    } else if (clave > nodo->clave) {
        nodo->der = insertarABB(nodo->der, clave);
    }
    return nodo;
}

int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

int factorEquilibrio(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izq) - altura(nodo->der);
}

Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;

    x->der = y;
    y->izq = T2;
    return x;
}

Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;
    return y;
}

void imprimirArbol(Nodo* nodo, int nivel = 0, const char* rama = "Raiz") {
    if (nodo == nullptr) return;
    for (int i = 0; i < nivel; i++) cout << "    ";
    cout << rama << ": " << nodo->clave << " (FE=" << factorEquilibrio(nodo) << ")\n";
    imprimirArbol(nodo->izq, nivel + 1, "I");
    imprimirArbol(nodo->der, nivel + 1, "D");
}

Nodo* balancearSiNecesario(Nodo* raiz) {
    if (raiz == nullptr) return nullptr;

    int fe = factorEquilibrio(raiz);

    if (fe > 1) {
        int feHijo = factorEquilibrio(raiz->izq);
        cout << "Diagnostico: FE(nodo)=" << fe << ", FE(izq)=" << feHijo << " -> ";
        if (feHijo >= 0) {
            cout << "LL (Rotacion simple a la derecha)\n";
            return rotarDerecha(raiz);
        } else {
            cout << "LR (Rotacion izquierda en hijo izq + rotacion derecha en nodo)\n";
            raiz->izq = rotarIzquierda(raiz->izq);
            return rotarDerecha(raiz);
        }
    }

    if (fe < -1) {
        int feHijo = factorEquilibrio(raiz->der);
        cout << "Diagnostico: FE(nodo)=" << fe << ", FE(der)=" << feHijo << " -> ";
        if (feHijo <= 0) {
            cout << "RR (Rotacion simple a la izquierda)\n";
            return rotarIzquierda(raiz);
        } else {
            cout << "RL (Rotacion derecha en hijo der + rotacion izquierda en nodo)\n";
            raiz->der = rotarDerecha(raiz->der);
            return rotarIzquierda(raiz);
        }
    }

    cout << "Diagnostico: FE(nodo)=" << fe << " -> Equilibrado (sin rotacion)\n";
    return raiz;
}

void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izq);
    liberarArbol(nodo->der);
    delete nodo;
}

int main() {
    int k1, k2, k3;
    cout << "Ingrese tres claves separadas por espacio: ";
    if (!(cin >> k1 >> k2 >> k3)) return 0;

    Nodo* raiz = nullptr;
    raiz = insertarABB(raiz, k1);
    raiz = insertarABB(raiz, k2);
    raiz = insertarABB(raiz, k3);

    cout << "\n--- Arbol ANTES ---\n";
    imprimirArbol(raiz);

    cout << "\n";
    raiz = balancearSiNecesario(raiz);

    cout << "\n--- Arbol DESPUES ---\n";
    imprimirArbol(raiz);

    liberarArbol(raiz);
    return 0;
}