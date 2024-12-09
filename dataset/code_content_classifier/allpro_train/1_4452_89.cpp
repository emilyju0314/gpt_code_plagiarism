#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, sgn = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * sgn;
}
const int N = 510;
int ld, sz[N], tot, siz[N];
short f[N][N][N], col[N], tmp[N][N], dfn[N], ind[N], tim, n;
vector<pair<int, int> > G[N];
int dis[N][N];
void dfs1(int x, int p) {
  dfn[x] = ++tim;
  ind[tim] = x;
  sz[x] = 1;
  for (pair<int, int> y : G[x]) {
    if (y.first == p) continue;
    dfs1(y.first, x);
    sz[x] += sz[y.first];
  }
}
void dfs2(int *d, int x, int p, int ddis = 0) {
  d[x] = ddis;
  for (pair<int, int> y : G[x]) {
    if (y.first == p) continue;
    dfs2(d, y.first, x, min(ddis + y.second, ld + 1));
  }
}
void dp(int x, int p) {
  for (int i = 1; i <= n; i++)
    if (dis[x][i] <= ld && x != i) f[x][0][i] = 0;
  f[x][1][x] = col[x] ^ 1;
  siz[x] = 1;
  for (pair<int, int> d : G[x]) {
    int y = d.first;
    if (y == p) continue;
    dp(y, x);
    for (int i = 0; i <= min(siz[x] + siz[y], tot); i++)
      for (int j = 1; j <= n; j++) tmp[i][j] = n + 1;
    for (int i = 0; i <= min(siz[x], tot); i++)
      for (int j = 0; j <= min(siz[y], tot); j++) {
        short mn = n + 1;
        for (int l = dfn[y]; l <= dfn[y] + sz[y] - 1; l++)
          mn = min(mn, f[y][j][ind[l]]);
        for (int l = 1; l <= n; l++) {
          if (f[x][i][l] + f[y][j][l] < tmp[i + j][l])
            tmp[i + j][l] = f[x][i][l] + f[y][j][l];
          if (l < dfn[y] || l > dfn[y] + sz[y] - 1)
            if (tmp[i + j][ind[l]] > f[x][i][ind[l]] + mn)
              tmp[i + j][ind[l]] = f[x][i][ind[l]] + mn;
        }
      }
    for (int i = 0; i <= min(siz[x] + siz[y], tot); i++)
      for (int j = 1; j <= n; j++) f[x][i][j] = tmp[i][j];
    siz[x] += siz[y];
  }
}
signed main() {
  n = read(), ld = read();
  tot = 0;
  for (int i = 1; i <= n; i++) col[i] = read(), tot += col[i];
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(), w = read();
    G[u].push_back(pair<int, int>(v, w));
    G[v].push_back(pair<int, int>(u, w));
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 1; k <= n; k++) f[i][j][k] = n + 1;
  for (int i = 1; i <= n; i++) dfs2(dis[i], i, 0);
  dfs1(1, 0);
  dp(1, 0);
  short ans = n + 1;
  for (int i = 1; i <= n; i++) ans = min(ans, f[1][tot][i]);
  if (ans == n + 1)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}
