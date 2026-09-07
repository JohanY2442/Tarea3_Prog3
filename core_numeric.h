#ifndef CORE_NUMERIC_H
#define CORE_NUMERIC_H

#include <concepts>
#include <iterator>

namespace core_numeric {

// AQUI ESTAN LOS CONCEPTS
template <typename C>
concept Iterable = requires(C c) {
    std::begin(c);
    std::end(c);
};

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template <typename T>
concept Divisible = requires(T a, std::size_t n) {
    { a / n } -> std::same_as<T>;
};

// aqui esta el concept propio
template <typename T>
concept Subtractable = requires(T a, T b) {
    { a - b } -> std::same_as<T>;
};

// AQUI ESTA LA FUNCION Y LOS DOS ALGORITMOS
// 1. Función sum
template <Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {
    typename C::value_type result{};
    for (const auto& item : container) {
        result = result + item;
    }
    return result;
}

// 2. Algoritmo mean
template <Iterable C>
requires Divisible<typename C::value_type> && Addable<typename C::value_type>
auto mean(const C& container) {
    auto total = sum(container);
    std::size_t count = 0;
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        ++count;
    }
    return total / count;
}

// 3. Algoritmo variance
template <Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type> && Subtractable<typename C::value_type>
auto variance(const C& container) {
    auto m = mean(container);
    typename C::value_type acumulador{};
    std::size_t count = 0;

    for (const auto& val : container) {
        auto diff = val - m;
        acumulador = acumulador + (diff * diff);
        ++count;
    }
    return acumulador / count;
}



}

#endif
