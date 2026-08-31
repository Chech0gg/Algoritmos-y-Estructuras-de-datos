#include <iostream>
using namespace std;
int main () {
    int numero, *dir_numero;
    cout << "ingrese el numero : ";
    cin >> numero;
    dir_numero = &numero; // se guarda la dir de memoria
    if (*dir_numero % 2 == 0) {
        cout << "el numero es par" << endl;
        cout << "la direccion de memoria es:" << dir_numero << endl;
    }
    else {
        cout << "el numero es impar" << endl;
        cout << "la direccion de memoria es:" << dir_numero << endl;
    }
    return 0;
}
