registros = [('vidrio', 12), ('papel', 8), ('vidrio', 5), ('plastico', 20),
('papel', 14), ('metal', 3), ('plastico', 7), ('vidrio', 9)]
totales = {}
for material, kilos in registros:
    totales[material] = totales.get(material, 0) + kilos
mayor = max(totales, key=totales.get)
distintos = {material for material, _ in registros}
print(totales)
print(mayor, totales[mayor])
print(distintos)
#F.1Teoría esencial
#Conjunto (set): colección sin repetidos. Sirve para eliminar duplicados y para preguntar si
#algo pertenece ( x in s , O(1) en promedio). Operaciones: unión a | b , intersección a &
#b , diferencia a - b .
#Mapa (dict): asocia cada clave única con un valor. Sirve para contar, acumular, agrupar e
#indexar: d[clave] = valor , d.get(clave, 0) . Las claves deben ser hashables
#(inmutables: int, str, tuplas de inmutables). Una lista como clave da TypeError .
#Cuándo cada uno: si necesitas guardar un dato por cada clave (kilos por material), un dict.
#Si solo importa saber qué elementos existen, sin dato asociado, un set.
#Tabla hash. Un arreglo de M buckets y una función h(k) que convierte una clave en un
#índice entre 0 y M-1. Si h es buena, buscar, insertar y borrar cuestan O(1) en promedio,
#porque se salta directo al bucket sin recorrer nada.
#Colisión: dos claves distintas con el mismo h(k). Es inevitable (hay más claves posibles
#que buckets), así que toda tabla hash necesita una estrategia.
#Encadenamiento: cada bucket guarda una lista de las claves que cayeron ahí. Insertar
#es O(1); buscar recorre la cadena del bucket.
#Direccionamiento abierto (sondeo lineal): si el bucket está ocupado, prueba (h + 1) %
#M, (h + 2) % M, ... hasta hallar uno libre. Puede formar bloques seguidos de casillas
#ocupadas (agrupamiento primario). Para borrar hay que dejar una marca especial; si se
#vaciara la casilla sin más, se cortaría el camino de otras claves.
#Factor de carga α = n / M (n = elementos, M = buckets). Con encadenamiento, α es la
#longitud media de cadena y puede superar 1; la búsqueda esperada es O(1 + α). Con
#direccionamiento abierto α debe ser menor que 1, y la tabla se redimensiona (rehash)
#cuando α pasa un umbral.
#Peor caso O(n): si todas las claves caen en el mismo bucket, la tabla degenera en una
#lista enlazada. Por eso se dice O(1) promedio y O(n) peor caso.
#Qué es una buena función hash: determinista, rápida y que reparte las claves de forma
#uniforme. Con h(k) = k % M conviene que M sea primo: con M = 8 y claves múltiplos de
#8, todas caen en el bucket 0.
#Python: dict y set son tablas hash con direccionamiento abierto. Desde Python 3.7
#el dict conserva el orden de inserción; el set no garantiza ningún orden.