#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
int n, m;
vector<int> G[N];
int fa[N][20], dep[N], d[N];
void pre_dfs(int u, int f) {
  dep[u] = dep[fa[u][0] = f] + 1;
  for (int i = 1; i <= 18; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  vector<int> e;
  for (int v : G[u])
    if (v != f) e.push_back(v), pre_dfs(v, u);
  G[u] = e;
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 18; ~i; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 18; ~i; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int jmp(int x, int d) {
  for (int i = 18; ~i; i--)
    if (d >= (1 << i)) d -= 1 << i, x = fa[x][i];
  return x;
}
vector<pair<int, int> > e[N];
int blk[N], c[N], ct;
void sub_dfs(int u, int f) {
  for (int v : G[u]) sub_dfs(v, u), d[u] += d[v];
  if (d[u])
    e[u].push_back(pair<int, int>(f, 0)), e[f].push_back(pair<int, int>(u, 0));
}
void dfs(int u, int co) {
  if (c[u] >= 0 && c[u] != co) {
    puts("-1");
    exit(0);
  }
  if (c[u] >= 0) return;
  c[u] = co;
  blk[u] = ct;
  for (pair<int, int> v : e[u]) dfs(v.first, co ^ v.second);
}
pair<int, int> f[N], g[N];
int ans[N];
pair<int, int> mrg(pair<int, int> a, pair<int, int> b) {
  return pair<int, int>(max(a.first, b.first), min(a.second, b.second));
}
bool work(int u, int k) {
  for (int v : G[u])
    if (!work(v, k)) return false;
  f[u] = pair<int, int>(1, k);
  static int ex[N];
  int t = 0;
  for (int v : G[u])
    if (blk[v]) {
      if (blk[v] == blk[u]) {
        if (!c[v])
          f[u] = mrg(f[u], pair<int, int>(1, f[v].second - 1));
        else
          f[u] = mrg(f[u], pair<int, int>(f[v].first + 1, k));
      } else {
        if (!ex[blk[v]]) ex[blk[v]] = ++t, g[t] = pair<int, int>(1, k);
        int z = ex[blk[v]];
        if (!c[v])
          g[z] = mrg(g[z], pair<int, int>(1, f[v].second - 1));
        else
          g[z] = mrg(g[z], pair<int, int>(f[v].first + 1, k));
      }
    }
  for (int v : G[u]) ex[blk[v]] = 0;
  if (f[u].first > f[u].second) return false;
  pair<int, int> z(1, k);
  for (int i = 1; i <= t; i++) {
    if (g[i].first > g[i].second) return false;
    if (k - g[i].second + 1 < g[i].first)
      g[i] = pair<int, int>(k - g[i].second + 1, k - g[i].first + 1);
    z = mrg(z, g[i]);
  }
  pair<int, int> p = mrg(z, f[u]);
  pair<int, int> q =
      mrg(pair<int, int>(k - z.second + 1, k - z.first + 1), f[u]);
  if (p.first > p.second && q.first > q.second) return false;
  if (p.first > p.second)
    f[u] = q;
  else if (q.first > q.second)
    f[u] = p;
  else
    f[u] = pair<int, int>(min(p.first, q.first), max(p.second, q.second));
  return true;
}
void cope(int u, int k, bool r) {
  static int ex[N], rm[N];
  int t = 0;
  for (int v : G[u])
    if (blk[v] && blk[v] != blk[u]) {
      if (!ex[blk[v]])
        rm[ex[blk[v]] = ++t] = blk[v], g[t] = pair<int, int>(1, k);
      int z = ex[blk[v]];
      if (!c[v])
        g[z] = mrg(g[z], pair<int, int>(1, f[v].second - 1));
      else
        g[z] = mrg(g[z], pair<int, int>(f[v].first + 1, k));
    }
  for (int v : G[u]) ex[blk[v]] = 0;
  static bool rv[N];
  for (int i = 1; i <= t; i++)
    rv[rm[i]] = (g[i].first <= ans[u] && ans[u] <= g[i].second) ? 0 : 1;
  for (int v : G[u]) {
    if (!blk[v])
      ans[v] = f[v].first, cope(v, k, 0);
    else {
      bool o = blk[v] == blk[u] ? r : rv[blk[v]];
      if (!o)
        ans[v] = c[v] ? f[v].first : f[v].second;
      else
        ans[v] = c[v] ? k - f[v].first + 1 : k - f[v].second + 1;
      cope(v, k, o);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1, u, v; i < n; i++)
    scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
  pre_dfs(1, 0);
  for (int i = 1, x, y, l; i <= m; i++) {
    scanf("%d%d", &x, &y);
    l = LCA(x, y);
    if (x != l) ++d[x], --d[jmp(x, dep[x] - dep[l] - 1)];
    if (y != l) ++d[y], --d[jmp(y, dep[y] - dep[l] - 1)];
    if (x != l && y != l)
      e[x].push_back(pair<int, int>(y, 1)),
          e[y].push_back(pair<int, int>(x, 1));
  }
  sub_dfs(1, 0);
  memset(c, -1, sizeof(c));
  for (int i = 2; i <= n; i++)
    if (!blk[i]) ++ct, dfs(i, 0);
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (work(1, mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
  work(1, l);
  ans[1] = f[1].first;
  cope(1, l, 0);
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
