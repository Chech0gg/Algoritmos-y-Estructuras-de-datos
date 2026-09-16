#1
def sumalista(lista):# creamos la funcio para sumar elementos a una lista
    if len(lista) == 0: #definimos qie si la lista no tiene elementos que regrese 0
        return 0
    else:
        return lista[0] + sumalista(lista[1:])# llamamos a la funcion recursiva para que sume  los elementos desde el primer indice dde la lista hasta el ultimo ademas que utilize un parametro para la list ael cual desde el imdice 1 hasta el final por eso el 1: ya que en una lista muy grande no se sabe hasta que indice se va a sumar
print(sumalista([1,6,8,9,10]))

#2
a = int(input("digite la base de la potencia:"))
b = int(input("digite el exponente:"))
def potenciab(n):
    if n == 1:#caso base si el exponente es igual a 1 que regrese la base
        return a
    else:
        return a * potenciab(n - 1)
print(potenciab(b))

#3

t = str(input("digite la palabra palabra para invertir:"))
def invertir(t):
    if len(t) <= 0:#caso base si la palabra es menor o igual a 0 que regrese la palabra
        return t
    else:
        return t[-1] + invertir(t[:-1])#se realiza de el ultimo indice de la palabra hasta el primer indice de la palabra y se va concatenando con el resto de la palabra
print(invertir(t))

#4 
lista =[1,3,4,6,7,7]
def invertirlista(lista):
    if len(lista) <= 0:#caso base si la lista es menor o igual a 0 que regrese la lista
        return lista
    else:
        return [lista[-1]] + invertirlista(lista[:-1]) #se realiza la misma logica que en el ejercicio anterior pero en este caso se hace con una lista y no con un string
print(invertirlista(lista))