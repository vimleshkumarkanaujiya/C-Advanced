#include <iostream>
#include <tuple>
#include <string>

int main() {
  // Creating a tuple
  std::tuple<std::string, int, float> person = {"Alice", 25, 5.8};

  // Accessing elements of the tuple
  std::cout << "Name: " << std::get<0>(person) << std::endl;   // Alice
  std::cout << "Age: " << std::get<1>(person) << std::endl;    // 25
  std::cout << "Height: " << std::get<2>(person) << std::endl; // 5.8

  // Modifying a tuple
  std::get<1>(person) = 26;
  std::get<2>(person) = 6.0;

  // Accessing modified elements
  std::cout << "Name: " << std::get<0>(person) << std::endl;   // Alice
  std::cout << "Age: " << std::get<1>(person) << std::endl;    // 26
  std::cout << "Height: " << std::get<2>(person) << std::endl; // 6.0

  return 0;
}

