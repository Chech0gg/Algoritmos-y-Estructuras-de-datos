#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo {
    int clave; string nombre;
    Nodo *izq, *der;
    Nodo(int c, string n = "") : clave(c), nombre(n), izq(nullptr), der(nullptr) {}
};

Nodo* insertar(Nodo* n, int clave, string nombre = "") {
    if (n == nullptr) return new Nodo(clave, nombre);
    if (clave < n->clave)      n->izq = insertar(n->izq, clave, nombre);
    else if (clave > n->clave) n->der = insertar(n->der, clave, nombre);
    return n;                                  // clave repetida: no se inserta
}
Nodo* buscar(Nodo* n, int clave, vector<string>* pasos = nullptr) {
    if (pasos) pasos->push_back(n == nullptr ? "vacio" : to_string(n->clave));
    if (n == nullptr || n->clave == clave) return n;
    return clave < n->clave ? buscar(n->izq, clave, pasos) : buscar(n->der, clave, pasos);
}
Nodo* minimo(Nodo* n) { while (n->izq) n = n->izq; return n; }
Nodo* maximo(Nodo* n) { while (n->der) n = n->der; return n; }

Nodo* eliminar(Nodo* n, int clave) {
    if (n == nullptr) return nullptr;
    if (clave < n->clave)      n->izq = eliminar(n->izq, clave);
    else if (clave > n->clave) n->der = eliminar(n->der, clave);
    else {
        if (n->izq == nullptr) { Nodo* d = n->der; delete n; return d; }   // 0 o 1 hijo
        if (n->der == nullptr) { Nodo* i = n->izq; delete n; return i; }
        Nodo* suc = minimo(n->der);                                        // 2 hijos
        n->clave = suc->clave; n->nombre = suc->nombre;
        n->der = eliminar(n->der, suc->clave);
    }
    return n;
}
void inorden(Nodo* n, vector<int>& s) {
    if (n == nullptr) return;
    inorden(n->izq, s); s.push_back(n->clave); inorden(n->der, s);
}
int altura(Nodo* n) { return n == nullptr ? -1 : 1 + max(altura(n->izq), altura(n->der)); }
int hijos(Nodo* raiz, int clave) {
    Nodo* n = buscar(raiz, clave);
    if (n == nullptr) return -1;
    return (n->izq ? 1 : 0) + (n->der ? 1 : 0);
}
void liberar(Nodo* n) { if (!n) return; liberar(n->izq); liberar(n->der); delete n; }
void verLista(const string& t, const vector<int>& v) {
    cout << t << " [";
    for (size_t i = 0; i < v.size(); i++) { cout << v[i]; if (i + 1 < v.size()) cout << ", "; }
    cout << "]" << endl;
}

int main() {
    Nodo* raiz = nullptr;
    vector<int> n;
    int x;
    cout << "Ingrese el recurso: ";
    cin >> x;
    for (int i = 0; i < x; i++) {
        int clave;
        string nombre;
        cout << "Ingrese la clave del recurso: ";
        cin >> clave;
        cout << "Ingrese el nombre del recurso: ";
        cin >> nombre;
        raiz = insertar(raiz, clave, nombre);
        n.push_back(clave);
        if (raiz == nullptr) {
            cout << "No se pudo insertar la clave: " << clave << endl;
        }
    }

    verLista("Claves ingresadas", n);
    vector<int> s;
    inorden(raiz, s);
    verLista("Claves en orden", s);

    liberar(raiz);
    return 0;
}