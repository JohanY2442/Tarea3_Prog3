#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

int main() {
    std::cout << "--- PRUEBAS CORE_NUMERIC ---" << std::endl;

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
    
    // ERROR 1: std::string cumple 'Iterable' y 'Addable', pero NO 'Divisible' ni 'Subtractable'.
    // Al intentar calcular 'variance' o 'mean', el compilador detiene la ejecución por fallo de concepts.
    auto error_variance = core_numeric::variance(palabras);

    int numero_suelto = 10;
    // ERROR 2: int no es 'Iterable' (carece de std::begin y std::end).
    // Al intentar pasarlo a 'sum', falla el concept Iterable inmediatamente.
    auto error_sum = core_numeric::sum(numero_suelto);
    */

    return 0;
}
