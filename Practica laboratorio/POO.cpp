#include <iostream>
#include <string>

using namespace std;

// 1. CLASE BASE
class PuntoAcopio {
// 'protected' permite que la clase hija acceda a estas variables sin complicarse
protected: 
    int codigo;
    string barrio;
    double totalRecogido;

public:
    // Constructor
    PuntoAcopio(int c, string b, double t) {
        codigo = c;
        barrio = b;
        totalRecogido = t;
    }

    // Método 1: Sumar kilos
    void registrarRecoleccion(double kilos) {
        totalRecogido = totalRecogido + kilos;
    }

    // Método 2: Revisar meta
    bool superaMeta(double meta) {
        return totalRecogido >= meta;
    }

    // Imprimir datos ('virtual' permite que se sobrescriba)
    virtual void mostrarDescripcion() {
        cout << "Punto " << codigo << " (" << barrio << ") - Total: " << totalRecogido << " kg" << endl;
    }
};

// 2. CLASE HIJA (Hereda de PuntoAcopio)
class MaterialEspecial : public PuntoAcopio {
private:
    string tipo; // Atributo propio

public:
    // Constructor
    MaterialEspecial(int c, string b, double t, string tp) : PuntoAcopio(c, b, t) {
        tipo = tp;
    }

    // Redefinimos el método de la clase padre
    void mostrarDescripcion() override {
        cout << "Punto Especial " << codigo << " (" << barrio << ") - Total: " << totalRecogido << " kg | Tipo: " << tipo << endl;
    }
};

int main() {
    // Arreglo de 4 punteros a la clase base
    PuntoAcopio* centro[4];

    // Creamos los objetos (2 normales y 2 especiales)
    centro[0] = new PuntoAcopio(101, "Centro", 120.5);
    centro[1] = new MaterialEspecial(201, "Norte", 85.0, "Pilas");
    centro[2] = new PuntoAcopio(102, "Sur", 310.0);
    centro[3] = new MaterialEspecial(202, "Occidente", 45.0, "Aceite");

    // Probamos sumar kilos
    centro[0]->registrarRecoleccion(30.0);

    cout << "=== LISTA DE PUNTOS ===" << endl;

    // Recorremos el arreglo
    for (int i = 0; i < 4; i++) {
        centro[i]->mostrarDescripcion(); // Muestra la descripción correspondiente
        
        if (centro[i]->superaMeta(100.0)) {
            cout << "   -> ¡Supero la meta de 100 kg!" << endl;
        } else {
            cout << "   -> No alcanzada la meta." << endl;
        }
    }

    return 0;
}