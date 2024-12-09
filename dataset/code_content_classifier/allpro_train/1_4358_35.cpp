#include <bits/stdc++.h>
const int fin = 0, maxn = 2010;
const double Pi = 3.1415926;
const int D = 5, W = 18;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
int n, m;
bool G[maxn][maxn], g[maxn][maxn], v[maxn][maxn];
int x[maxn * maxn], y[maxn * maxn];
double sx, sy;
int cnt;
inline void dfs(int x, int y) {
  bool F = 0;
  ++cnt, sx += x, sy += y;
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
    if (v[tx][ty]) continue;
    if (!g[tx][ty]) {
      F = 1;
      continue;
    }
    v[tx][ty] = 1;
    dfs(tx, ty);
  }
  if (F) ::x[m] = x, ::y[m++] = y;
}
int main() {
  if (fin) {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
  }
  int i, j, ii, ij, p, c0 = 0, c1 = 0, c;
  double t, E;
  scanf("%d", &n);
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) scanf("%d", &p), G[i][j] = !!p;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
      t = c = 0;
      for (ii = i - D; ii <= i + D; ++ii)
        for (ij = j - D; ij <= j + D; ++ij) {
          if (ii < 0 || ii >= n || ij < 0 || ij >= n) continue;
          if ((ii - i) * (ii - i) + (ij - j) * (ij - j) > W) continue;
          ++c, t += G[ii][ij];
        }
      g[i][j] = (t / c > 0.5);
    }
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      if (g[i][j] && !v[i][j]) {
        cnt = m = 0, sx = sy = 0, E = 0;
        v[i][j] = 1, dfs(i, j);
        if (cnt < 150) continue;
        sx /= cnt, sy /= cnt;
        for (p = 0; p < m; ++p) {
          t = (x[p] - sx) * (x[p] - sx) + (y[p] - sy) * (y[p] - sy);
          if (E < t) E = t;
        }
        t = cnt / E;
        (fabs(t - Pi) < fabs(t - 2) ? c0 : c1)++;
      }
  printf("%d %d\n", c0, c1);
  return 0;
}
