#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int len(const T &a) {
  return a.size();
}
constexpr int maxn = 2e5 + 10, maxl = 20;
struct edge {
  int v, u, i;
};
struct dsu {
  int p[maxn];
  dsu() { iota(p, p + maxn, 0); }
  int root(int v) { return p[v] == v ? v : p[v] = root(p[v]); }
  void unite(int v, int u) { p[root(v)] = root(u); }
};
struct tree {
  int guys1[maxn], guys2[maxn];
  int comp[maxn];
  bool mark[maxn];
  vector<edge> g[maxn];
  int par[maxn][maxl], dep[maxn];
  int par_edge[maxn];
  tree() {
    memset(par_edge, -1, sizeof(par_edge));
    for (int i = 0; i < maxn; ++i) {
      for (int j = 0; j < maxl; ++j) {
        par[i][j] = i;
      }
    }
  }
  void prep(int v) {
    mark[v] = true;
    for (int i = 1; i < maxl; ++i) {
      par[v][i] = par[par[v][i - 1]][i - 1];
    }
    for (auto &e : g[v]) {
      int u = e.v;
      if (u != par[v][0]) {
        par[u][0] = v;
        comp[u] = comp[v];
        par_edge[u] = e.i;
        dep[u] = dep[v] + 1;
        prep(u);
      }
    }
  }
  void prep() {
    int c = 0;
    for (int i = 0; i < maxn; ++i) {
      if (!mark[i]) {
        comp[i] = c++;
        par[i][0] = i;
        prep(i);
      }
    }
  }
  int get_par(int v, int k) {
    for (int i = 0; i < maxl; ++i) {
      if ((k >> i) & 1) {
        v = par[v][i];
      }
    }
    return v;
  }
  int lca(int v, int u) {
    if (dep[u] < dep[v]) {
      swap(u, v);
    }
    u = get_par(u, dep[u] - dep[v]);
    if (v == u) {
      return v;
    }
    for (int i = maxl - 1; i >= 0; --i) {
      if (par[v][i] != par[u][i]) {
        v = par[v][i];
        u = par[u][i];
      }
    }
    return par[v][0];
  }
  void direct(int from, int to) {
    if (comp[from] != comp[to]) {
      puts("No");
      exit(0);
    }
    int w = lca(from, to);
    guys1[from]++;
    guys1[w]--;
    guys2[to]++;
    guys2[w]--;
  }
  array<int, 2> check(int v) {
    mark[v] = true;
    array<int, 2> sum;
    sum[0] = guys1[v];
    sum[1] = guys2[v];
    for (auto &e : g[v]) {
      int u = e.v;
      if (u != par[v][0]) {
        auto ret = check(u);
        if (ret[0] > 0 && ret[1] > 0) {
          puts("No");
          exit(0);
        }
        sum[0] += ret[0];
        sum[1] += ret[1];
      }
    }
    return sum;
  }
};
int n, m, q;
edge es[maxn];
vector<edge> g[maxn];
bool cut[maxn];
bool mark[maxn];
int low[maxn], tin[maxn], timer;
void dfs(int v, int pe) {
  tin[v] = low[v] = timer++;
  mark[v] = true;
  for (auto &e : g[v]) {
    if (e.i == pe) {
      continue;
    }
    int u = e.v;
    if (mark[u]) {
      low[v] = min(low[v], tin[u]);
    } else {
      dfs(u, e.i);
      low[v] = min(low[v], low[u]);
      if (low[u] >= tin[u]) {
        cut[e.i] = true;
      }
    }
  }
}
dsu d;
tree t;
pair<int, int> qs[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v, --u;
    g[v].push_back({u, v, i});
    g[u].push_back({v, u, i});
    es[i] = {v, u, i};
  }
  for (int i = 0; i < n; ++i) {
    if (!mark[i]) {
      dfs(i, -1);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (!cut[i]) {
      d.unite(es[i].v, es[i].u);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (cut[i]) {
      int vv = d.root(es[i].v);
      int uu = d.root(es[i].u);
      t.g[vv].push_back({uu, vv, i});
      t.g[uu].push_back({vv, uu, i});
    }
  }
  t.prep();
  for (int i = 0; i < q; ++i) {
    int from, to;
    scanf("%d%d", &from, &to);
    --from, --to;
    qs[i] = {from, to};
  }
  for (int i = 0; i < q; ++i) {
    if (d.root(qs[i].first) != d.root(qs[i].second)) {
      t.direct(d.root(qs[i].first), d.root(qs[i].second));
    }
  }
  memset(t.mark, 0, sizeof(t.mark));
  for (int i = 0; i < n; ++i) {
    if (!t.mark[i]) {
      t.check(i);
    }
  }
  puts("Yes");
}
