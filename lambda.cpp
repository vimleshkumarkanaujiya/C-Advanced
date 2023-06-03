#include <iostream>

using namespace std;

int main() {
  auto sum = [](int a, int b) {
    return a + b;
  };
  int result = sum(5, 3); // result is 8
  cout << result;
}
