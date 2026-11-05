#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Nodo {
    string dato;
    Nodo* izq;
    Nodo* der;
    Nodo(string d) : dato(d), izq(nullptr), der(nullptr) {}
};

void preorden(Nodo* n, vector<string>& s) {
    if (n == nullptr) return;          // caso base
    s.push_back(n->dato);              // 1) raiz
    preorden(n->izq, s);               // 2) izquierda
    preorden(n->der, s);               // 3) derecha
}
void inorden(Nodo* n, vector<string>& s) {
    if (n == nullptr) return;
    inorden(n->izq, s);
    s.push_back(n->dato);
    inorden(n->der, s);
}
void postorden(Nodo* n, vector<string>& s) {
    if (n == nullptr) return;
    postorden(n->izq, s);
    postorden(n->der, s);
    s.push_back(n->dato);
}
int altura(Nodo* n) {
    if (n == nullptr) return -1;
    return 1 + max(altura(n->izq), altura(n->der));
}
int contar(Nodo* n) {
    if (n == nullptr) return 0;
    return 1 + contar(n->izq) + contar(n->der);
}
int contarHojas(Nodo* n) {
    if (n == nullptr) return 0;
    if (n->izq == nullptr && n->der == nullptr) return 1;
    return contarHojas(n->izq) + contarHojas(n->der);
}
vector<string> porNiveles(Nodo* raiz) {
    vector<string> s;
    if (raiz == nullptr) return s;
    queue<Nodo*> q; q.push(raiz);
    while (!q.empty()) {
        Nodo* n = q.front(); q.pop();
        s.push_back(n->dato);
        if (n->izq) q.push(n->izq);
        if (n->der) q.push(n->der);
    }
    return s;
}
void liberar(Nodo* n) {                // postorden: borrar hijos antes que el padre
    if (n == nullptr) return;
    liberar(n->izq);
    liberar(n->der);
    delete n;
}
void mostrar(const string& titulo, const vector<string>& v) {
    cout << titulo << ": ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << " -> ";
    }
    cout << endl;
}
bool soniguales(Nodo* a, Nodo* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->dato == b->dato && soniguales(a->izq, b->izq) && soniguales(a->der, b->der);
}
int main() {
    Nodo* a = new Nodo("10");
    a->izq = new Nodo("5");
    a->der = new Nodo("15");

    Nodo* b = new Nodo("10");
    b->izq = new Nodo("5");
    b->der = new Nodo("15");

    cout << (soniguales(a, b) ? "true" : "false") << endl;

    liberar(a);
    liberar(b);

    return 0;
}