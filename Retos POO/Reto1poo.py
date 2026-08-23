class Persona:
    def __init__(self,TipoDoc="",documento="",nombre="",apellido="",peso=0.0,estatura=0.0,edad=0):
        self.TipoDoc = TipoDoc
        self.documento = documento
        self.nombre = nombre
        self.apellido = apellido
        self.peso = peso
        self.estatura = estatura
        self.edad = edad
    def pedirDatos(self):
        self.TipoDoc = input("Tipo de documento: ")
        self.documento = input("Documento: ")
        self.nombre = input("Nombre: ")
        self.apellido = input("Apellido: ")
        self.peso = float(input("Peso en kg: "))
        self.estatura = float(input("Estatura en metros: "))
        self.edad = int(input("Edad: "))
        self.sexo = input("Sexo: ")

    def mostrarPersona(self):
        print("Tipo de documento:", self.TipoDoc)
        print("Documento:", self.documento)
        print("Nombre:", self.nombre)
        print("Apellido:", self.apellido)
        print("Peso:", self.peso, "kg")
        print("Estatura:", self.estatura, "m")
        print("Edad:", self.edad)
        print("Sexo:", self.sexo)
    def calcularImc(self):
        imc = self.peso / (self.estatura ** 2)

        print("IMC:", imc)

        if imc < 20:
            print("El peso está por debajo de lo ideal")
        elif imc <= 25:
            print("El peso es ideal")
        else:
            print("Tiene sobrepeso")
    def mayorEdad(self):
        if self.edad >= 18:
            print("Es mayor de edad")
        else:
            print("No es mayor de edad")
persona = Persona()
persona.pedirDatos()
persona.mostrarPersona()
persona.calcularImc()
persona.mayorEdad()