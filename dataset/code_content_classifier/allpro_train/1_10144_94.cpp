#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, f[200005][25], fa[200005], dep[200005], fa2[200005], ans[1000005],
    maxn[200005][25], mx, nw[200005];
bool vis[1000005];
struct node {
  int u, v, id, w;
  node(){};
  node(int V, int W) {
    v = V;
    w = W;
  }
} e[1000005];
vector<node> G[1000005];
void makeSet(int x) {
  for (int i = 1; i <= x; i++) fa[i] = i;
}
int findSet(int x) {
  if (fa[x] != x) fa[x] = findSet(fa[x]);
  return fa[x];
}
void makeSet2(int x) {
  for (int i = 1; i <= x; i++) fa2[i] = i, nw[i] = INF;
}
int findSet2(int x) {
  if (fa2[x] != x) fa2[x] = findSet2(fa2[x]);
  return fa2[x];
}
bool cmp(node a, node b) { return a.w < b.w; }
void unionSet() {
  for (int i = 1; i <= m; i++) {
    int U = findSet(e[i].u), V = findSet(e[i].v);
    if (U != V) {
      fa[U] = V;
      vis[i] = 1;
      G[e[i].u].push_back(node(e[i].v, e[i].w));
      G[e[i].v].push_back(node(e[i].u, e[i].w));
    }
  }
}
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  for (int i = 0; i < G[x].size(); i++) {
    int tmp = G[x][i].v, tot = G[x][i].w;
    if (tmp != fa) {
      f[tmp][0] = x;
      maxn[tmp][0] = tot;
      dfs(tmp, x);
    }
  }
}
void prepare() {
  f[1][0] = 0;
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      maxn[i][j] = max(maxn[i][j - 1], maxn[f[i][j - 1]][j - 1]);
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  }
}
void add(int &x, int maxdep) {
  for (int i = 19; i >= 0; i--)
    if (dep[f[x][i]] >= maxdep) mx = max(mx, maxn[x][i]), x = f[x][i];
}
int Doubly(int x, int y) {
  mx = 0;
  if (dep[x] < dep[y]) add(y, dep[x]);
  if (dep[x] > dep[y]) add(x, dep[y]);
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      mx = max(mx, maxn[x][i]);
      mx = max(mx, maxn[y][i]);
      x = f[x][i], y = f[y][i];
    }
  }
  mx = max(mx, maxn[x][0]);
  mx = max(mx, maxn[y][0]);
  return f[x][0];
}
int main() {
  scanf("%d %d", &n, &m);
  makeSet(n);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    e[i].id = i;
  }
  sort(e + 1, e + 1 + m, cmp);
  unionSet();
  dfs(1, 0);
  prepare();
  makeSet2(n);
  for (int i = 1; i <= m; i++) {
    if (!vis[i]) {
      int lca = Doubly(e[i].u, e[i].v);
      ans[e[i].id] = mx;
      while (dep[findSet2(e[i].u)] > dep[lca]) {
        int uu = findSet2(e[i].u);
        nw[uu] = e[i].w;
        fa2[uu] = findSet2(f[uu][0]);
      }
      while (dep[findSet2(e[i].v)] > dep[lca]) {
        int vv = findSet2(e[i].v);
        nw[vv] = e[i].w;
        fa2[vv] = findSet2(f[vv][0]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (vis[i]) {
      if (dep[e[i].u] > dep[e[i].v])
        ans[e[i].id] = nw[e[i].u];
      else
        ans[e[i].id] = nw[e[i].v];
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
