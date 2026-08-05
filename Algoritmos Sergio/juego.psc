Algoritmo juego
	Definir eleccion, moneda Como Entero
	
    Escribir "juego"
    Escribir "Elija una opción:"
    Escribir "0. Cara"
    Escribir "1. Sello"
    Leer eleccion
    Si eleccion <> 0 Y eleccion <> 1 Entonces
        Escribir "Opción inválida."
    SiNo
		
        moneda <- Aleatorio(0,1)
		
        Si moneda = 0 Entonces
            Escribir "La moneda cayó en: Cara"
        SiNo
            Escribir "La moneda cayó en: Sello"
        FinSi
		
        Si eleccion = moneda Entonces
            Escribir "¡Felicidades! Ganaste."
        SiNo
            Escribir "Lo siento, perdiste."
        FinSi
		
    FinSi
FinAlgoritmo