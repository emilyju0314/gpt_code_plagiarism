#include <iostream>

int main() {
  int n, c, tmp;
  int sum = 0;

  std::cin >> n >> c;

  for (int i = 0; i < c; ++i) {
    std::cin >> tmp;
    sum += tmp;
  }

  if (sum % (n + 1) == 0) {
    std::cout << sum / (n + 1) << std::endl;
  } else {
    std::cout << 1 + sum / (n + 1) << std::endl;
  }

  return 0;
}

