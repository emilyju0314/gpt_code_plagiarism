#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> g[N];
int par[N], sub[N], level[N], ans[N];
int DP[LOGN][N];
int n, m;
void dfs0(int u) {
  for (auto it = g[u].begin(); it != g[u].end(); it++)
    if (*it != DP[0][u]) {
      DP[0][*it] = u;
      level[*it] = level[u] + 1;
      dfs0(*it);
    }
}
void preprocess() {
  level[0] = 0;
  DP[0][0] = 0;
  dfs0(0);
  for (int i = 1; i < LOGN; i++)
    for (int j = 0; j < n; j++) DP[i][j] = DP[i - 1][DP[i - 1][j]];
}
int lca(int a, int b) {
  if (level[a] > level[b]) swap(a, b);
  int d = level[b] - level[a];
  for (int i = 0; i < LOGN; i++)
    if (d & (1 << i)) b = DP[i][b];
  if (a == b) return a;
  for (int i = LOGN - 1; i >= 0; i--)
    if (DP[i][a] != DP[i][b]) a = DP[i][a], b = DP[i][b];
  return DP[0][a];
}
int dist(int u, int v) { return level[u] + level[v] - 2 * level[lca(u, v)]; }
int nn;
void dfs1(int u, int p) {
  sub[u] = 1;
  nn++;
  for (auto it = g[u].begin(); it != g[u].end(); it++)
    if (*it != p) {
      dfs1(*it, u);
      sub[u] += sub[*it];
    }
}
int dfs2(int u, int p) {
  for (auto it = g[u].begin(); it != g[u].end(); it++)
    if (*it != p && sub[*it] > nn / 2) return dfs2(*it, u);
  return u;
}
void decompose(int root, int p) {
  nn = 0;
  dfs1(root, root);
  int centroid = dfs2(root, root);
  if (p == -1) p = centroid;
  par[centroid] = p;
  for (auto it = g[centroid].begin(); it != g[centroid].end(); it++) {
    g[*it].erase(centroid);
    decompose(*it, centroid);
  }
  g[centroid].clear();
}
void update(int u) {
  int x = u;
  while (1) {
    ans[x] = min(ans[x], dist(x, u));
    if (x == par[x]) break;
    x = par[x];
  }
}
int query(int u) {
  int x = u;
  int ret = INF;
  while (1) {
    ret = min(ret, dist(u, x) + ans[x]);
    if (x == par[x]) break;
    x = par[x];
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u - 1].insert(v - 1);
    g[v - 1].insert(u - 1);
  }
  preprocess();
  decompose(0, -1);
  for (int i = 0; i < n; i++) ans[i] = INF;
  update(0);
  while (m--) {
    int t, v;
    scanf("%d %d", &t, &v);
    v--;
    if (t == 1)
      update(v);
    else
      printf("%d\n", query(v));
  }
  return 0;
}
