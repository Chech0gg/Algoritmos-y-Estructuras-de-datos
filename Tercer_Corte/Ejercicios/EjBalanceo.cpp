#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo {
    int clave; Nodo *izq, *der; int alt;
    Nodo(int c) : clave(c), izq(nullptr), der(nullptr), alt(0) {}
};
int  alt(Nodo* n)   { return n == nullptr ? -1 : n->alt; }
int  fe(Nodo* n)    { return n == nullptr ? 0 : alt(n->izq) - alt(n->der); }
void recalc(Nodo* n){ n->alt = 1 + max(alt(n->izq), alt(n->der)); }

Nodo* rotarDerecha(Nodo* y) {
    //        y                x
    //       / \              / \
    //      x   C    ==>     A   y
    //     / \                  / \
    //    A   B                B   C
    Nodo* x = y->izq; Nodo* B = x->der;
    x->der = y; y->izq = B;
    recalc(y); recalc(x);        // primero el que baja, luego el que sube
    return x;
}
Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der; Nodo* B = y->izq;
    y->izq = x; x->der = B;
    recalc(x); recalc(y);
    return y;
}
void inorden(Nodo* n, vector<int>& s) {
    if (!n) return; inorden(n->izq, s); s.push_back(n->clave); inorden(n->der, s);
}
void preorden(Nodo* n, vector<string>& s) {
    if (!n) return;
    s.push_back(to_string(n->clave) + "(fe=" + to_string(fe(n)) + ")");
    preorden(n->izq, s); preorden(n->der, s);
}
void liberar(Nodo* n) { if (!n) return; liberar(n->izq); liberar(n->der); delete n; }

void ver(const string& titulo, Nodo* r) {
    vector<string> s; preorden(r, s);
    vector<int> t; inorden(r, t);
    cout << "  " << titulo; for (size_t i = titulo.size(); i < 22; i++) cout << ' ';
    cout << " preorden: "; for (auto& x : s) cout << x << ' ';
    cout << "\n  "; for (int i = 0; i < 22; i++) cout << ' ';
    cout << " inorden : [";
    for (size_t i = 0; i < t.size(); i++) { cout << t[i]; if (i + 1 < t.size()) cout << ", "; }
    cout << "]   altura=" << alt(r) << endl;
}

int main() {
    cout << "CASO LL  (pesado a la izquierda-izquierda)  ->  una rotacion DERECHA" << endl;
    Nodo* r = new Nodo(30); r->izq = new Nodo(20); r->izq->izq = new Nodo(10);
    recalc(r->izq->izq); recalc(r->izq); recalc(r);
    ver("antes (fe raiz = 2)", r); r = rotarDerecha(r); ver("despues", r); liberar(r);

    cout << "\nCASO RR  (pesado a la derecha-derecha)      ->  una rotacion IZQUIERDA" << endl;
    r = new Nodo(10); r->der = new Nodo(20); r->der->der = new Nodo(30);
    recalc(r->der->der); recalc(r->der); recalc(r);
    ver("antes (fe raiz = -2)", r); r = rotarIzquierda(r); ver("despues", r); liberar(r);

    cout << "\nCASO LR  (izquierda-derecha)  ->  IZQUIERDA sobre el hijo, luego DERECHA sobre la raiz" << endl;
    r = new Nodo(30); r->izq = new Nodo(10); r->izq->der = new Nodo(20);
    recalc(r->izq->der); recalc(r->izq); recalc(r);
    ver("antes (fe raiz = 2)", r);
    r->izq = rotarIzquierda(r->izq); recalc(r); ver("tras rotar el hijo", r);
    r = rotarDerecha(r); ver("despues", r); liberar(r);

    cout << "\nCASO RL  (derecha-izquierda) ->  DERECHA sobre el hijo, luego IZQUIERDA sobre la raiz" << endl;
    r = new Nodo(10); r->der = new Nodo(30); r->der->izq = new Nodo(20);
    recalc(r->der->izq); recalc(r->der); recalc(r);
    ver("antes (fe raiz = -2)", r);
    r->der = rotarDerecha(r->der); recalc(r); ver("tras rotar el hijo", r);
    r = rotarIzquierda(r); ver("despues", r); liberar(r);
    return 0;
}