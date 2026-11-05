/* Nodo* insertar(Nodo* n, int clave) {
    if (n == nullptr) return new Nodo(clave);
    if (clave < n->clave)      n->izq = insertar(n->izq, clave);
    else if (clave > n->clave) n->der = insertar(n->der, clave);
    return n;                        // clave repetida: no se inserta
}*/