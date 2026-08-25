edad = int(input("Ingrese la edad del paciente: "))
urgencia = input("¿Tiene una condición de urgencia? (Si/No): ")
minutos_espera = int(input("¿Cuántos minutos lleva esperando?: "))
if urgencia == "Si"or urgencia == "si":
    prioridad = "Alta"
elif edad >= 50 and minutos_espera >= 30:
    prioridad = "Alta"
elif minutos_espera >= 90:
    prioridad = "Alta"
elif edad >= 50 or minutos_espera >= 30:
    prioridad = "Media"
else:
    prioridad = "Baja"
print("La prioridad del paciente es:", prioridad)
 