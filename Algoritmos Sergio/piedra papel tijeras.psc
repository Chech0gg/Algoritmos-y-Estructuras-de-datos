Algoritmo rock_paper_sissors
	Definir jugador, maquina Como Entero
	
    Escribir "1. Piedra"
    Escribir "2. Papel"
    Escribir "3. Tijera"
    Escribir "Ingrese su elección:"
    Leer jugador
	
    maquina <- Aleatorio(1,3)
	
    Escribir "La máquina eligió: "
	
    Segun maquina Hacer
        1:
            Escribir "Piedra"
        2:
            Escribir "Papel"
        3:
            Escribir "Tijera"
    FinSegun
	

    Si jugador = maquina Entonces
        Escribir "¡Empate!"
    SiNo
        Si (jugador = 1 Y maquina = 3) O (jugador = 2 Y maquina = 1) O (jugador = 3 Y maquina = 2) Entonces
            Escribir "¡Ganaste!"
        SiNo
            Escribir "La máquina gana."
        FinSi
    FinSi
FinAlgoritmo