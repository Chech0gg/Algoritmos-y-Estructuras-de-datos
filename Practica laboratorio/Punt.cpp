#include <iostream>
using namespace std;

int main() {
    int cantidad;

    // 1. Pedir tamaño al usuario
    cout << "Ingrese la cantidad de nuevos puntos de acopio: ";
    cin >> cantidad;

    // Validación básica de entrada
    if (cantidad <= 0) {
        cout << "Cantidad no valida." << endl;
        return 0;
    }

    // 2. Reserva dinamica de memoria
    double* nuevos_puntos = new double[cantidad];

    // 3. Llenar el arreglo utilizando aritmetica de punteros
    cout << "\n--- Registro de pesos para la jornada especial ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese el peso del nuevo punto " << (i + 1) << ": ";
        // (nuevos_puntos + i) calcula la direccion de memoria de la casilla i
        cin >> *(nuevos_puntos + i); 
    }

    // 4. Calcular el promedio recorriendo con aritmetica de punteros
    double suma = 0.0;
    double* ptr = nuevos_puntos; // Puntero auxiliar que apunta al inicio

    for (int i = 0; i < cantidad; i++) {
        suma += *ptr; // Se obtiene el valor apuntado
        ptr++;        // Se avanza a la siguiente posicion de memoria
    }

    double promedio = suma / cantidad;
    cout << "\nEl promedio de recoleccion en la jornada especial es: " << promedio << " kg" << endl;

    // 5. Liberar memoria correctamente
    delete[] nuevos_puntos;
    nuevos_puntos = nullptr; // Evitar puntero colgante

    return 0;
}