#include <iostream>
using namespace std;

int main() {
    // 1. DECLARACIÓN DEL ARREGLO
    // Se crea un arreglo (vector) de 4 enteros en posiciones contiguas de memoria:
    // Posición 0: 5 | Posición 1: 3 | Posición 2: 9 | Posición 3: 1
    int v[4] = {5, 3, 9, 1};

    // 2. ASIGNACIÓN DEL PUNTERO
    // El nombre de un arreglo ('v') actúa como un puntero a su primer elemento (v[0]).
    // 'p' guarda la dirección de memoria de v[0] (donde está el número 5).
    int* p = v;

    // 3. ARITMÉTICA DE PUNTEROS Y DESREFERENCIACIÓN
    // (p + 2) avanza 2 posiciones de memoria desde el inicio (pasa de v[0] a v[2]).
    // El operador '*' obtiene el VALOR guardado en esa dirección.
    // *(p + 2) equivale a escribir v[2], que es el número 9.
    cout << *(p + 2);

    return 0;
}