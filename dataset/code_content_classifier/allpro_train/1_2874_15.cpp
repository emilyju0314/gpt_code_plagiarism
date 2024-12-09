#include <bits/stdc++.h>
using namespace std;
int f[20][100010], g[20][100010], F[20][100010], G[20][100010], ans[100010],
    x[200010];
unsigned int le[200010], ri[200010];
int main() {
  int k, n;
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%u%u%d", &le[i], &ri[i], &x[i]);
    int a = (le[i] >> k), b = (ri[i] >> k), c = le[i] & ((1 << k) - 1),
        d = ri[i] & ((1 << k) - 1);
    a++;
    b++;
    c++;
    d++;
    for (int j = 0; j < 16; j++)
      if ((x[i] >> j) & 1) {
        g[j][a]++;
        g[j][b + 1]--;
        if (a == b)
          f[j][c]++, f[j][d + 1]--;
        else if (a + 1 == b)
          f[j][c]++, f[j][1]++, f[j][d + 1]--;
        else
          f[j][1]++;
      }
  }
  for (int i = 0; i < 16; i++)
    for (int j = 1; j <= (1 << k); j++)
      f[i][j] += f[i][j - 1], g[i][j] += g[i][j - 1];
  for (int i = 0; i < 16; i++)
    for (int j = 1; j <= (1 << k); j++) {
      f[i][j] = (f[i][j] ? 1 : 0);
      g[i][j] = (g[i][j] ? 1 : 0);
      F[i][j] = F[i][j - 1] + f[i][j];
      G[i][j] = G[i][j - 1] + g[i][j];
    }
  for (int i = 1; i <= n; i++) {
    int a = (le[i] >> k), b = (ri[i] >> k), c = le[i] & ((1 << k) - 1),
        d = ri[i] & ((1 << k) - 1);
    a++;
    b++;
    c++;
    d++;
    for (int j = 0; j < 16; j++)
      if (!((x[i] >> j) & 1))
        if (a == b && g[j][a] && F[j][d] - F[j][c - 1])
          return puts("impossible"), 0;
        else if (a < b) {
          bool ok =
              ((g[j][a] && F[j][1 << k] - F[j][c - 1]) || (g[j][b] && F[j][d]));
          if (a + 1 < b) ok |= (G[j][b - 1] - G[j][a] && F[j][1 << k]);
          if (ok) return puts("impossible"), 0;
        }
  }
  puts("possible");
  for (int i = 0; i < 16; i++)
    for (int j = 1; j <= (1 << k); j++) ans[j] ^= (f[i][j] << i);
  for (int i = 1; i <= (1 << k); i++) printf("%d\n", ans[i]), ans[i] = 0;
  for (int i = 0; i < 16; i++)
    for (int j = 1; j <= (1 << k); j++) ans[j] ^= (g[i][j] << i);
  for (int i = 1; i <= (1 << k); i++) printf("%d\n", ans[i]);
  return 0;
}
