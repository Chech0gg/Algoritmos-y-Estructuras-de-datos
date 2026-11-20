#include <iostream>
#include <limits>
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

bool esBSTRango(Nodo* nodo, long long minimo, long long maximo) {
    if (nodo == nullptr) return true;

    if (nodo->clave <= minimo || nodo->clave >= maximo) {
        return false;
    }

    return esBSTRango(nodo->izq, minimo, nodo->clave) &&
           esBSTRango(nodo->der, nodo->clave, maximo);
}

bool esBST(Nodo* raiz) {
    return esBSTRango(raiz, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izq);
    liberarArbol(nodo->der);
    delete nodo;
}

int main() {

    Nodo* impostor = new Nodo(50);
    impostor->izq = new Nodo(30);
    impostor->izq->der = new Nodo(60);

    cout << boolalpha;
    cout << "Es BST el contraejemplo: " << esBST(impostor) << "\n";  

    liberarArbol(impostor);

    Nodo* valido = new Nodo(50);
    valido->izq = new Nodo(30);
    valido->izq->izq = new Nodo(20);
    valido->izq->der = new Nodo(40);
    valido->der = new Nodo(70);

    cout << "Es BST el arbol valido: " << esBST(valido) << "\n"; 

    liberarArbol(valido);

    return 0;
}