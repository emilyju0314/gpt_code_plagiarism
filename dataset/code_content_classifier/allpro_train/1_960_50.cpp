#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000;
const int MAXB = 20;
int n, m, k, c;
int fa[MAXN][MAXB], dep[MAXN];
bool vis[MAXN];
vector<int> g[MAXN], cir[MAXN];
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int b = MAXB - 1; b >= 0; b--)
    if (dep[fa[u][b]] >= dep[v]) u = fa[u][b];
  if (u == v) return u;
  for (int b = MAXB - 1; b >= 0; b--)
    if (fa[u][b] != fa[v][b]) u = fa[u][b], v = fa[v][b];
  return fa[u][0];
}
inline int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
void dfs(int u, int f, int d) {
  fa[u][0] = f;
  dep[u] = d;
  vis[u] = 1;
  for (int b = 1; b < MAXB; b++) fa[u][b] = fa[fa[u][b - 1]][b - 1];
  bool flag = 0;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (!vis[v]) dfs(v, u, d + 1), flag = 1;
  }
  if (!flag) {
    if (d >= (n - 1) / k + 1) {
      printf("PATH\n%d\n", d);
      for (int v = u; v; v = fa[v][0]) printf("%d ", v);
      putchar('\n');
      exit(0);
    }
    int x = 0, y = 0;
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v != f) {
        if (x == 0)
          x = v;
        else {
          y = v;
          break;
        }
      }
    }
    c++;
    if ((dist(u, x) + 1) % 3 != 0) {
      int p = lca(u, x);
      for (int v = u; v != p; v = fa[v][0]) cir[c].push_back(v);
      int t = cir[c].size();
      for (int v = x; v != fa[p][0]; v = fa[v][0]) cir[c].push_back(v);
      reverse(cir[c].begin() + t, cir[c].end());
    } else if ((dist(u, y) + 1) % 3 != 0) {
      int p = lca(u, y);
      for (int v = u; v != p; v = fa[v][0]) cir[c].push_back(v);
      int t = cir[c].size();
      for (int v = y; v != fa[p][0]; v = fa[v][0]) cir[c].push_back(v);
      reverse(cir[c].begin() + t, cir[c].end());
    } else {
      cir[c].push_back(u);
      int p = lca(x, y);
      for (int v = x; v != p; v = fa[v][0]) cir[c].push_back(v);
      int t = cir[c].size();
      for (int v = y; v != fa[p][0]; v = fa[v][0]) cir[c].push_back(v);
      reverse(cir[c].begin() + t, cir[c].end());
    }
    if (c == k) {
      puts("CYCLES");
      for (int i = 1; i <= k; i++) {
        printf("%d\n", cir[i].size());
        for (int j = 0; j < cir[i].size(); j++) printf("%d ", cir[i][j]);
        putchar('\n');
      }
      exit(0);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  c = 0;
  dfs(1, 0, 1);
  puts("-1");
  return 0;
}
