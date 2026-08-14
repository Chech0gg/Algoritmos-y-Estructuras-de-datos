# una biblioteca comunitaria prest 3 recursos (computador, videobeam, sala)
# durante 5 días. Se quiere saber cuánto se usó cada recurso y qué tan cargado estuvo.

recursos = ["computador", "videobeam", "sala"]
uso = [
    [13, 5, 12, 4, 36],
    [2, 3, 20, 15, 22],
    [16, 12, 45, 23, 9],
]

# 1) Total de uso por recurso
print("Uso total por recurso:")
for i, recurso in enumerate(recursos):
    total_recurso = sum(uso[i])
    print(f"- {recurso}: {total_recurso} unidades")

print()

# 2) Carga por día (suma los tres recursos en cada día)
print("Carga por día:")
for j in range(len(uso[0])):
    total_dia = sum(uso[i][j] for i in range(len(uso)))
    print(f"- Día {j + 1}: {total_dia} unidades")

print()

# 3) Carga relativa (%) respecto al total general
print("Carga relativa del uso total:")
total_general = sum(sum(fila) for fila in uso)
for i, recurso in enumerate(recursos):
    total_recurso = sum(uso[i])
    porcentaje = (total_recurso / total_general) * 100 if total_general else 0
    print(f"- {recurso}: {porcentaje:.1f}% del uso total")
