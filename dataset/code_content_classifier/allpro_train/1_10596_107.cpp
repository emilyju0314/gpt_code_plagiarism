#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
vector<int> g[N], q[N];
bool read() {
  if (!(cin >> n >> m)) return false;
  for (int i = 0; i < int(n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < int(m); ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    q[a].push_back(b);
    q[b].push_back(a);
  }
  return true;
}
int l[N], r[N], T;
void dfs(int v) {
  l[v] = r[v] = T++;
  for (int i = 0; i < int(g[v].size()); ++i) {
    int to = g[v][i];
    if (l[to] == -1) {
      dfs(to);
      r[v] = r[to];
    }
  }
}
pair<int, int> st[N * 4];
int upd[N * 4];
pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first)
    return make_pair(a.first, a.second + b.second);
  else
    return min(a, b);
}
void push(int v, int l, int r) {
  if (upd[v] != 0) {
    st[v].first += upd[v];
    if (l != r) {
      upd[v * 2 + 1] += upd[v];
      upd[v * 2 + 2] += upd[v];
    }
    upd[v] = 0;
  }
}
void update(int v, int l, int r, int L, int R, int val) {
  push(v, l, r);
  if (L == l && R == r) {
    upd[v] += val;
    return;
  }
  int m = (l + r) >> 1;
  if (R <= m) update(v * 2 + 1, l, m, L, R, val);
  if (L > m) update(v * 2 + 2, m + 1, r, L, R, val);
  if (L <= m && R > m)
    update(v * 2 + 1, l, m, L, m, val),
        update(v * 2 + 2, m + 1, r, m + 1, R, val);
  push(v * 2 + 1, l, m);
  push(v * 2 + 2, m + 1, r);
  st[v] = merge(st[v * 2 + 1], st[v * 2 + 2]);
}
void build(int v, int l, int r) {
  if (l == r) {
    st[v] = make_pair(0, 1);
    return;
  }
  int m = (l + r) >> 1;
  build(v * 2 + 1, l, m);
  build(v * 2 + 2, m + 1, r);
  st[v] = merge(st[v * 2 + 1], st[v * 2 + 2]);
}
pair<int, int> get(int v, int l, int r, int L, int R) {
  push(v, l, r);
  if (l == L && r == R) return st[v];
  int m = (l + r) >> 1;
  if (R <= m) return get(v * 2 + 1, l, m, L, R);
  if (L > m) return get(v * 2 + 2, m + 1, r, L, R);
  if (L <= m && R > m)
    return merge(get(v * 2 + 1, l, m, L, m),
                 get(v * 2 + 2, m + 1, r, m + 1, R));
}
int ans[N];
void dfs2(int v) {
  for (int i = 0; i < int(q[v].size()); ++i) {
    int u = q[v][i];
    update(0, 0, T - 1, l[v], r[v], +1);
    update(0, 0, T - 1, l[u], r[u], +1);
  }
  pair<int, int> p = get(0, 0, T - 1, 0, T - 1);
  int c = T;
  if (p.first == 0) c -= p.second;
  ans[v] = max(c - 1, 0);
  for (int i = 0; i < int(g[v].size()); ++i) {
    int to = g[v][i];
    if (l[v] < l[to]) dfs2(to);
  }
  for (int i = 0; i < int(q[v].size()); ++i) {
    int u = q[v][i];
    update(0, 0, T - 1, l[v], r[v], -1);
    update(0, 0, T - 1, l[u], r[u], -1);
  }
}
void solve() {
  memset(l, -1, sizeof(l));
  dfs(0);
  build(0, 0, T - 1);
  dfs2(0);
  for (int i = 0; i < int(n); ++i) cout << ans[i] << " ";
}
int main() {
  while (read()) solve();
  return 0;
}
