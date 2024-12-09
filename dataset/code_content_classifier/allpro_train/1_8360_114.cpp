#include <bits/stdc++.h>
const int MAXN = 1000 + 5;
const int MAXM = 2e5 + 5;
int f[2][MAXN][MAXN];
int du[2][MAXN];
int g[MAXN][MAXN];
int ans[MAXM];
inline void work(int a, int b, int u, int v, int x, int y) {
  int to = f[b][v][x];
  f[a][u][x] = v;
  f[b][v][x] = u;
  if (!to)
    f[b][v][y] = 0;
  else
    work(b, a, v, to, y, x);
}
int main() {
  int a, b, m;
  scanf("%d%d%d", &a, &b, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u][v] = i;
    du[0][u]++;
    du[1][v]++;
    int t0 = 1, t1 = 1;
    while (f[0][u][t0]) ++t0;
    while (f[1][v][t1]) ++t1;
    if (t0 == t1)
      f[0][u][t0] = v, f[1][v][t1] = u;
    else
      work(0, 1, u, v, t0, t1);
  }
  int mx = 0;
  for (int i = 1; i <= a; ++i) mx = std::max(mx, du[0][i]);
  for (int i = 1; i <= b; ++i) mx = std::max(mx, du[1][i]);
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= mx; ++j) {
      if (f[0][i][j]) ans[g[i][f[0][i][j]]] = j;
    }
  }
  printf("%d\n", mx);
  for (int i = 1; i <= m; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
