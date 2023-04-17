#include <iostream>

int main() {
    int x = 5; // 0101 in binary
    int y = 10; // 1010 in binary

    // Bitwise AND operator
    int result_and = x & y; // 0000 in binary
    std::cout << "x & y = " << result_and << std::endl;

    // Bitwise OR operator
    int result_or = x | y; // 1111 in binary
    std::cout << "x | y = " << result_or << std::endl;

    // Bitwise XOR operator
    int result_xor = x ^ y; // 1111 in binary
    std::cout << "x ^ y = " << result_xor << std::endl;

    // Bitwise NOT operator
    int result_not_x = ~x; // 1010 in binary (2's complement)
    std::cout << "~x = " << result_not_x << std::endl;

    int result_not_y = ~y; // 0101 in binary (2's complement)
    std::cout << "~y = " << result_not_y << std::endl;

    // Bitwise left shift operator
    int result_left_shift = x << 2; // 010100 in binary
    std::cout << "x << 2 = " << result_left_shift << std::endl;

    // Bitwise right shift operator
    int result_right_shift = y >> 2; // 0010 in binary
    std::cout << "y >> 2 = " << result_right_shift << std::endl;

    return 0;
}

