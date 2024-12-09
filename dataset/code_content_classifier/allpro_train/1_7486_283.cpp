#include <bits/stdc++.h>
using ll = long long;
int main() {
  int n, a_col, a_row, b_col, b_row;
  std::cin >> n;
  int sum{};
  while (n--) {
    std::cin >> a_col >> a_row >> b_col >> b_row;
    sum += (b_row - a_row + 1) * (b_col - a_col + 1);
  }
  std::cout << sum << std::endl;
}
