#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

int main() {
    std::cout << "--- PRUEBAS CORE_NUMERIC (Parte 1) ---" << std::endl;

    // 1. CASOS QUE COMPILAN CORRECTAMENTE
    std::vector<double> datos = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};

    auto total = core_numeric::sum(datos);
    auto promedio = core_numeric::mean(datos);
    auto varianza = core_numeric::variance(datos);

    std::cout << "Suma: " << total << std::endl;         // Esperado: 40
    std::cout << "Promedio: " << promedio << std::endl;   // Esperado: 5
    std::cout << "Varianza: " << varianza << std::endl;   // Esperado: 4

    // 2. CASOS QUE NO COMPILAN POR CONCEPTS (Se dejan comentados según la guía)
    /*
    std::vector<std::string> palabras = {"Hola", "Mundo"};
    
    // ERROR 1: std::string cumple 'Iterable' y 'Addable', pero NO 'Divisible'.
    // Al intentar calcular 'mean', falla en tiempo de compilación.
    auto error_mean = core_numeric::mean(palabras);

    int numero_suelto = 10;
    // ERROR 2: int no es 'Iterable' (no tiene std::begin / std::end).
    // Al intentar pasarlo a 'sum', falla el concept Iterable.
    auto error_sum = core_numeric::sum(numero_suelto);
    */

    return 0;
}
