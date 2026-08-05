Algoritmo vacunas_menores_edad
	definir meses_de_edad,peso,dosis Como real
	Escribir "Cuantos meses de edad tiene el menor?"
	Leer meses_de_edad
	Si meses_de_edad >12 Entonces
		Escribir "no se puede realizar el procedimiento "
	SiNo
		Escribir "Cual es el peso del bebe?"
		Leer peso
		dosis<- ((peso + 10 ) / (meses_de_edad * 10)) * 8 
		Escribir " la dosis que se le debe suministrar al menor es de :"  dosis 
	Fin Si
FinAlgoritmo