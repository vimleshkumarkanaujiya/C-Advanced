#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

int main() {
  std::vector < int > numbers = {
    1,
    2,
    3,
    4,
    5
  };
  int count = count_if(numbers.begin(), numbers.end(), [](int n) {
    return n % 2 == 0;
  });
  // count is 2 (2 and 4 are even)
  cout << count;
}
