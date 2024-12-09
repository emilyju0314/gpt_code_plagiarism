#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 5e3 + 3;
const int M = 5e5 + 3;
long long f[N][N];
int n, m;
long long ans[M];
int a[M], w[M];
long long sum1, sum2;
inline long long quick(long long x, long long y) {
  if (x < 0) return 0;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
    if (a[i] == 1)
      sum1 += w[i];
    else
      sum2 += w[i];
  }
  f[1][1] = sum1 * quick(sum1 + sum2, mod - 2) % mod;
  f[1][0] = sum2 * quick(sum1 + sum2, mod - 2) % mod;
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j <= i; ++j) {
      int g = i - j;
      f[i + 1][j + 1] =
          (f[i + 1][j + 1] +
           f[i][j] * (sum1 + j) % mod * quick(sum1 + sum2 + j - g, mod - 2)) %
          mod;
      f[i + 1][j] = (f[i + 1][j] + f[i][j] * max(0ll, sum2 - g) % mod *
                                       quick(sum1 + sum2 + j - g, mod - 2)) %
                    mod;
    }
  }
  long long r1 = 0, r2 = 0;
  for (int i = 0; i <= m; ++i) {
    r1 = (r1 + f[m][i] * (sum1 + i)) % mod;
    r2 = (r2 + f[m][i] * (max(0ll, sum2 - m + i))) % mod;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1)
      ans[i] = r1 * w[i] % mod * quick(sum1, mod - 2) % mod;
    else
      ans[i] = r2 * w[i] % mod * quick(sum2, mod - 2) % mod;
    printf("%I64d\n", ans[i]);
  }
  return 0;
}
