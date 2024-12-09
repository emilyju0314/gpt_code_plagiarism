#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const size_t N = 3001;
double dp[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  size_t n, k, t;
  cin >> n >> k;
  for (size_t i = 1; i <= n; ++i) {
    cin >> t;
    double s = 0;
    copy(dp[i - 1], dp[i - 1] + k + 1, dp[i]);
    for (size_t j = 1; j <= t; ++j) {
      int x;
      cin >> x;
      s += x;
      for (size_t m = j; m <= k; ++m) {
        dp[i][m] = max(dp[i][m], dp[i - 1][m - j] + s);
      }
    }
  }
  cout << static_cast<uint64_t>(dp[n][k]) << '\n';
  return 0;
}
