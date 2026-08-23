/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Persona
{
private:
    string tipoDoc;
    string documento;
    string nombre;
    string apellido;
    float peso;
    float estatura;
    int edad;
    string sexo;

public:

    void pedirDatos()
    {
        cout << "Tipo de documento: ";
        cin >> tipoDoc;
        cout << "Documento: ";
        cin >> documento;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Peso en kg: ";
        cin >> peso;
        cout << "Estatura en metros: ";
        cin >> estatura;
        cout << "Edad: ";
        cin >> edad;
        cout << "Sexo: ";
        cin >> sexo;
    }

    void mostrarPersona()
    {
        cout << "Tipo de documento: " << tipoDoc << endl;
        cout << "Documento: " << documento << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Estatura: " << estatura << " m" << endl;
        cout << "Edad: " << edad << endl;
        cout << "Sexo: " << sexo << endl;
    }

    void calcularImc()
    {
        float imc;
        imc = peso / (estatura * estatura);
        cout << "\nIMC: " << imc << endl;
        if (imc < 20)
        {
            cout << "El peso esta por debajo de lo ideal" << endl;
        }
        else if (imc <= 25)
        {
            cout << "El peso es ideal" << endl;
        }
        else
        {
            cout << "Tiene sobrepeso" << endl;
        }
    }

    void mayorEdad()
    {
        if (edad >= 18)
        {
            cout << "Es mayor de edad" << endl;
        }
        else
        {
            cout << "No es mayor de edad" << endl;
        }
    }
};

int main()
{
    Persona persona;
    persona.pedirDatos();
    persona.mostrarPersona();
    persona.calcularImc();
    persona.mayorEdad();

    return 0;
}