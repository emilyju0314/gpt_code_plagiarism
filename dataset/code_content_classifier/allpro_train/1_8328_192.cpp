#include <bits/stdc++.h>
int main() {
  auto optimize_cpp_stdio = []() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return 0;
  }();
  static char table[62];
  std::iota(table + 0, table + 10, '0');
  std::iota(table + 10, table + 10 + 26, 'a');
  std::iota(table + 10 + 26, table + 10 + 26 + 26, 'A');
  int T;
  std::cin >> T;
  while (T--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> s(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> s[i];
      sum += std::count(s[i].begin(), s[i].end(), 'R');
    }
    auto next = [&](int& i, int& j) -> bool {
      j += (i & 1) ? -1 : 1;
      if (j == m) i++, j = m - 1;
      if (j < 0) i++, j = 0;
      return i < n;
    };
    int ave = sum / k, cnt1 = sum - ave * k, cnt0 = k - cnt1;
    for (int i = 0, j = 0, c = 0, cnt = 0; i < n; next(i, j)) {
      if (s[i][j] == 'R') cnt++;
      s[i][j] = table[c];
      if (c < cnt0 && cnt == ave) {
        c = std::min(c + 1, k - 1);
        cnt = 0;
      } else if (cnt0 <= c && cnt == ave + 1) {
        c = std::min(c + 1, k - 1);
        cnt = 0;
      }
    }
    for (std::string& str : s) std::cout << str << "\n";
  }
  return 0;
}
