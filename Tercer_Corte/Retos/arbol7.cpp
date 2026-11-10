#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Nodo {
public:
    int clave;
    Nodo* izq;
    Nodo* der;
    int alt;

    // Constructor
    Nodo(int c) {
        clave = c;
        izq = nullptr;
        der = nullptr;
        alt = 0;
    }
};

// Declaraciones previas
int alt(Nodo* n);
int fe(Nodo* n);
void recalc(Nodo* n);
Nodo* rotarDerecha(Nodo* y);
Nodo* rotarIzquierda(Nodo* x);

Nodo* insertar(Nodo* n, int clave) {
    if (n == nullptr) return new Nodo(clave);
    if (clave < n->clave) {
        n->izq = insertar(n->izq, clave);
    } else if (clave > n->clave) {
        n->der = insertar(n->der, clave);
    }
    
    recalc(n);
    
    if (fe(n) == 2) {
        if (fe(n->izq) < 0) {
            n->izq = rotarIzquierda(n->izq);
        }
        return rotarDerecha(n);
    }
    if (fe(n) == -2) {
        if (fe(n->der) > 0) {
            n->der = rotarDerecha(n->der);
        }
        return rotarIzquierda(n);
    }
    return n;
}

Nodo* buscar(Nodo* n, int clave, vector<string>* pasos = nullptr) {
    if (pasos != nullptr) {
        pasos->push_back(n == nullptr ? "vacio" : to_string(n->clave));
    }
    if (n == nullptr || n->clave == clave) return n;
    return (clave < n->clave) ? buscar(n->izq, clave, pasos) : buscar(n->der, clave, pasos);
}

int alt(Nodo* n) {
    return (n == nullptr) ? -1 : n->alt;
}

int fe(Nodo* n) {
    return (n == nullptr) ? 0 : alt(n->izq) - alt(n->der);
}

void recalc(Nodo* n) {
    n->alt = 1 + max(alt(n->izq), alt(n->der));
}

Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* B = x->der;
    
    x->der = y;
    y->izq = B;
    
    recalc(y);
    recalc(x);
    
    return x;
}

Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* B = y->izq;
    
    y->izq = x;
    x->der = B;
    
    recalc(x);
    recalc(y);
    
    return y;
}

void inorden(Nodo* n, vector<int>& s) {
    if (n == nullptr) return;
    inorden(n->izq, s);
    s.push_back(n->clave);
    inorden(n->der, s);
}

void preorden(Nodo* n, vector<string>& s) {
    if (n == nullptr) return;
    s.push_back(to_string(n->clave) + "(fe=" + to_string(fe(n)) + ")");
    preorden(n->izq, s);
    preorden(n->der, s);
}

void ver(string titulo, Nodo* raiz) {
    vector<string> s;
    preorden(raiz, s);
    vector<int> t;
    inorden(raiz, t);
    
    cout << left << setw(22) << titulo << " preorden: ";
    for (const string& str : s) cout << str;
    cout << endl;
    
    cout << left << setw(22) << "" << " inorden: [";
    for (size_t i = 0; i < t.size(); ++i) {
        cout << t[i] << (i + 1 < t.size() ? ", " : "");
    }
    cout << "] altura=" << alt(raiz) << endl;
}

Nodo* leerclaves(int n) {
    Nodo* raiz = nullptr;
    for (int i = 0; i < n; ++i) {
        int clave;
        cout << "Ingrese la clave del nodo: ";
        cin >> clave;
        raiz = insertar(raiz, clave);
    }
    return raiz;
}

string tipo_rotacion(Nodo* n) {
    if (n == nullptr) return "Balanceado";
    if (fe(n) == 2) {
        if (fe(n->izq) < 0) return "RL";
        return "LL";
    }
    if (fe(n) == -2) {
        if (fe(n->der) > 0) return "LR";
        return "RR";
    }
    return "Balanceado";
}

int main() {
    cout << "Arbol AVL / Balanceado" << endl;
    int n;
    cout << "Ingrese el número de nodos: ";
    cin >> n;
    
    Nodo* raiz = leerclaves(n);
    ver("Árbol AVL", raiz);
    cout << "Tipo de rotación: " << tipo_rotacion(raiz) << endl;

    return 0;
}