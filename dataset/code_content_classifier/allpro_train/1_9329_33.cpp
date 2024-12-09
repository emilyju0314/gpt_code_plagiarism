#include <bits/stdc++.h>
int main(void) {
  int n, a;
  std::vector<int> A;
  int check = 0;
  int sum = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    A.push_back(a);
    sum += a;
  }
  if (n == 1) {
    std::cout << -1 << std::endl;
    check = 1;
  }
  if (check == 0) {
    for (int i = 0; i < n; i++) {
      if (sum - A[i] != A[i]) {
        std::cout << 1 << std::endl;
        std::cout << i + 1 << std::endl;
        check = 1;
        break;
      }
    }
  }
  if (check == 0 && n > 2) {
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++) {
        if (sum - (A[i] + A[j]) != (A[i] + A[j])) {
          std::cout << 2 << std::endl;
          std::cout << i + 1 << " " << j + 1 << std::endl;
          check = 1;
          break;
        }
      }
  }
  if (check == 0) std::cout << -1 << std::endl;
  return 0;
}
