#include <bits/stdc++.h>
using namespace std;
const int M = 110;
const int inf = 1000000000;
int main() {
  int n, m, g[M][M] = {0};
  double f[M][M] = {0.0};
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = inf;
      f[i][j] = 0;
    }
    g[i][i] = 0;
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u][v] = 1, f[u][v] = 1;
    g[v][u] = 1, f[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (g[j][k] > g[j][i] + g[i][k]) {
          g[j][k] = g[j][i] + g[i][k];
          f[j][k] = f[j][i] * f[i][k];
        } else {
          if (g[j][k] == g[j][i] + g[i][k]) {
            f[j][k] += f[j][i] * f[i][k];
          }
        }
      }
    }
  }
  double ans = 1.0;
  for (int i = 2; i < n; i++)
    if (g[1][n] == g[1][i] + g[i][n])
      ans = max(ans, (((double)2.0 * (f[1][i] * f[i][n])) / f[1][n]));
  printf("%.20lf\n", ans);
  return 0;
}
