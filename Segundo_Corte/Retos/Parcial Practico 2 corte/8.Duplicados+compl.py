def dup_lista(datos):
    vistos = [] # lista
    d = 0
    for x in datos:
        if x in vistos: d += 1
        else: vistos.append(x)
    return d
print(dup_lista([1, 2, 3, 2, 4, 1]))
#dup_lista: O(n²). x in vistos sobre una lista recorre los elementos uno por uno. Con
#datos todos distintos (peor caso), vistos crece 0, 1, 2, ..., n-1, y las comparaciones suman
#0 + 1 + ... + (n-1) = n(n-1)/2. El append es O(1) amortizado y no domina.
