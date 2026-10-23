/*
#include <iostream>
#include <vector>
using namespace std;
    int contar(const vector<int>& v, int n, int umbral) {
    if (n < 0) return 0; // (1)
        if (v[n] >= umbral) // (2)
            return 1 + contar(v, n - 1, umbral);
        return contar(v, n - 1, umbral);
}
int main() {
    vector<int> v = {12, 45, 7, 38, 60, 19, 23};
    int umbral = 20;
    cout << contar(v, v.size() - 1, umbral) << endl;
    return 0;
}
*/
/*Defecto (2): acceso fuera de rango. Con n = 7 la función lee v[7], pero los índices válidos
son 0 a 6. En C++ operator[] no verifica límites: es comportamiento indefinido (puede
leer basura, dar un resultado erróneo o fallar). Además, el elemento v[6] = 23, que sí debía
contarse, solo se evalúa si n llega a 6; el diseño mezcla dos significados de n.
Defecto (1): caso base inconsistente. Aquí n significa cantidad de elementos, así que el
caso base correcto es n == 0 (o n <= 0): con cero elementos no hay nada que contar. El
caso n < 0 es una llamada a un rango imposible y obliga a procesar v[0] con n = 0 usando el
índice equivocado.
*/
#include <iostream>
#include <vector>
using namespace std;
    int contar(const vector<int>& v, int n, int umbral) {
        if (n <= 0) return 0; // sin elementos: 0
            if (v[n - 1] >= umbral) // último elemento del rango
            return 1 + contar(v, n - 1, umbral);
        return contar(v, n - 1, umbral);
}
int main() {
    vector<int> v = {12, 45, 7, 38, 60, 19, 23};
    int umbral = 20;
    cout << contar(v, v.size(), umbral) << endl;
    return 0;
}
