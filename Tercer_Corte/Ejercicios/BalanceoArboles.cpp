//Balanceo de árboles: introducción y rotaciones AVL
//8, 10, 12, 15, 17, 20, 25
//AVL adelson-velsky-landis

/*int  alt(Nodo* n)    { return n == nullptr ? -1 : n->alt; }
int  fe(Nodo* n)     { return n == nullptr ? 0 : alt(n->izq) - alt(n->der); }
void recalc(Nodo* n) { n->alt = 1 + max(alt(n->izq), alt(n->der)); }*/

// fe > 0   -> pesa la izquierda
// fe < 0   -> pesa la derecha
// abs(fe) > 1 -> hay que rotar


/*
fe +2  +1 nodo  LL izquierda-izquierda rotacion derecha
fe -2 -1nodo RR derecha-derecha  rotacion a la izquierda
fe +2 -1  nodo LR izquierda-derecha  rotacion izquierda sobre el hijo y luego derecha sobre el nodo
fe -2 +1  nodo RL derecha -izquierda rotacion derecha sobre el hijo y luego a la izquierda sobre el nodo 

*/

//10,20,30
/*
1. implementar alt fe recalc
2. implementar rotar a la derecha y rotar a la izquierda respetando el orden de recal
3. construir los 4 arboles desbalanceados y aplicamos la rotacion que corresponda
4. imprimir el preorden con fe de cada nodo antes y despues y el inorden de cada paso
5. comprobar que el inorden es 10,20,30 en todos los 4 casos
*/
    