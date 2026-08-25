/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>

using namespace std;

int main() {

    int cantidadProductos;
    int cantidad;
    string nombre;

    double precio;
    double subtotal;
    double total = 0;
    double descuento;
    double totalPagar;

    cout << "Cuantos productos va a comprar: ";
    cin >> cantidadProductos;

    for (int i = 1; i <= cantidadProductos; i++) {

        cout << "\nProducto " << i << endl;

        cout << "Nombre del producto: ";
        cin >> nombre;

        cout << "Precio unitario: ";
        cin >> precio;

        cout << "Cantidad comprada: ";
        cin >> cantidad;

        subtotal = precio * cantidad;

        cout << "Subtotal: $" << subtotal << endl;

        total = total + subtotal;
    }

    cout << "\nTotal antes del descuento: $" << total << endl;

    if (total > 300000) {

        descuento = total * 0.10;

    } else if (total >= 150000) {

        descuento = total * 0.05;

    } else {

        descuento = 0;
    }

    totalPagar = total - descuento;

    cout << "Descuento aplicado: $" << descuento << endl;
    cout << "Total a pagar: $" << totalPagar << endl;

    return 0;
}