#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void upmin(T &x, T y) {
  y < x ? x = y : 0;
}
template <typename T>
inline void upmax(T &x, T y) {
  x < y ? x = y : 0;
}
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long OO = 1e18;
const int N = 210;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
long long f[N][N], g[N], C[N][N];
int main() {
  int n = gi(), d = gi(), mod = gi(), i, j, k;
  long long ans = 0;
  for (i = 0; i <= n; i++)
    for (j = C[i][0] = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  f[1][0] = g[1] = 1;
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= d; j++)
      for (k = 1; k < i; k++)
        f[i][j] =
            (f[i][j] + f[i - k][j - 1] * C[i - 2][k - 1] % mod * g[k]) % mod;
    for (j = 1; j < d; j++) (g[i] += f[i][j]) %= mod;
  }
  for (i = 0; i <= d; i++)
    for (j = 0; i + j <= d; j++)
      if (j != 1)
        for (k = 1; k <= n; k++) ans = (ans + f[k][i] * f[n - k + 1][j]) % mod;
  ans = ans * 2 * n * (n - 1) % mod;
  cout << ans << endl;
  return 0;
}
