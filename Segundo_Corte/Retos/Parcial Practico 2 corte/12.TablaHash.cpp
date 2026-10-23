
#include <vector>
#include <list>
using namespace std;

const int M = 7;
vector<list<int>> tabla(M); // necesita <vector> y <list>
void insertar(int k) { tabla[k % M].push_back(k); }
bool buscar(int k) {
for (int x : tabla[k % M])
if (x == k) return true;
return false;
}
int main() {
    insertar(10);
    insertar(3);
    insertar(17);
    if (buscar(10)) {
        // encontrado
    }
    if (!buscar(5)) {
        // no encontrado
    }
    return 0;
}
/*Colisiones: 4. Son las inserciones que caen en un bucket ya ocupado: 9 (choca con 23),
36 (choca con 15), 51 (choca con 23 y 9 en el bucket 2) y 28 (choca con 42).
Comprobación: 8 claves - 4 buckets ocupados = 4.
Cadena más larga: 3 (bucket 2).
Factor de carga: α = 8 / 7 ≈ 1,14. Con encadenamiento puede ser mayor que 1; significa
en promedio 1,14 claves por bucket.
Observaciones que suman: tres buckets (4, 5, 6) quedaron vacíos mientras el 2 tiene tres
claves, así que con estas claves h reparte mal; buscar 51 recorre 3 nodos y buscar 17 solo 1.
Si el profesor considera la inserción al inicio de la cadena, el orden dentro de cada bucket
se invierte, pero las longitudes y el conteo no cambian. Si en clase se cuentan pares de
claves en conflicto en vez de inserciones en bucket ocupado, el número sería otro (5
pares); la definición más habitual en estos ejercicios es la de 4, pero declara la tuya.
Extra F-1 (medio, muy típico). Dada una lista de enteros y un objetivo, devuelve los
índices de dos elementos que sumen el objetivo. Hazlo en O(n).
def dos_sumas(nums, objetivo):
vistos = {} # valor -> índice
for i, x in enumerate(nums):
complemento = objetivo - x
if complemento in vistos:
return (vistos[complemento], i)
vistos[x] = i # se guarda DESPUÉS de consultar
return None
Traza con [2, 7, 11, 15] y objetivo 9. i = 0, x = 2: el complemento 7 no está; vistos = {2: 0}. i = 1,
x = 7: el complemento 2 sí está → devuelve (0, 1). Con [3, 3] y objetivo 6: i = 0 guarda {3: 0}; i
= 1 encuentra el complemento 3 → (0, 1). Guardar después de consultar evita emparejar un
elemento consigo mismo. Dos ciclos anidados darían O(n²); el dict lo baja a O(n)
*/
