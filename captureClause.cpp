#include <iostream>

using namespace std;

int main() {
  int x = 5;
  int y = 3;
  auto multiply = [x, & y](int z) {
    return x * y * z;
  };
  int result = multiply(2); // result is 30 (5 * 3 * 2)
  cout << result;
}
