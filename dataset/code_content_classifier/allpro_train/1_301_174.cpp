#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
long long n, d, mod, dp[maxn][11], pd[maxn][11], t[11];
inline long long ksm(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * x % mod;
    n >>= 1;
    x = x * x % mod;
  }
  return ret;
}
inline long long solve() {
  dp[0][0] = 1;
  for (int i = 1; i <= n / 2; ++i)
    if ((i - 1) % (d - 1) == 0) {
      long long f = (i == 1) ? 1 : dp[i - 1][d - 1];
      for (int j = 0; j < n; ++j) memset(pd[j], 0, (d + 1) * sizeof pd[0][0]);
      t[0] = 1;
      for (int j = 1; j <= d; ++j)
        t[j] = t[j - 1] * (f + j - 1) % mod * ksm(j, mod - 2) % mod;
      for (int j = 0; j <= d; ++j)
        for (int k = 0; k <= d; ++k)
          if (j + k <= d)
            for (int l = 0; l < n; ++l)
              if (l + k * i < n)
                pd[l + k * i][j + k] =
                    (pd[l + k * i][j + k] + dp[l][j] * t[k]) % mod;
      for (int j = 0; j < n; ++j)
        memcpy(dp[j], pd[j], (d + 1) * sizeof pd[0][0]);
    }
  long long ret = dp[n - 1][d];
  if (n % 2 == 0)
    ret = (ret - dp[n / 2 - 1][d - 1] * (dp[n / 2 - 1][d - 1] - 1) / 2) % mod;
  return ret < 0 ? ret + mod : ret;
}
int main() {
  cin >> n >> d >> mod;
  cout << ((n <= 2) ? 1 : solve());
  return 0;
}
