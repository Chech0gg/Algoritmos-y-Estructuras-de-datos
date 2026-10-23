#include <iostream>
using namespace std;

class ColaCircular {
private:
    int CAP = 5; // Capacidad máxima de ejemplo
    int frente = 0;
    int cantidad = 0;
    int datos[5];

public:
    bool encolar(int x) {
        if (cantidad >= CAP) return false; // desbordamiento
        int final = (frente + cantidad) % CAP;
        datos[final] = x;
        ++cantidad;
        return true;
    }

    bool desencolar() {
        if (cantidad == 0) return false; // subdesbordamiento
        frente = (frente + 1) % CAP;
        --cantidad;
        return true;
    }

    // Método para imprimir los elementos actuales de la cola
    void imprimir() {
        cout << "Cola actual: [ ";
        for (int i = 0; i < cantidad; i++) {
            int indice = (frente + i) % CAP;
            cout << datos[indice] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    ColaCircular cola;
    
    // Llenamos la cola hasta su capacidad máxima (5 elementos)
    cout << "--- Llenando la cola ---" << endl;
    cola.encolar(11); 
    cola.encolar(22); 
    cola.encolar(33);
    cola.encolar(44);
    cola.encolar(55);
    
    cola.imprimir(); // Muestra los 5 elementos
    
    // Intentamos encolar un elemento extra (Aquí ocurre el desbordamiento)
    cout << "\n--- Intentando insertar un elemento extra ---" << endl;
    if (cola.encolar(99) == false) {
        cout << "¡Alerta de desbordamiento (Overflow)! No se pudo insertar el 99 porque la cola esta llena." << endl;
    }
    
    cout << "\nEstado final de la cola:" << endl;
    cola.imprimir(); 
    
    return 0;
}