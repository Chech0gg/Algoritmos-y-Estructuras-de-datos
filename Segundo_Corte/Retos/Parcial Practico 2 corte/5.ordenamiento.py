v = [42, 17, 93, 8, 55, 31]
for i in range(1, len(v)):
    actual = v[i]
    j = i - 1
    while j >= 0 and v[j] > actual:
        v[j + 1] = v[j]
        j -= 1
    v[j + 1] = actual
print("Vector ordenado:", v)
#Total de comparaciones de datos: 1 + 1 + 3 + 2 + 4 = 11. Arreglo final: [8, 17, 31, 42, 55, 93].
#Convención de conteo (decláralo en el parcial): aquí cuento las evaluaciones de v[j] >
#actual. La condición j >= 0 no compara datos; en las pasadas 1 y 3 el ciclo termina porque j
#llega a -1 y, por el cortocircuito de and , no se evalúa una comparación más. Si tu profesora
#cuenta también j >= 0, el total cambia; lo importante es anunciar tu criterio.
#Verificación con inversiones: el arreglo original tiene 8 inversiones: (42,17), (42,8), (42,31),
#(17,8), (93,8), (93,55), (93,31), (55,31). Y los desplazamientos suman 1 + 0 + 3 + 1 + 3 = 8. ✔
#Además, comparaciones = desplazamientos + pasadas que terminan por una comparación
#falsa = 8 + 3 (pasadas 2, 4 y 5) = 11.
