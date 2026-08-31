#include <iostream>
using namespace std;

int main() {
    // Definición de la matriz (4 puntos x 6 días)
    double recoleccion[4][6] = {
        {120.5, 80.0,  0.0, 150.2, 200.0, 90.5},  // Punto 1
        { 95.0, 110.0, 85.5,   0.0, 130.0, 75.0},  // Punto 2
        {  0.0, 140.0, 160.0, 175.5, 210.0, 0.0},  // Punto 3
        {100.0,  90.0, 105.0,  80.0, 120.0, 60.0}   // Punto 4
    };

    double totalPuntos[4] = {0};
    double totalDias[6] = {0};
    int diasSinOperacion = 0;

    // Procesamiento de datos mediante ciclos anidados
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            double peso = recoleccion[i][j];

            // Acumular totales
            totalPuntos[i] += peso;
            totalDias[j] += peso;

            // Contar días sin operación
            if (peso == 0.0) {
                diasSinOperacion++;
            }
        }
    }

    // Identificar el punto más productivo
    int puntoMasProductivo = 0;
    for (int i = 1; i < 4; i++) {
        if (totalPuntos[i] > totalPuntos[puntoMasProductivo]) {
            puntoMasProductivo = i;
        }
    }

    // Identificar el día con menor recolección
    int diaMenorRecoleccion = 0;
    for (int j = 1; j < 6; j++) {
        if (totalDias[j] < totalDias[diaMenorRecoleccion]) {
            diaMenorRecoleccion = j;
        }
    }

    // Impresión del informe
    cout << "=== INFORME DE RECICLAJE COMUNITARIO ===" << endl << endl;

    cout << "1. Total por punto de acopio:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "   - Punto " << (i + 1) << ": " << totalPuntos[i] << " kg" << endl;
    }

    cout << endl << "2. Total por dia:" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "   - Dia " << (j + 1) << ": " << totalDias[j] << " kg" << endl;
    }

    cout << endl << "3. Punto mas productivo: Punto " << (puntoMasProductivo + 1) 
         << " (" << totalPuntos[puntoMasProductivo] << " kg)" << endl;

    cout << "4. Dia de menor recoleccion: Dia " << (diaMenorRecoleccion + 1) 
         << " (" << totalDias[diaMenorRecoleccion] << " kg)" << endl;

    cout << "5. Registros sin operacion (0 kg): " << diasSinOperacion << " dias/puntos" << endl;

    return 0;
}
