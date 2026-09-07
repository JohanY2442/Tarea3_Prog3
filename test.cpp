#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

int main() {
    std::cout << "--- PRUEBAS CORE_NUMERIC ---" << std::endl;

    // 1. CASOS QUE COMPILAN CORRECTAMENTE
    std::vector<double> datos = {4.0, 24.0, 10.0, 0.0, 9.0, 67.0, 67.0, 19.0, 1.0, 19.0, 10.0, 5.0, 25.0};

    auto total = core_numeric::sum(datos);
    auto promedio = core_numeric::mean(datos);
    auto varianza = core_numeric::variance(datos);
 
    std::cout << "Suma: " << total << std::endl;   // El resultado deberia ser 260
    std::cout << "Promedio: " << promedio << std::endl; // El promedio deberia ser 20
    std::cout << "Varianza: " << varianza << std::endl;  // La varianza deberia ser 463,3846 aproximadamente

    // 2. CASOS QUE NO COMPILAN
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
