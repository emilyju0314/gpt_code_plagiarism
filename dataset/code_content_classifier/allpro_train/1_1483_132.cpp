#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int buffer = 200004;
const int NMAX = 1004;
inline int Pow(const int x, const int n) {
  if (n == 0) return 1;
  if (n & 1) return 1LL * x * Pow(x, n - 1) % MOD;
  int a = Pow(x, n / 2);
  return 1LL * a * a % MOD;
}
int dp[NMAX], fact[NMAX * NMAX], inv[NMAX * NMAX], n, m, k;
inline int Comb(const int n, const int k) {
  if (k > n) return 0;
  int ret = 1LL * fact[n] * inv[n - k] % MOD;
  return 1LL * ret * inv[k] % MOD;
}
int main() {
  cin >> n >> m >> k;
  fact[0] = inv[0] = 1;
  for (int i = (1); i <= (max(n, k)); ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
    inv[i] = Pow(fact[i], MOD - 2);
  }
  for (int i = (1); i <= (n); ++i) {
    dp[i] = Pow(i, n);
    for (int j = (1); j <= (i - 1); ++j) {
      dp[i] -= 1LL * dp[j] * Comb(i, j) % MOD;
      if (dp[i] < 0) dp[i] += MOD;
    }
  }
  int ans = 0, x, y, z;
  if (m == 1) {
    for (int distincte = (1); distincte <= (min(n, k)); ++distincte) {
      ans += 1LL * dp[distincte] * Comb(k, distincte) % MOD;
      ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
  }
  if (m == 2) {
    for (int distincte = (1); distincte <= (min(n, k)); ++distincte) {
      x = 1LL * dp[distincte] * Comb(k, distincte) % MOD;
      x = 1LL * x * x % MOD;
      ans = (ans + x) % MOD;
    }
    cout << ans << "\n";
    return 0;
  }
  for (int distincte = (1); distincte <= (min(n, k)); ++distincte) {
    for (int intersect = (1); intersect <= (distincte); ++intersect) {
      x = 1LL * dp[distincte] * Comb(k, distincte) % MOD;
      z = 1LL * Pow(intersect, n * (m - 2)) * Comb(distincte, intersect) % MOD;
      y = 1LL * dp[distincte] * Comb(k - distincte, distincte - intersect) %
          MOD;
      x = 1LL * x * y % MOD;
      x = 1LL * x * z % MOD;
      ans = (ans + x) % MOD;
    }
  }
  cout << ans << "\n";
  return 0;
}
