#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // Use the new range-based for loop to iterate over a vector
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Use the new auto keyword to declare variables
    auto x = 10;
    auto y = 3.14;
    auto z = "hello";
    std::cout << x << " " << y << " " << z << std::endl;

    // Use the new chrono library to measure time
    auto start = std::chrono::steady_clock::now();
    // ... do some work ...
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " microseconds." << std::endl;

    // Use the new nullptr keyword instead of NULL
    int* p = nullptr;
    if (p == nullptr) {
        std::cout << "Pointer is null." << std::endl;
    }

    // Use the new default and delete keywords to control default behavior
    class MyClass {
    public:
        MyClass() = default;
        MyClass(const MyClass&) = delete;
        MyClass& operator=(const MyClass&) = delete;
    };
    MyClass a;
    // MyClass b(a); // error: copy constructor is deleted

    return 0;
}

/* This program demonstrates several new features of C++11:

The range-based for loop, which simplifies iterating over collections.
The auto keyword, which allows for easier declaration of variables with automatic type deduction.
The chrono library, which provides a standard way to measure time.
The nullptr keyword, which provides a null pointer value that is distinct from other integer values.
The default and delete keywords, which allow for greater control over the default behavior of class methods.
Note that not all compilers fully support C++11 yet, so you may need to check the documentation for your specific compiler to see which features are supported. */
