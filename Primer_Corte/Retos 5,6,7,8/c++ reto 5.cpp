/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double num1, num2;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "\n--- RESULTADOS ---" << endl;

    // Suma
    cout << "Suma: " << num1 + num2 << endl;

    // Resta
    cout << "Resta: " << num1 - num2 << endl;

    // Multiplicacion
    cout << "Multiplicacion: " << num1 * num2 << endl;

    // Division
    if (num2 != 0) {
        cout << "Division: " << num1 / num2 << endl;
    } else {
        cout << "Division: No se puede dividir entre cero" << endl;
    }

    // Raiz cuadrada
    if (num1 >= 0) {
        cout << "Raiz cuadrada de " << num1 << ": " 
             << sqrt(num1) << endl;
    } else {
        cout << "Raiz cuadrada de " << num1 
             << ": No existe en los numeros reales" << endl;
    }

    if (num2 >= 0) {
        cout << "Raiz cuadrada de " << num2 << ": " 
             << sqrt(num2) << endl;
    } else {
        cout << "Raiz cuadrada de " << num2 
             << ": No existe en los numeros reales" << endl;
    }

    // Potenciacion
    cout << num1 << " elevado a " << num2 << ": "
         << pow(num1, num2) << endl;

    return 0;
}