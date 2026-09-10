#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

// aca probamos a los objetos
struct Punto {
    double x;
    double y;

    Punto operator+(const Punto& other) const {
        return {x + other.x, y + other.y};
    }

    Punto operator-(const Punto& other) const {
        return {x - other.x, y - other.y};
    }

    Punto operator*(const Punto& other) const {
        return {x * other.x, y * other.y};
    }

    Punto operator/(std::size_t n) const {
        return {x / n, y / n};
    }

    bool operator<(const Punto& other) const {
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }
};

int main() {
    // ACA PONEMOS LOS TESTS

    // 1. CASOS QUE SI COMPILAN
    std::vector<double> datos = {4.0, 24.0, 10.0, 0.0, 9.0, 67.0, 67.0, 19.0, 1.0, 19.0, 10.0, 5.0, 25.0};

    auto total = core_numeric::sum(datos);
    auto promedio = core_numeric::mean(datos);
    auto varianza = core_numeric::variance(datos);
    auto maximo = core_numeric::max(datos);

    std::cout << "Suma: " << total << std::endl;   // El resultado deberia ser 260
    std::cout << "Promedio: " << promedio << std::endl; // El promedio deberia ser 20
    std::cout << "Varianza: " << varianza << std::endl;  // La varianza deberia ser 463,3846 aprox
    std::cout << "Maximo: " << maximo << std::endl; // El numero maximo deberia ser 67.0

    // prueba de transform_reduce
    auto tr = core_numeric::transform_reduce(datos, [](double x) { return x * x; });
    std::cout << "Transform reduce: " << tr << std::endl;

    // pruebas de funciones variadicas
    auto s_var = core_numeric::sum_variadic(1, 2, 33, 4);
    auto m_var = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0);
    auto v_var = core_numeric::variance_variadic(1.0, 2.0, 3.0, 4.0);
    auto mx_var = core_numeric::max_variadic(1.0, 2.7, 3.0, 4.0);

    std::cout << "Sum variadic: " << s_var << std::endl;
    std::cout << "Mean variadic: " << m_var << std::endl;
    std::cout << "Variance variadic: " << v_var << std::endl;
    std::cout << "Max variadic: " << mx_var << std::endl;

    // prueba de objetos con la clase Punto
    std::vector<Punto> puntos = {{1.0, 2.0}, {3.0, 4.0}};
    auto suma_puntos = core_numeric::sum(puntos);
    std::cout << "Suma de puntos: (" << suma_puntos.x << ", " << suma_puntos.y << ")" << std::endl;

    // 2. AHORA LOS CASOS QUE NO COMPILAN

    // std::vector<std::string> palabras = {"Tres", "chanchitos"};
    // auto prueba_error1 = core_numeric::variance(palabras);
    // En este caso, si pasamos un vector que contiene strings a la varianza y esto va a fallar porque como son strings no pueden restarse ni dividirse. 

    // int numero = 10;
    // auto prueba_error2 = core_numeric::sum(numero); 
    // En este segundo caso, le estamos pasando solo un numero a la suma y esto dara error, porque la suma necesita un contenedor, no un solo numero, ya que no va a poder iterar
    // si solo es un numero y no tiene ni begin ni end, por eso que no compilara.

    // struct ObjetoSinComparar {};
    // std::vector<ObjetoSinComparar> lista_vacia(2);
    // auto prueba_error3 = core_numeric::max(lista_vacia);
    // En este tercer caso va a fallar porque la estructura no tiene implementado el operador < y no cumple el concept Comparable que pide max.

    return 0;
}
