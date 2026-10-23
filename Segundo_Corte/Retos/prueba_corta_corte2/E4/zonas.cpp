// ============================================================
//  Prueba corta · Segundo corte · EJERCICIO 4  (25 puntos)
//  Tema: mapas y conjuntos
//  Sistema: RedAcopio — consolidado de recoleccion por zona
//
//  Este archivo NO tiene main(): el main esta en pruebas_e4.cpp
//  NO MODIFIQUE el archivo pruebas_e4.cpp
//  Compile y ejecute:
//     g++ -std=c++17 -g -o pruebas_e4 zonas.cpp pruebas_e4.cpp
//     ./pruebas_e4
// ============================================================
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

// Debe hacer TRES cosas:
//   1. llenar 'totales' con los kilos acumulados por zona
//   2. llenar 'repetidas' con las zonas que aparecen en MAS DE UN registro
//   3. devolver el nombre de la zona con mayor total acumulado
//
// Si 'reg' esta vacio, devuelva la cadena vacia "" y no agregue nada.
//
// PENDIENTE: implementar el cuerpo de la funcion.

string zonaMayor(const vector<pair<string,int>>& reg,
                 map<string,int>& totales,
                 set<string>& repetidas) {
    if (reg.empty()) return ""; // si el registro esta vacio, devolvemos cadena vacia y no hacemos nada
    
    map<string,int> contador; // utilizo el contador para las zonas las cuales estan repetidas
    string zona_max;
    int max_total = 0; // añado el contador para las zonas con mayor total acumulado
    for (const auto& r : reg) {
        const string& zona = r.first;
        int kilos = r.second;
        totales[zona] += kilos; // se suma os diferentes kilos de la zona
        contador[zona]++;       // utilizamos el contador para saber cuantas veces aparece cada zona
        if (contador[zona] > 1) repetidas.insert(zona); // utlizamos metodo insert para agregar la zona al conjunto de repetidas
        // dependiedm del total acumulado de la zona, actualizamos la zona con mayor total si es necesario
        if (totales[zona] > max_total) { // si el total acumulado de la zona es mayor que el maximo registrado s actualiza y se vuelve la zona con mayor total
            max_total = totales[zona];
            zona_max = zona;
        }
    }
    return zona_max;
}

