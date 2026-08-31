class PuntoAcopio:
    def __init__(self, codigo, barrio, total_recogido=0.0):
        # Atributos encapsulados (privados por convención con un guion bajo)
        self._codigo = codigo
        self._barrio = barrio
        self._total_recogido = total_recogido

    # Método 1: Registrar recolección
    def registrar_recoleccion(self, kilos):
        if kilos > 0:
            self._total_recogido += kilos

    # Método 2: Verificar si supera la meta
    def supera_meta(self, meta):
        return self._total_recogido >= meta

    # Getters
    def get_codigo(self):
        return self._codigo

    def get_barrio(self):
        return self._barrio

    def get_total_recogido(self):
        return self._total_recogido

    # Descripción base
    def mostrar_descripcion(self):
        print(f"[PUNTO GENERAL] Código: {self._codigo} | Barrio: {self._barrio} | Total: {self._total_recogido} kg")


# 2. CLASE DERIVADA: MaterialEspecial
class MaterialEspecial(PuntoAcopio):
    def __init__(self, codigo, barrio, total_recogido, tipo_material):
        # Llamada al constructor de la clase base
        super().__init__(codigo, barrio, total_recogido)
        self._tipo_material = tipo_material  # Atributo propio

    # Redefinición del método de la clase padre
    def mostrar_descripcion(self):
        print(f"[MATERIAL ESPECIAL] Código: {self._codigo} | Barrio: {self._barrio} | Total: {self._total_recogido} kg | Tipo: {self._tipo_material}")


# 3. PRUEBA
# Lista mezclando objetos de ambas clases
centro = [
    PuntoAcopio(101, "Centro", 120.5),
    MaterialEspecial(201, "Norte", 85.0, "Baterías y Pilas"),
    PuntoAcopio(102, "Sur", 310.0),
    MaterialEspecial(202, "Occidente", 45.0, "Aceite Usado")
]

# Ejecutar métodos
centro[0].registrar_recoleccion(30.0)
centro[1].registrar_recoleccion(20.0)

print("=== INFORME DE PUNTOS DE ACOPIO ===\n")

# Recorrido de la lista y llamado al método correspondiente (Polimorfismo en Python)
for punto in centro:
    punto.mostrar_descripcion()
    
    if punto.supera_meta(100.0):
        print("   -> Estado: Superó la meta de 100 kg")
    else:
        print("   -> Estado: No ha alcanzado la meta de 100 kg")
    print("-" * 50)