#ifndef CORE_NUMERIC_H
#define CORE_NUMERIC_H

#include <concepts>
#include <iterator>
#include <type_traits>

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

// otro concept propio para comparar en el max
template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

// AQUI ESTA LA FUNCION Y LOS DOS ALGORITMOS
// Función sum
template <Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {
    typename C::value_type result{};
    for (const auto& item : container) {
        result = result + item;
    }
    return result;
}

// Algoritmo mean
template <Iterable C>
requires Divisible<typename C::value_type> && Addable<typename C::value_type>
auto mean(const C& container) {
    auto total = sum(container);
    std::size_t count = 0;
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        ++count;
    }

    // si es tipo entero lo convierto a double para no perder decimales
    if constexpr (std::is_integral_v<typename C::value_type>) {
        return static_cast<double>(total) / count;
    } else {
        return total / count;
    }
}

// Algoritmo variance
template <Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type> && Subtractable<typename C::value_type>
auto variance(const C& container) {
    auto m = mean(container);
    decltype(m) acumulador{}; // toma el tipo del promedio para no perder decimales
    std::size_t count = 0;

    for (const auto& val : container) {
        auto diff = val - m;
        acumulador = acumulador + (diff * diff);
        ++count;
    }
    return acumulador / count;
}

// Algoritmo max
template <Iterable C>
requires Comparable<typename C::value_type>
auto max(const C& container) {
    auto it = std::begin(container);
    auto max_val = *it;
    for (; it != std::end(container); ++it) {
        if (max_val < *it) {
            max_val = *it;
        }
    }
    return max_val;
}

// Algoritmo transform_reduce
template <Iterable C, typename Func>
auto transform_reduce(const C& container, Func op) {
    auto it = std::begin(container);
    auto result = op(*it);
    ++it;
    for (; it != std::end(container); ++it) {
        result = result + op(*it);
    }
    return result;
}

// FUNCIONES VARIADICAS CON FOLD EXPRESSIONS Y CONCEPTS

template <Addable... Args>
auto sum_variadic(Args... args) {
    return (... + args);
}

template <Addable... Args>
auto mean_variadic(Args... args) {
    auto total = sum_variadic(args...);
    return static_cast<double>(total) / sizeof...(args);
}

template <Comparable First, Comparable... Args>
auto max_variadic(First first, Args... args) {
    auto res = first;
    ((res = (args > res ? args : res)), ...);
    return res;
}

template <Addable... Args>
auto variance_variadic(Args... args) {
    double m = mean_variadic(args...);
    double acumulador = 0;
    ((acumulador = acumulador + (args - m) * (args - m)), ...);
    return acumulador / sizeof...(args);
}

}

#endif
