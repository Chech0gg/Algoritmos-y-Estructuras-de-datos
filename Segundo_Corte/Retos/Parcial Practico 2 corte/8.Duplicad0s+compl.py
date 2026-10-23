def dup_conjunto(datos):
    vistos = set() # conjunto
    d = 0
    for x in datos:
        if x in vistos: d += 1
        else: vistos.add(x)
    return d