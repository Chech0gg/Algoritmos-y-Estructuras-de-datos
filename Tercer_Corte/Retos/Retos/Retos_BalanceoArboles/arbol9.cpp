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

int altura(Nodo* n) {
    if (n == nullptr) return -1;
    int a = altura(n->izq);
    int b = altura(n->der);
    return 1 + (a > b ? a : b);
}

int fe(Nodo* n) {
    if (n == nullptr) return 0;
    return altura(n->izq) - altura(n->der);
}

Nodo* rotarIzq(Nodo* x) {
    Nodo* y = x->der;
    Nodo* t2 = y->izq;
    y->izq = x;
    x->der = t2;
    return y;
}

Nodo* rotarDer(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* t2 = x->der;
    x->der = y;
    y->izq = t2;
    return x;
}

Nodo* rebalancearNodo(Nodo* n, bool& roto) {
    roto = false;
    if (n == nullptr) return nullptr;

    int balance = fe(n);
    if (balance > 1) {
        roto = true;
        if (fe(n->izq) < 0) n->izq = rotarIzq(n->izq);
        return rotarDer(n);
    }
    if (balance < -1) {
        roto = true;
        if (fe(n->der) > 0) n->der = rotarDer(n->der);
        return rotarIzq(n);
    }
    return n;
}
Nodo* eliminarSoloPrimeraRotacion(Nodo* raiz, int clave, bool& yaRoto) {
    if (raiz == nullptr) return nullptr;

    if (clave < raiz->clave) {
        raiz->izq = eliminarSoloPrimeraRotacion(raiz->izq, clave, yaRoto);
    } else if (clave > raiz->clave) {
        raiz->der = eliminarSoloPrimeraRotacion(raiz->der, clave, yaRoto);
    } else {
        if (raiz->izq == nullptr || raiz->der == nullptr) {
            Nodo* temp = (raiz->izq != nullptr) ? raiz->izq : raiz->der;
            delete raiz;
            return temp;
        }
        Nodo* suc = raiz->der;
        while (suc->izq != nullptr) suc = suc->izq;
        raiz->clave = suc->clave;
        raiz->der = eliminarSoloPrimeraRotacion(raiz->der, suc->clave, yaRoto);
    }

    if (!yaRoto) {
        bool rotoAhora = false;
        raiz = rebalancearNodo(raiz, rotoAhora);
        if (rotoAhora) {
            yaRoto = true;
            cout << "Rotacion aplicada en nodo con clave " << raiz->clave
                 << " (nueva altura de este subarbol: " << altura(raiz) << ")\n";
        }
    }
    return raiz;
}

void mostrarFE(Nodo* n) {
    if (n == nullptr) return;
    cout << "Nodo " << n->clave << " -> alt=" << altura(n) << ", FE=" << fe(n) << "\n";
    mostrarFE(n->izq);
    mostrarFE(n->der);
}

void liberar(Nodo* n) {
    if (n == nullptr) return;
    liberar(n->izq);
    liberar(n->der);
    delete n;
}

int main() {
    // Construimos el ejemplo donde al eliminar 50 rota el subarbol de 60 -> 80
    Nodo* raiz = new Nodo(40);
    raiz->izq = new Nodo(20);
    raiz->izq->izq = new Nodo(10);
    raiz->izq->izq->izq = new Nodo(5);

    raiz->der = new Nodo(60);
    raiz->der->izq = new Nodo(50);
    raiz->der->der = new Nodo(80);
    raiz->der->der->der = new Nodo(90);

    bool yaRoto = false;
    raiz = eliminarSoloPrimeraRotacion(raiz, 50, yaRoto);

    cout << "\nEstado tras aplicar SOLO la primera rotacion:\n";
    mostrarFE(raiz);

    liberar(raiz);
    return 0;
}