#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
long long c[maxn][maxn], pw[2][maxn], f[maxn][maxn];
inline int add(long long a, long long b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int mul(long long a, long long b) { return a * b % mod; }
inline long long kpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void init(int n, int m) {
  for (int i = 0; i <= n; ++i) c[i][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  for (int i = 0; i <= n; ++i) {
    pw[0][i] = kpow(m - 1, i);
    pw[1][i] = kpow(m, i);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  init(n, m);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      for (int k = 1; k <= j; ++k)
        f[i][j] =
            add(f[i][j],
                mul(mul(mul(f[i - 1][j - k], c[n - j + k][k]), pw[1][j - k]),
                    pw[0][n - j]));
      f[i][j] =
          add(f[i][j], mul(f[i - 1][j], mul((pw[1][j] - pw[0][j] + mod) % mod,
                                            kpow(m - 1, n - j))));
    }
  cout << f[n][n];
  return 0;
}
