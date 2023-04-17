#include <iostream>
#include <vector>

// Use generic lambdas to define functions that work with any type
auto sum = [](auto a, auto b) { return a + b; };

// Use variable templates to define constants that depend on a type
template<typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
    // Use binary literals and digit separators for improved readability
    auto binary = 0b1010'1010'0101'0101;
    std::cout << std::hex << binary << std::endl;

    // Use std::make_unique to create unique_ptr objects
    auto ptr = std::make_unique<int>(42);
    std::cout << *ptr << std::endl;

    // Use std::vector::emplace_back to construct objects in place
    std::vector<std::string> v;
    v.emplace_back("hello");
    v.emplace_back("world");
    for (const auto& s : v) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    // Use generic lambdas to define functions that work with any type
    std::cout << sum(10, 20) << std::endl;
    std::cout << sum(3.14, 2.72) << std::endl;

    // Use variable templates to define constants that depend on a type
    std::cout << "pi<float> = " << pi<float> << std::endl;
    std::cout << "pi<double> = " << pi<double> << std::endl;

    return 0;
}

/* This program demonstrates several new features of C++14:

Binary literals and digit separators, which make it easier to write and read binary and hexadecimal numbers.
std::make_unique, which provides a safer and more concise way to create unique_ptr objects.
std::vector::emplace_back, which allows for the in-place construction of objects in a vector.
Generic lambdas, which allow for the definition of functions that work with any type.
Variable templates, which allow for the definition of constants that depend on a type.
Note that not all compilers fully support C++14 yet, so you may need to check the documentation for your specific compiler to see which features are supported. */
