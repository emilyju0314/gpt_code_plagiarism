#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5, LOG = 20;
vector<int> ga[maxn], gb[maxn];
map<int, bool> m[maxn];
int n;
int fa[maxn][LOG], f[maxn], dep[maxn];
int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }
void dfs1(int x, int f = 0) {
  fa[x][0] = f;
  dep[x] = dep[f] + 1;
  for (int k = (1); k < (LOG); ++k) fa[x][k] = fa[fa[x][k - 1]][k - 1];
  for (auto y : ga[x]) {
    if (y == f) continue;
    dfs1(y, x);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int k = (LOG)-1; k >= (0); --k)
    if (dep[fa[x][k]] >= dep[y]) x = fa[x][k];
  if (x == y) return x;
  for (int k = (LOG)-1; k >= (0); --k)
    if (fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
  return fa[x][0];
}
void get(int x, int y) {
  int l = lca(x, y), z;
  if (find(x) != find(l)) {
    z = find(x);
  } else {
    z = y;
    for (int k = (LOG)-1; k >= (0); --k)
      if (dep[fa[z][k]] > dep[l] && find(fa[z][k]) != find(l)) {
        z = fa[z][k];
      }
  }
  printf("%d %d %d %d\n", z, fa[z][0], x, y);
  f[z] = fa[z][0];
}
void dfs2(int x, int f = 0) {
  for (auto y : gb[x]) {
    if (y == f) continue;
    dfs2(y, x);
    get(y, x);
  }
}
signed main() {
  cin >> n;
  int u, v;
  for (int i = (0); i < (n - 1); ++i) {
    cin >> u >> v;
    m[u][v] = m[v][u] = 1;
    ga[u].push_back(v);
    ga[v].push_back(u);
  }
  dfs1(1);
  printf("%d\n", n - 1);
  for (int i = (0); i < (n - 1); ++i) {
    cin >> u >> v;
    gb[u].push_back(v);
    gb[v].push_back(u);
  }
  dfs2(1);
}
