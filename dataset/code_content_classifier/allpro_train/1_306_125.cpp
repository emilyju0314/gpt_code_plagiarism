#include <bits/stdc++.h>
using namespace std;
int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, -1, 1, 0};
int qx[100001], head, tail, qy[100001];
int ena[100001], ech[100001];
int stx, sty, enx, eny;
int res;
char ress[3001], s[3001];
int n, m, k;
char g[100][100];
int ans[3001];
int f[100][100];
int now;
int vis[100][100];
inline void work() {
  now++;
  g[stx][sty] = ech[1];
  qx[head = tail = 0] = enx, qy[0] = eny;
  memset(f, 63, sizeof(f));
  f[enx][eny] = 0;
  while (head <= tail) {
    int x = qx[head], y = qy[head++];
    for (int i = 0; i < 4; ++i) {
      int xx = x + dirx[i], yy = y + diry[i];
      if (xx < 0 || yy < 0 || xx >= n || yy >= m || !ena[g[xx][yy]]) continue;
      if (f[xx][yy] > f[x][y] + 1) {
        f[xx][yy] = f[x][y] + 1;
        qx[++tail] = xx, qy[tail] = yy;
      }
    }
  }
  if (f[stx][sty] > res) return;
  memset(ans, 63, sizeof(ans));
  ans[f[stx][sty]] = ech[1];
  qx[head = tail = 0] = stx, qy[0] = sty;
  while (head <= tail) {
    int x = qx[head], y = qy[head++];
    if (ans[f[x][y]] != g[x][y]) continue;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dirx[i], yy = y + diry[i];
      if (xx < 0 || yy < 0 || xx >= n || yy >= m || !ena[g[xx][yy]]) continue;
      if (f[xx][yy] == f[x][y] - 1 && vis[xx][yy] != now) {
        ans[f[xx][yy]] =
            ((ans[f[xx][yy]]) < (g[xx][yy]) ? (ans[f[xx][yy]]) : (g[xx][yy]));
        qx[++tail] = xx, qy[tail] = yy;
        vis[xx][yy] = now;
      }
    }
  }
  int sn = 0;
  for (int i = f[stx][sty] - 1; i > 0; --i) s[sn++] = ans[i] + 'a';
  s[sn] = 0;
  if (res > f[stx][sty] || res == f[stx][sty] && strcmp(s, ress) == -1)
    res = f[stx][sty], memcpy(ress, s, sizeof(s));
}
inline void dfs(int p, int la) {
  if (p > k) {
    work();
    return;
  }
  for (int i = la; i < 26; ++i) {
    ena[i] = 1;
    ech[p] = i;
    dfs(p + 1, i + 1);
    ena[i] = 0;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", g[i]);
    for (int j = 0; j < m; ++j)
      if (g[i][j] == 'S')
        stx = i, sty = j;
      else if (g[i][j] == 'T')
        enx = i, eny = j;
      else
        g[i][j] -= 'a';
  }
  res = 214748364;
  dfs(1, 0);
  if (res == 214748364)
    printf("-1\n");
  else
    printf("%s\n", ress);
  return 0;
}
