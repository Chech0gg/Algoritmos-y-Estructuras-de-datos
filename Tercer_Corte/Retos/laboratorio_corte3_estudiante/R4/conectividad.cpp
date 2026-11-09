// ============================================================
//  Laboratorio integrador · Corte 3 · RETO 4  (25 puntos)
//  Sesiones 41 y 43 — DFS, componentes conexas y vias criticas
//  Sistema: RedAcopio — que vias no pueden cerrarse
//
//  Este archivo NO tiene main(): el main esta en pruebas_r4.cpp
//  MODIFIQUE SOLO ESTE ARCHIVO.  NO TOQUE pruebas_r4.cpp ni red.h
//  Compile y ejecute:
//     g++ -std=c++17 -g -o pruebas_r4 conectividad.cpp pruebas_r4.cpp
//     ./pruebas_r4
// ============================================================
#include <vector>
#include <string>
#include "red.h"
using namespace std;

int cuantasComponentes(const vector<vector<int>>& g) {
    // Cuenta en cuantos pedazos esta partida la red.
    // Lance un DFS desde cada vertice que todavia no haya sido visitado;
    // cada DFS que arranca es una componente nueva.
    //
    // Use una PILA explicita (un vector<int> con push_back y pop_back),
    // no recursion.
    //
    // PENDIENTE: implementar.
    return 0;
}

vector<string> viasCriticas() {
    // Una via es CRITICA si al cerrarla la red deja de estar conectada.
    // Para cada arista: arme la red SIN esa arista y cuente componentes.
    // Si pasa de 1 a mas de 1, la via es critica.
    //
    // Devuelva los nombres con el formato  "ORIGEN-DESTINO"
    // respetando el orden en que aparecen en ARISTAS.
    // Ejemplo de formato:  "ACOPIO-NORTE"
    //
    // PENDIENTE: implementar.
    return {};
}
