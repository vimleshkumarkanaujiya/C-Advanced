#include <iostream>
#include <vector>
#include <ranges>

int main() {
    // Initialize a vector of integers
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Use a range-based for loop with a filter and a transform
    for (int i : v | std::views::filter([](int i) { return i % 2 == 0; })
                     | std::views::transform([](int i) { return i * i; })) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Use a coroutine to generate Fibonacci numbers
    auto fibonacci = []() -> std::generator<int> {
        int a = 0, b = 1;
        while (true) {
            co_yield a;
            std::swap(a, b);
            b += a;
        }
    };

    // Use a range-based for loop to print the first 10 Fibonacci numbers
    for (int i : fibonacci() | std::views::take(10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Use the spaceship operator to compare two strings
    std::string s1 = "hello";
    std::string s2 = "world";
    if (s1 <=> s2 < 0) {
        std::cout << s1 << " comes before " << s2 << std::endl;
    } else {
        std::cout << s2 << " comes before " << s1 << std::endl;
    }

    // Use the consteval keyword to perform compile-time computation
    constexpr auto square = [] (int x) consteval {
        return x * x;
    };
    constexpr int result = square(10);
    static_assert(result == 100);
    
    return 0;
}

/* This program demonstrates several new features of C++20:

The std::views::filter and std::views::transform functions from the new ranges library are used to filter and transform the elements of a vector in a range-based for loop.
The std::generator type from the coroutines library is used to generate Fibonacci numbers.
The spaceship operator (<=>) is used to compare two strings.
The consteval keyword is used to perform compile-time computation.
Note that not all compilers fully support C++20 yet, so you may need to check the documentation for your specific compiler to see which features are supported. */
