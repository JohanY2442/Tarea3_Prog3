#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

int main() {
    std::cout << "AQUI ESTAN LOS TESTS" << std::endl;

    // 1. CASOS QUE SI COMPILAN
    std::vector<double> datos = {4.0, 24.0, 10.0, 0.0, 9.0, 67.0, 67.0, 19.0, 1.0, 19.0, 10.0, 5.0, 25.0};

    auto total = core_numeric::sum(datos);
    auto promedio = core_numeric::mean(datos);
    auto varianza = core_numeric::variance(datos);
 
    std::cout << "Suma: " << total << std::endl;   // El resultado deberia ser 260
    std::cout << "Promedio: " << promedio << std::endl; // El promedio deberia ser 20
    std::cout << "Varianza: " << varianza << std::endl;  // La varianza deberia ser 463,3846 aproximadamente

    // 2. CASOS QUE NO COMPILAN
    
    // std::vector<std::string> palabras = {"Tres", "chanchitos"};
    // auto prueba_error1 = core_numeric::variance(palabras);
    // En este caso, si pasamos un vector que contiene strings a la varianza y esto va a fallar porque como son strings no pueden restarse ni dividirse. 

    
    //int numero = 10;
    // auto prueba_error2 = core_numeric::sum(numero); 
    // En este segundo caso, le estamos pasando solo un numero a la suma y esto dara error, porque la suma necesita un contenedor, no un solo numero, ya que no va a poder iterar
    // si solo es un numero y no tiene ni begin ni end, por eso que no compilara.

  

    return 0;
}
