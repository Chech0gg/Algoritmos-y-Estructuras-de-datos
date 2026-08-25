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

    int dado1, dado2, suma;

    srand(time(0));

    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;

    suma = dado1 + dado2;

    cout << "Dado 1: " << dado1 << endl;
    cout << "Dado 2: " << dado2 << endl;
    cout << "Suma: " << suma << endl;

    if ((dado1 == 1 && dado2 == 1) ||
        suma == 3 ||
        suma == 11 ||
        suma == 2 ||
        suma == 12 ||
        suma == 7) {

        cout << "GANASTE!" << endl;

    } else {

        cout << "PERDISTE!" << endl;
    }

    return 0;
}