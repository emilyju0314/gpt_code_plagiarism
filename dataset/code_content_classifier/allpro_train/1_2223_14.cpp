#include <bits/stdc++.h>
const int md = 998244353;
int f[2][2010][11];
long long fac[2010], ifac[2010];
long long g(int n, int m) {
  return n ? fac[m + n - 1] * ifac[m] % md * ifac[n - 1] % md : !m;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = *fac = 1; i <= 2000; i++) fac[i] = fac[i - 1] * i % md;
  ifac[2000] = 516258150;
  for (int i = 2000; i; i--) ifac[i - 1] = ifac[i] * i % md;
  while (t--) {
    int n, m[2] = {0}, c[2][11] = {0};
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j < 11; j++) f[0][i][j] = f[1][i][j] = !i && !j;
    int s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int x, y = 0, v;
      scanf("%d", &x);
      for (v = x % 11; x; x /= 10) y ^= 1;
      c[y][v]++;
      (s += v) %= 11;
      for (int j = m[y]++; j >= 0; j--)
        for (int k = 0; k < 11; k++)
          (f[y][j + 1][(k + v) % 11] += f[y][j][k]) %= md;
    }
    s = s * 6 % 11;
    for (int t = 0; t <= m[0]; t++)
      for (int v = 0; v < 11; v++)
        ans = (ans + f[0][t][(s - v + 11) % 11] * fac[t] % md * fac[m[0] - t] %
                         md * f[1][m[1] + 1 >> 1][v] % md * fac[m[1] / 2] % md *
                         fac[m[1] + 1 >> 1] % md * g(m[1] / 2 + 1, t) % md *
                         g(m[1] + 1 >> 1, m[0] - t)) %
              md;
    printf("%d\n", ans);
  }
  return 0;
}
