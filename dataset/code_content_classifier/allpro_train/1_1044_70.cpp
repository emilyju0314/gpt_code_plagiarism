#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int n;
long long f[20][maxn], cost[20][maxn], bq[20][maxn], dq[20][maxn];
int fa[20][maxn], dep[maxn];
long long dp[maxn];
int a[maxn];
struct Edge {
  int nxt, to;
  long long w;
} G[maxn << 1];
int bG = 0, hG[maxn];
void add(int x, int y, int w) {
  G[bG].nxt = hG[x];
  G[bG].to = y;
  G[bG].w = w;
  hG[x] = bG++;
  G[bG].nxt = hG[y];
  G[bG].to = x;
  G[bG].w = w;
  hG[y] = bG++;
}
void dfs(int v, int p, int dis) {
  dep[v] = dis;
  fa[0][v] = p;
  f[0][v] = 0;
  for (int i = hG[v]; i != -1; i = G[i].nxt) {
    int u = G[i].to;
    if (u == p) continue;
    bq[0][u] = G[i].w;
    dfs(u, v, dis + 1);
    f[0][v] += max(f[0][u] - 2 * G[i].w + dq[0][u], 0ll);
  }
  cost[0][v] = max(f[0][v] - 2 * bq[0][v] + dq[0][v], 0ll);
}
void dfs2(int v, int p, long long d) {
  dp[v] = d;
  for (int i = hG[v]; i != -1; i = G[i].nxt) {
    int u = G[i].to;
    if (u == p) continue;
    dfs2(u, v, max(d + f[0][v] - cost[0][u] + dq[0][v] - 2 * G[i].w, 0ll));
  }
}
void buildbz() {
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      if (fa[i - 1][j] == -1) {
        fa[i][j] = -1;
        f[i][j] = f[i - 1][j];
        cost[i][j] = cost[i - 1][j];
        bq[i][j] = bq[i - 1][j];
        dq[i][j] = dq[i - 1][j];
      } else {
        fa[i][j] = fa[i - 1][fa[i - 1][j]];
        f[i][j] = f[i - 1][j] + f[i - 1][fa[i - 1][j]];
        cost[i][j] = cost[i - 1][j] + cost[i - 1][fa[i - 1][j]];
        bq[i][j] = bq[i - 1][j] + bq[i - 1][fa[i - 1][j]];
        dq[i][j] = dq[i - 1][j] + dq[i - 1][fa[i - 1][j]];
      }
    }
  }
}
long long findans(int v, int u) {
  long long re = 0;
  if (dep[v] < dep[u]) swap(v, u);
  int cj = dep[v] - dep[u];
  for (int i = 19; i >= 0; i--) {
    if ((cj >> i) & 1) {
      re += dq[i][v] + f[i][v] - bq[i][v] - cost[i][v];
      v = fa[i][v];
    }
  }
  if (v == u) {
    re += f[0][v] + dq[0][v] + dp[v];
    return re;
  }
  for (int i = 19; i >= 0; i--) {
    if (fa[i][v] != fa[i][u]) {
      re += dq[i][v] + f[i][v] - bq[i][v] - cost[i][v];
      re += dq[i][u] + f[i][u] - bq[i][u] - cost[i][u];
      v = fa[i][v];
      u = fa[i][u];
    }
  }
  re += (dq[0][v] + f[0][v] - bq[0][v] - cost[0][v]);
  re += (dq[0][u] + f[0][u] - bq[0][u] - cost[0][u]);
  v = fa[0][v];
  re += dq[0][v] + f[0][v] + dp[v];
  return re;
}
int main() {
  int Q;
  scanf("%d%d", &n, &Q);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", dq[0] + i);
  }
  int x, y, w;
  memset(hG, -1, sizeof(hG));
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &x, &y, &w);
    x--;
    y--;
    add(x, y, w);
  }
  bq[0][0] = 0;
  dfs(0, -1, 0);
  dfs2(0, -1, 0);
  buildbz();
  while (Q--) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    printf("%I64d\n", findans(x, y));
  }
  return 0;
}
