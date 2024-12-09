#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int dep[N];
struct Node {
  int x, t, id;
  Node() {}
  void input() { scanf("%d%d", &x, &t); }
  bool operator<(const Node &a) const {
    if (t + dep[x] == a.t + dep[a.x]) return x < a.x;
    return t + dep[x] < a.t + dep[a.x];
  }
} Q[N];
int n, m, tot;
int son[N], fa[N], top[N], mark[N], size[N], id[N];
int M[N << 2], lazy[N << 2], ans[N];
vector<int> E[N];
void dfs1(int x, int f) {
  size[x] = 1;
  fa[x] = f;
  dep[x] = dep[f] + 1;
  int m = n + 1;
  for (int &i : E[x]) {
    dfs1(i, x);
    size[x] += size[i];
    if (size[i] > size[m]) m = i;
  }
  son[x] = m;
}
void dfs2(int x, int f) {
  if (son[x] != n + 1) {
    tot++;
    top[son[x]] = top[x];
    mark[son[x]] = tot;
    dfs2(son[x], x);
  }
  for (int &i : E[x]) {
    if (i != son[x]) {
      tot++;
      top[i] = i;
      mark[i] = tot;
      dfs2(i, x);
    }
  }
}
void build(int k, int l, int r) {
  lazy[k] = M[k] = 0;
  if (l == 1) M[k] = 2e9;
  if (l == r) return;
  int mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  M[k] = max(M[k << 1], M[k << 1 | 1]);
}
inline void pushdown(int &k, int &l, int &r) {
  if (!lazy[k]) return;
  M[k << 1 | 1] = lazy[k << 1 | 1] = lazy[k];
  int mid = l + r >> 1;
  M[k << 1] = lazy[k << 1] = lazy[k] - 2 * (r - mid);
  lazy[k] = 0;
}
int Query(int k, int l, int r, int p, int q) {
  if (l != r) pushdown(k, l, r);
  if (l > q || r < p) return 0;
  if (l >= p && r <= q) return M[k];
  int mid = l + r >> 1;
  return max(Query(k << 1, l, mid, p, q), Query(k << 1 | 1, mid + 1, r, p, q));
}
int Query(int k, int l, int r, int p, int q, int c) {
  if (l != r) pushdown(k, l, r);
  if (l > q || r < p) return -1;
  if (M[k] <= c) return -1;
  if (l == r) return id[l];
  int mid = l + r >> 1;
  int res = Query(k << 1 | 1, mid + 1, r, p, q, c);
  if (res != -1) return res;
  return Query(k << 1, l, mid, p, q, c);
}
void modify(int k, int l, int r, int p, int q, int c) {
  if (l != r) pushdown(k, l, r);
  if (l > q || r < p) return;
  if (l >= p && r <= q) {
    c -= 2 * (q - r);
    M[k] = lazy[k] = c;
    return;
  }
  int mid = l + r >> 1;
  modify(k << 1, l, mid, p, q, c);
  modify(k << 1 | 1, mid + 1, r, p, q, c);
  M[k] = max(M[k << 1], M[k << 1 | 1]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    E[x].push_back(i);
  }
  dfs1(0, 0);
  top[0] = 0;
  tot = 1;
  mark[0] = 1;
  dfs2(0, 0);
  for (int i = 0; i <= n; i++) id[mark[i]] = i;
  build(1, 1, ++n);
  for (int i = 1; i <= m; i++) {
    Q[i].input();
    Q[i].id = i;
  }
  sort(Q + 1, Q + 1 + m);
  for (int i = 1; i <= m; i++) {
    int x = Q[i].x, t = Q[i].t, tmp, u;
    while (1) {
      tmp = Query(1, 1, n, mark[top[x]], mark[x]);
      if (tmp > dep[Q[i].x] + t) {
        u = Query(1, 1, n, mark[top[x]], mark[x], dep[Q[i].x] + t);
        break;
      }
      x = fa[top[x]];
    }
    ans[Q[i].id] = t + 2 * (dep[Q[i].x] - dep[u]);
    x = Q[i].x;
    while (1) {
      tmp = Query(1, 1, n, mark[top[x]], mark[x]);
      if (tmp > dep[Q[i].x] + t) {
        u = Query(1, 1, n, mark[top[x]], mark[x], dep[Q[i].x] + t);
        if (u != x)
          modify(1, 1, n, mark[u] + 1, mark[x],
                 ans[Q[i].id] - (dep[Q[i].x] - dep[x]) + dep[x]);
        break;
      } else {
        modify(1, 1, n, mark[top[x]], mark[x],
               ans[Q[i].id] - (dep[Q[i].x] - dep[x]) + dep[x]);
      }
      x = fa[top[x]];
    }
  }
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
}
