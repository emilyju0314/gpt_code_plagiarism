#include <bits/stdc++.h>
using namespace std;
int C[205][205], f[2][55][55][102];
int n, m, K, k, mx, i, j, r, prv, nxt, ans, mod = 1000000007;
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  C[0][0] = 1;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= i; j++) {
      if (C[i][j] > K) C[i][j] = K + 1;
      C[i + 1][j + 1] += C[i][j];
      C[i + 1][j] += C[i][j];
    }
  n >>= 1;
  prv = 0, nxt = 1;
  for (i = 1; i <= n; i++) f[prv][i][i][1] = 1;
  for (mx = 1; mx < m; mx++) {
    memset(f[nxt], 0, sizeof f[nxt]);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= i; j++)
        for (k = 1; k <= K; k++)
          if (f[prv][i][j][k]) {
            ans = (ans + 1ll * (m - mx) * f[prv][i][j][k]) % mod;
            for (r = 1; r <= n - i; r++) {
              int tmp = k * C[r + j - 1][j - 1];
              if (tmp > K) break;
              add(f[nxt][i + r][r][tmp], f[prv][i][j][k]);
            }
          }
    swap(prv, nxt);
  }
  printf("%d\n", ans);
  return 0;
}
