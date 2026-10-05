#Asigno los cassileros correspondientes para cada uno , como no puedo abrir y no puedo preguntar, secilllamente
#ya tienen cada uno alguna caracteristica ya sea el nombre , numero ,fecha especifica que lo identifica por lo cual creeria que puede ser
#la mejor solucion de este

abecedario = {chr(i): i - ord('A') + 1 for i in range(ord('A'), ord('Z') + 1)}

def calcular_valor_nombre(nombre):
    total = sum(abecedario.get(letra.upper(), 0) for letra in nombre)
    return total % 11

print("Ingrese un nombre:")
nombre = input()
valor = calcular_valor_nombre(nombre)
print(f"El valor del nombre '{nombre}' es: {valor}")
#al final se obtiene el casillero correspondiente al nombre ingresado por el usuario dependiento de la suma de los valores asignados a cada letra y el modulo 11
#y ademas re organiza los casilleros de manera cíclica del 1 al 11 para qeu sea de la maner 

#momento 3: 
# si estuvieran las 11 personas en el casillero 0 , podriamos encontarr a cualquier persona ?
# En este caso, si todas las personas están en el casillero 0, no podríamos encontrarlas usando el valor del nombre, ya que todos los nombres darían el mismo casillero.
# por lo que usariamos otro método para localizar a las personas, como un sistema de identificación único o un registro adicional que nos permita diferenciarlas dentro del mismo casillero.
