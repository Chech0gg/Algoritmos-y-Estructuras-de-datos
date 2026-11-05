/* Quiz 28/10/26  */
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

Nodo* insertar(Nodo* n, int clave, string nombre="") {
    if(n==nullptr) return new Nodo(clave, nombre);
    if (clave < n->clave) n->izq = insertar(n->izq, clave, nombre);
    else if (clave > n->clave) n->der = insertar(n->der, clave, nombre);
    return n;
}
void inorden(Nodo* n, vector<int>& s) {
    if (n == nullptr) return;
    inorden(n->izq, s);
    s.push_back(n->clave);
    inorden(n->der, s);
}
Nodo* minimo(Nodo* n) {
    if (n == nullptr) return nullptr;
    while (n->izq) n = n->izq;
    return n;
}
Nodo* maximo(Nodo* n) {
    if (n == nullptr) return nullptr;
    while (n->der) n = n->der;
    return n;
}
int altura(Nodo* n) {
    if (n == nullptr) return -1;
    return 1 + max(altura(n->izq), altura(n->der));
}
Nodo* buscar(Nodo* n, int clave, vector<string>* p = nullptr) {
    if (n == nullptr) return nullptr;
    if (p) p->push_back(to_string(n->clave));
    if (clave == n->clave) return n;
    if (clave < n->clave) return buscar(n->izq, clave, p);
    return buscar(n->der, clave, p);
}
int hijos(Nodo* n, int clave) {
    Nodo* r = buscar(n, clave);
    if (!r) return -1;
    int c = 0;
    if (r->izq) c++;
    if (r->der) c++;
    return c;
}
Nodo* eliminar(Nodo* n, int clave) {
    if (n == nullptr) return nullptr;
    if (clave < n->clave) n->izq = eliminar(n->izq, clave);
    else if (clave > n->clave) n->der = eliminar(n->der, clave);
    else {
        if (!n->izq) { Nodo* tmp = n->der; delete n; return tmp; }
        if (!n->der) { Nodo* tmp = n->izq; delete n; return tmp; }
        Nodo* tmp = minimo(n->der);
        n->clave = tmp->clave;
        n->nombre = tmp->nombre;
        n->der = eliminar(n->der, tmp->clave);
    }
    return n;
}
void liberar(Nodo* n) {
    if (!n) return;
    liberar(n->izq);
    liberar(n->der);
    delete n;
}
void verLista(const string& titulo, const vector<int>& v) {
    cout << titulo << ": ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << " -> ";
    }
    cout << endl;
}




int main() {
    Nodo* raiz = nullptr;
    for (int c : {50, 30, 70, 20, 40, 60, 80, 35}) raiz = insertar(raiz, c);
    vector<int> s; inorden(raiz, s);
    verLista("Inorden (queda ordenado):", s);

    cout << "minimo = " << minimo(raiz)->clave << "  maximo = " << maximo(raiz)->clave
         << "  altura = " << altura(raiz) << endl;

    for (int objetivo : {40, 65}) {
        vector<string> p; Nodo* r = buscar(raiz, objetivo, &p);
        cout << "buscar(" << objetivo << "): camino ";
        for (size_t i = 0; i < p.size(); i++) { cout << p[i]; if (i + 1 < p.size()) cout << " -> "; }
        cout << "  =>  " << (r ? "ENCONTRADO" : "NO ESTA")
             << "  (" << p.size() << " comparaciones)" << endl;
    }

    const char* NOMBRE[] = {"caso 1: hoja, 0 hijos", "caso 2: un hijo", "caso 3: dos hijos"};
    for (int clave : {20, 30, 50}) {
        int k = hijos(raiz, clave);                 // se mide, no se supone
        raiz = eliminar(raiz, clave);
        s.clear(); inorden(raiz, s);
        cout << "eliminar(" << clave << ") [" << NOMBRE[k] << "] -> ";
        verLista("", s);
    }

    Nodo* deg = nullptr;
    for (int c : {10, 20, 30, 40, 50, 60, 70, 80}) deg = insertar(deg, c);
    cout << "\nBST con datos ordenados: altura = " << altura(deg) << " con 8 nodos (una lista enlazada)" << endl;
    cout << "BST con datos mezclados: altura = 3 con 8 nodos (log2(8) = 3)" << endl;

    liberar(raiz); liberar(deg);
    return 0;
}

