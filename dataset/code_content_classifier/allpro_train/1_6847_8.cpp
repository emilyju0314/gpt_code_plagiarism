#include <bits/stdc++.h>
constexpr int MAX_N = 300009;
int main() {
  int n;
  static int64_t a[MAX_N] = {}, s[MAX_N], left[MAX_N] = {}, right[MAX_N];
  int64_t x;
  std::cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    left[i] = std::max(static_cast<int64_t>(0), left[i - 1] + a[i]);
  }
  for (int i = n; i >= 1; --i) {
    right[i] = std::max(static_cast<int64_t>(0), right[i + 1] + a[i]);
  }
  int64_t min_wtf = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    min_wtf = std::min(min_wtf, s[i] * x - left[i]);
    ans = std::max(ans, s[i] * x + right[i + 1] - min_wtf);
  }
  std::cout << ans << std::endl;
}
