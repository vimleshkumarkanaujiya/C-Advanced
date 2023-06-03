#include <iostream>

#include <vector>

#include <algorithm>

int main() {
  std::vector < int > numbers = {
    5,
    2,
    3,
    1,
    4
  };

  // Sorting the vector using lambda expression
  std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return a < b;
  });

  // Printing the sorted vector
  std::cout << "Sorted numbers: ";
  for (auto x: numbers) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
