#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
long long dp[55][55];
long long f[55][55];
long long inv(int n) {
  long long ans = 1;
  int m = mod - 2;
  while (m) {
    if (m & 1) ans *= n, ans %= mod;
    n = 1LL * n * n % mod;
    m >>= 1;
  }
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  dp[0][1] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= n + 1; j++) {
      for (int leftMax = j; leftMax <= n + 1; leftMax++)
        for (int rightMax = j; rightMax <= n + 1; rightMax++)
          if (min(leftMax, rightMax) == j)
            for (int x = 0; x <= i; x++)
              f[i][j] += dp[x][leftMax] * dp[i - x][rightMax] % mod,
                  f[i][j] %= mod;
      for (int x = n; x >= 0; x--)
        for (int y = x + 1; y >= 0; y--) {
          long long t = 1;
          for (int c = 1; c * (i + 1) <= x && c * j <= y; c++) {
            t *= (f[i][j] + c - 1) * inv(c) % mod, t %= mod;
            dp[x][y] += dp[x - c * (i + 1)][y - c * j] * t, dp[x][y] %= mod;
          }
        }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
