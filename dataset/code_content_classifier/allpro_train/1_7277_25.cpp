#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 200010;
struct edge {
  int v, nxt;
} g[N << 1];
int tot = 0, head[N];
inline void add(int u, int v) {
  g[++tot] = edge{v, head[u]};
  head[u] = tot;
}
int n, q, p[N], fa[N], dfn[N << 2], dep[N], A[N], cnt = 0, bg[N],
                                                  st[20][N << 2];
inline void dfs(int u) {
  dfn[++cnt] = u;
  bg[u] = cnt;
  dep[u] = dep[fa[u]] + 1;
  for (int i = head[u]; i; i = g[i].nxt) {
    int v = g[i].v;
    dfs(v);
    dfn[++cnt] = u;
  }
}
inline void calc() {
  for (int i = 1; i <= cnt; ++i) st[0][i] = dfn[i];
  for (int i = 1; i <= 20; ++i)
    for (int j = 1; j + (1 << i) - 1 <= cnt; ++j)
      st[i][j] = (dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << i - 1)]]
                      ? st[i - 1][j]
                      : st[i - 1][j + (1 << i - 1)]);
}
inline int LCA(int u, int v) {
  int l = bg[u], r = bg[v];
  if (l > r) swap(l, r);
  int k = log2(r - l + 1);
  int a = st[k][l], b = st[k][r - (1 << k) + 1];
  int ans = (dep[a] < dep[b] ? a : b);
  return ans;
}
inline int dis(int u, int v) {
  int lca = LCA(u, v);
  return dep[u] + dep[v] - 2 * dep[lca];
}
int s[N << 2], t[N << 2];
inline void pushup(int o) {
  int a = s[o << 1], b = t[o << 1], c = s[o << 1 | 1], d = t[o << 1 | 1];
  if (a == -1 || b == -1 || c == -1 || d == -1) return (void)(s[o] = t[o] = -1);
  if (dep[b] > dep[a]) a = b;
  if (dep[c] > dep[a]) swap(c, a);
  if (dep[d] > dep[a]) swap(d, a);
  if (dis(b, a) < dis(c, a)) swap(b, c);
  if (dis(b, a) < dis(d, a)) swap(b, d);
  if (dis(a, b) == dis(a, c) + dis(c, b) && dis(a, b) == dis(a, d) + dis(b, d))
    s[o] = a, t[o] = b;
  else
    s[o] = t[o] = -1;
}
inline void build(int o, int l, int r) {
  if (l == r) {
    s[o] = t[o] = A[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  pushup(o);
}
inline void update(int p, int o, int l, int r, int x) {
  if (l == r) return (void)(s[o] = t[o] = x);
  int mid = (l + r) >> 1;
  if (mid >= p)
    update(p, o << 1, l, mid, x);
  else
    update(p, o << 1 | 1, mid + 1, r, x);
  pushup(o);
}
inline pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  int a = x.first, b = x.second, c = y.first, d = y.second;
  if (!a && !b) return make_pair(c, d);
  if (!c && !d) return make_pair(a, b);
  if (a == -1 || b == -1 || c == -1 || d == -1) return make_pair(-1, -1);
  if (dep[b] > dep[a]) a = b;
  if (dep[c] > dep[a]) swap(c, a);
  if (dep[d] > dep[a]) swap(d, a);
  if (dis(b, a) < dis(c, a)) swap(b, c);
  if (dis(b, a) < dis(d, a)) swap(b, d);
  if (dis(a, b) == dis(a, c) + dis(c, b) && dis(a, b) == dis(a, d) + dis(b, d))
    return make_pair(a, b);
  else
    return make_pair(-1, -1);
}
int ans = 0;
inline void query(int o, int l, int r, pair<int, int> a) {
  if (l == r) {
    pair<int, int> x = merge(a, make_pair(s[o], t[o]));
    if (x.first != -1) ans = max(ans, l);
    return;
  }
  int mid = (l + r) >> 1;
  pair<int, int> y = merge(a, make_pair(s[o << 1], t[o << 1]));
  if (y.first != -1)
    query(o << 1 | 1, mid + 1, r, y), ans = max(ans, mid);
  else
    query(o << 1, l, mid, a);
}
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) p[i] = read(), ++p[i], A[p[i]] = i;
  for (int i = 2; i <= n; ++i) fa[i] = read(), add(fa[i], i);
  dfs(1);
  calc();
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int opt, x, y;
    opt = read();
    if (opt == 1) {
      x = read(), y = read();
      update(p[y], 1, 1, n, x);
      update(p[x], 1, 1, n, y);
      swap(p[x], p[y]);
    } else {
      ans = 0;
      query(1, 1, n, make_pair(0, 0));
      printf("%d\n", ans);
    }
  }
  return 0;
}
