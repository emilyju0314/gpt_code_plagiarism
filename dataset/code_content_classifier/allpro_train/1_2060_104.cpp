#include <iostream>

int main() {
  int N, D, X;
  std::cin >> N >> D >> X;
  int res{X};
  for (int i = 0; i < N; i++) {
    int A;
    std::cin >> A;
    res += 1 + (D - 1) / A;
  }
  printf("%d\n", res);
}