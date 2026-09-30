#Implementen la pila sobre lista enlazada, sin usar la lista de Python. En C++ háganla con nodos y punteros.
#Implementen el deshacer de su proyecto con una pila. Los de la línea uno, deshacer el último préstamo. Los de la dos, el último registro de recolección. Los de la tres, la última asignación de monitoría. Ese es un requerimiento explícito de su línea.
#Evalúen una expresión en notación polaca inversa usando la pila. Tres más cuatro, en polaca inversa, se escribe tres, cuatro, más.
# Ejercicio 1 
class Nodo:

  def __init__(self, valor):
    self.valor = valor
    self.siguiente = None


class PilaEnlazada:

  def __init__(self):
    self.cima = None
    self._tamanio = 0

  def esta_vacia(self):
    return self.cima is None

  def apilar(self, valor):
    """Agrega un elemento en la cima (O(1))"""
    nuevo_nodo = Nodo(valor)
    nuevo_nodo.siguiente = self.cima
    self.cima = nuevo_nodo
    self._tamanio += 1

  def desapilar(self):
    """Elimina y retorna el elemento de la cima (O(1))"""
    if self.esta_vacia():
      raise IndexError("La pila está vacía")
    valor = self.cima.valor
    self.cima = self.cima.siguiente
    self._tamanio -= 1
    return valor

  def ver_cima(self):
    """Retorna el valor de la cima sin eliminarlo"""
    if self.esta_vacia():
      raise IndexError("La pila está vacía")
    return self.cima.valor
print(PilaEnlazada())
# Ejercicio 3
print("Ejercicio 3")
def evaluar_notacion_polaca_inversa(expresion):
    pila = []
    for operacion in expresion.split():
        if operacion.isdigit(): 
            pila.append(int(operacion))
        else:
            b = pila.pop()
            a = pila.pop()
            if operacion == '+':
                pila.append(a + b)
            elif operacion == '-':
                pila.append(a - b)
            elif operacion == '*':
                pila.append(a * b)
            elif operacion == '/':
                pila.append(a / b)
    return pila.pop()
print(evaluar_notacion_polaca_inversa("3 4 +"))
print(evaluar_notacion_polaca_inversa("3 4 5 + *"))
print(evaluar_notacion_polaca_inversa("10 2 /"))
print(evaluar_notacion_polaca_inversa("5 1 2 + 4 * + 3 -"))