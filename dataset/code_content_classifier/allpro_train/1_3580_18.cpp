#include <bits/stdc++.h>
using namespace std;
namespace runzhe2000 {
const int INF = 1000000000;
int n, m, a, b, d[105][105], timer, ecnt, vis[105], cnt[105], buscnt, s[105],
    t[105], must[105][105], an[105], last[105], f[105];
struct edge {
  int next, to;
} e[105 * 105];
void addedge(int a, int b) {
  e[++ecnt] = (edge){last[a], b};
  last[a] = ecnt;
}
int dfs(int x, int y) {
  int tmp = -1;
  for (int i = last[x]; i; i = e[i].next) {
    int j = e[i].to;
    if (d[x][j] + d[j][y] == d[x][y] && d[x][j] < INF)
      tmp = max(tmp, dfs(j, y));
  }
  if (tmp == -1) tmp = INF;
  tmp = min(tmp, an[x] + 1);
  return tmp;
}
void main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  memset(d, 63, sizeof(d));
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    d[u][v] = 1;
    addedge(u, v);
  }
  for (int i = 1; i <= n; i++) d[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  scanf("%d", &buscnt);
  for (int i = 1; i <= buscnt; i++) {
    scanf("%d%d", &s[i], &t[i]);
    memset(cnt, 0, sizeof(cnt));
    for (int j = 1; j <= n; j++)
      if (d[s[i]][j] + d[j][t[i]] == d[s[i]][t[i]] && d[s[i]][t[i]] < INF)
        cnt[d[s[i]][j]]++;
    for (int j = 1; j <= n; j++)
      if (d[s[i]][j] + d[j][t[i]] == d[s[i]][t[i]] && d[s[i]][t[i]] < INF &&
          cnt[d[s[i]][j]] == 1)
        must[i][j] = 1;
  }
  memset(an, 63, sizeof(an));
  for (an[b] = 0;;) {
    bool ok = 1;
    for (int i = 1; i <= buscnt; i++)
      for (int j = 1; j <= n; j++)
        if (must[i][j]) {
          ++timer;
          int ans = dfs(j, t[i]);
          if (ans < an[j]) an[j] = ans, ok = 0;
        }
    if (ok) break;
  }
  printf("%d\n", an[a] < INF ? an[a] : -1);
}
}  // namespace runzhe2000
int main() { runzhe2000::main(); }
