lecturas = [20,-999,22,24,-999,26]
sum = 0
datovalido = 0
descarartados = 0
for lectura in lecturas :
    if lectura != -999 :
        sum += lectura 
        datovalido += 1
    else:
        descarartados += 1
promedio = sum / datovalido
print ("los datos validos en cantidad son :", datovalido)
print ("los datos no validos en cantidad son :",descarartados)
print ("el promedio del arreglo es :", promedio)