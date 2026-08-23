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

    string cargo;
    float valorHora;
    float horasTrabajadas;

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

        cout << "Cargo: ";
        cin >> cargo;

        cout << "Valor por hora: ";
        cin >> valorHora;

        cout << "Cantidad de horas trabajadas: ";
        cin >> horasTrabajadas;
    }

    void mostrarPersona()
    {
        cout << "\n--- DATOS DE LA PERSONA ---" << endl;

        cout << "Tipo de documento: " << tipoDoc << endl;
        cout << "Documento: " << documento << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Valor por hora: " << valorHora << endl;
        cout << "Cantidad de horas trabajadas: " << horasTrabajadas << endl;
    }

    void calcularHonorarios()
    {
        float total1;
        float total2;

        total1 = valorHora * horasTrabajadas;

        total2 = total1 + (total1 * 996 / 1000);

        cout << "El total a pagar es: " << total2 << endl;
    }
};

int main()
{
    Persona empleado;

    empleado.pedirDatos();
    empleado.mostrarPersona();
    empleado.calcularHonorarios();

    return 0;
}