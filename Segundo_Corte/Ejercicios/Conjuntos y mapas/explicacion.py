#O(1)hashtable(conjuntos mapas)

#Conjunto:
#guarda elemeentos sin repeticion y sin orden
#mapa :(diccionario) guarda elementos
# sin repeticion y con orden

#funcion hash: recuibe un elemento y devuelve un numero entero
#determinista :para un mismo elemento
#siemore devuelve el mismo valor
# rapida: si calcula es mas costoso que recorrer 
# esta bien repaartida:
a = {"papel","lapiz","cuaderno"}
b = {"goma","regla","borrador"}
print(a.union(b))
print(a.intersection(b))
print(a.difference(b))
print(b.difference(a))

def hash(self,clave):
    h = 0
    for c in str(clave):
        h = (h * 31 + ord(c))%100
    return h
print(hash(None,"papel"))

print(hash(None,"ana"))
print(hash(None,"naa"))


