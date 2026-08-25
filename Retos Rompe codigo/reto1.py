print("=== RETO 1 ===")

vasoA = "Jugo de naranja"
vasoB = "Agua"
vasoC = "Vacío"

print("\nEstado inicial")
print("A:", vasoA)
print("B:", vasoB)
print("C:", vasoC)

# Paso 1
vasoC = vasoA
vasoA = "Vacío"

# Paso 2
vasoA = vasoB
vasoB = "Vacío"

# Paso 3
vasoB = vasoC
vasoC = "Vacío"

print("\nEstado final")
print("A:", vasoA)
print("B:", vasoB)
print("C:", vasoC)

print("\nSecuencia de pasos:")
print("1. Pasar el jugo del vaso A al vaso C.")
print("2. Pasar el agua del vaso B al vaso A.")