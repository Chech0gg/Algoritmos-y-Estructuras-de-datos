/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    double compra, descuento, total;
    int bolita;

    srand(time(0));

    cout << "Ingrese el valor de su compra: ";
    cin >> compra;

    if (compra > 50000) {

        bolita = rand() % 4 + 1;

        if (bolita == 1) {

            descuento = compra * 0.10;
            cout << "Bolita roja" << endl;
            cout << "Descuento: 10%" << endl;

        } else if (bolita == 2) {

            descuento = compra * 0.30;
            cout << "Bolita azul" << endl;
            cout << "Descuento: 30%" << endl;

        } else if (bolita == 3) {

            descuento = compra * 0.50;
            cout << "Bolita amarilla" << endl;
            cout << "Descuento: 50%" << endl;

        } else {

            descuento = compra;
            cout << "Bolita blanca" << endl;
            cout << "Descuento: 100%" << endl;
        }

        total = compra - descuento;

        cout << "Valor del descuento: $" << descuento << endl;
        cout << "Total a pagar: $" << total << endl;

    } else {

        cout << "La compra no supera los $50.000." << endl;
        cout << "No tiene descuento." << endl;
        cout << "Total a pagar: $" << compra << endl;
    }

    return 0;
}