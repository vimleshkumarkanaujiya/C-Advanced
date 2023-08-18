#include <iostream>

// Function to be referenced
int add(int a, int b) {
    return a + b;
}

// Function that takes a function reference as an argument
int performOperation(int (*func)(int, int), int x, int y) {
    return func(x, y);
}

int main() {
    // Defining a function reference
    int (*addRef)(int, int) = add;

    // Using the function reference
    int result = addRef(3, 5);
    std::cout << "Result: " << result << std::endl;

    // Using the function reference in another function
    int operationResult = performOperation(addRef, 7, 2);
    std::cout << "Operation Result: " << operationResult << std::endl;

    return 0;
}
