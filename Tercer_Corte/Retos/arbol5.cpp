#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Nodo {
public:
    int clave;
    string nombre;
    Nodo* izq;
    Nodo* der;

    // Constructor
    Nodo(int c, string nom = "") {
        clave = c;
        nombre = nom;
        izq = nullptr;
        der = nullptr;
    }
};

Nodo* insertar(Nodo* n, int clave, string nombre = "") {
    if (n == nullptr) return new Nodo(clave, nombre);
    if (clave < n->clave) {
        n->izq = insertar(n->izq, clave, nombre); // el retorno se REENGANCHA
    } else if (clave > n->clave) {
        n->der = insertar(n->der, clave, nombre);
    }
    // clave repetida: no se inserta
    return n;
}

Nodo* buscar(Nodo* n, int clave, vector<string>* pasos = nullptr) {
    if (pasos != nullptr) {
        pasos->push_back(n == nullptr ? "vacio" : to_string(n->clave));
    }
    if (n == nullptr || n->clave == clave) return n;
    return (clave < n->clave) ? buscar(n->izq, clave, pasos) : buscar(n->der, clave, pasos);
}

Nodo* minimo(Nodo* n) {
    while (n != nullptr && n->izq != nullptr) {
        n = n->izq;
    }
    return n;
}

Nodo* maximo(Nodo* n) {
    while (n != nullptr && n->der != nullptr) {
        n = n->der;
    }
    return n;
}

Nodo* eliminar(Nodo* n, int clave) {
    if (n == nullptr) return nullptr;
    if (clave < n->clave) {
        n->izq = eliminar(n->izq, clave);
    } else if (clave > n->clave) {
        n->der = eliminar(n->der, clave);
    } else { // encontramos el nodo a eliminar
        if (n->izq == nullptr) {
            Nodo* temp = n->der;
            delete n;
            return temp;
        }
        if (n->der == nullptr) {
            Nodo* temp = n->izq;
            delete n;
            return temp;
        }
        Nodo* suc = minimo(n->der);
        n->clave = suc->clave;
        n->nombre = suc->nombre;
        n->der = eliminar(n->der, suc->clave);
    }
    return n;
}

void inorden(Nodo* n, vector<int>& s) {
    if (n == nullptr) return;
    inorden(n->izq, s);
    s.push_back(n->clave);
    inorden(n->der, s);
}

int altura(Nodo* n) {
    if (n == nullptr) return -1;
    return 1 + max(altura(n->izq), altura(n->der));
}

Nodo* espejoNodo(Nodo* n) {
    if (n == nullptr) return nullptr;
    Nodo* temp = espejoNodo(n->der);
    n->der = espejoNodo(n->izq);
    n->izq = temp;
    return n;
}

int main() {
    cout << "El arbol inorden es :\n";
    Nodo* raiz = nullptr;
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    vector<int> s;
    inorden(raiz, s);

    // Imprimir el vector estilo Python
    cout << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        cout << s[i] << (i + 1 < s.size() ? ", " : "");
    }
    cout << "]\n";

    raiz = espejoNodo(raiz);
    cout << "El arbol inorden espejo es :\n";
    s.clear();
    inorden(raiz, s);

    cout << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        cout << s[i] << (i + 1 < s.size() ? ", " : "");
    }
    cout << "]\n";

    return 0;
}
