#include <bits/stdc++.h>
using namespace std;
const int N = 400005, K = 23, M = 9000005;
vector<int> v[N];
int read() {
  char ch = getchar();
  int f = 0, x = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    f = (f << 1) + (f << 3) + ch - '0';
    ch = getchar();
  }
  return f * x;
}
struct data {
  int x, y, z;
} e[N];
struct node {
  int from, to, next;
} edge[400005];
int tot, head[400005], dfn, cnt;
void add(int u, int v) {
  edge[tot].from = u;
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void ad(int x, int y) { v[x].push_back(y); }
int p[N], fa[N][K], top[N], n, m, Q, T[N];
int val[M], l[M], r[M];
int size[N], d[N], son[N], f[N], st[N], q[N], en[N];
bool cmp(const data &x, const data &y) { return d[x.z] < d[y.z]; }
void dfs(int x) {
  size[x] = 1;
  d[x] = d[f[x]] + 1;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    if (edge[i].to != f[x]) {
      f[edge[i].to] = x;
      dfs(edge[i].to);
      size[x] += size[edge[i].to];
      if (size[edge[i].to] > size[son[x]]) son[x] = edge[i].to;
    }
  }
}
void dfs2(int x, int y) {
  q[st[x] = ++dfn] = x;
  top[x] = y;
  if (son[x]) dfs2(son[x], y);
  for (int i = head[x]; i != -1; i = edge[i].next) {
    if (edge[i].to != son[x] && edge[i].to != f[x])
      dfs2(edge[i].to, edge[i].to);
  }
  en[x] = dfn;
}
int lca(int x, int y) {
  for (; top[x] != top[y]; x = f[top[x]])
    if (d[top[x]] < d[top[y]]) swap(x, y);
  return d[x] < d[y] ? x : y;
}
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void col(int x, int y) {
  for (x = find(x); d[x] >= d[y]; x = find(x)) fa[x][0] = y, p[x] = f[x];
}
void dfs3(int x) {
  for (int i = 1; i < K; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = head[x]; i != -1; i = edge[i].next)
    if (edge[i].to != f[x]) dfs3(edge[i].to);
}
int ask(int x, int a, int b, int c, int d) {
  if (c <= a && b <= d) return val[x];
  int mid = a + b >> 1, t = 0;
  if (c <= mid) t = ask(l[x], a, mid, c, d);
  if (d > mid) t += ask(r[x], mid + 1, b, c, d);
  return t;
}
int ins(int x, int a, int b, int c) {
  int y = ++cnt;
  val[y] = val[x] + 1;
  if (a == b) return y;
  int mid = a + b >> 1;
  if (c <= mid)
    l[y] = ins(l[x], a, mid, c), r[y] = r[x];
  else
    l[y] = l[x], r[y] = ins(r[x], mid + 1, b, c);
  return y;
}
int up(int x, int k) {
  while (1) {
    int t = st[x] - st[top[x]];
    if (k <= t) return q[st[x] - k];
    k -= t + 1;
    x = f[top[x]];
  }
}
int go(int x, int y) {
  if (x == y) return 0;
  if (d[fa[x][K - 1]] > d[y]) return -1;
  int t = 1;
  for (int i = K - 1; ~i; i--) {
    if (d[fa[x][i]] > d[y]) x = fa[x][i], t += 1 << i;
  }
  return t;
}
bool check(int x, int y) {
  return ask(T[en[x]], 1, n, st[y], en[y]) >
         ask(T[st[x] - 1], 1, n, st[y], en[y]);
}
int query(int x, int y) {
  if (st[x] <= st[y] && en[y] <= en[x]) return go(y, x);
  if (st[y] <= st[x] && en[x] <= en[y]) return go(x, y);
  int z = lca(x, y), t = 0;
  if (d[fa[x][K - 1]] > d[z]) return -1;
  for (int i = K - 1; ~i; i--)
    if (d[fa[x][i]] > d[z]) x = fa[x][i], t += 1 << i;
  int l = 0, r = d[y] - d[z] - 1, mid, o = d[y] - d[z];
  while (l <= r)
    if (check(x, up(y, mid = l + r >> 1)))
      r = (o = mid) - 1;
    else
      l = mid + 1;
  o = go(y, up(y, o));
  if (o < 0) return -1;
  return t + o + 1;
}
int main() {
  memset(head, -1, sizeof(head));
  n = read();
  for (int i = 2; i <= n; i++) {
    int x = read();
    add(x, i);
    add(i, x);
  }
  m = read();
  dfs(1);
  dfs2(1, 1);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    x = e[i].x = read();
    y = e[i].y = read();
    z = e[i].z = lca(e[i].x, e[i].y);
    if (x == y) continue;
    ad(st[x], st[y]);
    ad(st[y], st[x]);
  }
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= n; i++) p[i] = fa[i][0] = i;
  for (int i = 1; i <= m; i++) col(e[i].x, e[i].z), col(e[i].y, e[i].z);
  dfs3(1);
  for (int i = 1; i <= n; i++) {
    T[i] = T[i - 1];
    for (int j = 0; j < v[i].size(); j++) {
      T[i] = ins(T[i], 1, n, v[i][j]);
    }
  }
  Q = read();
  while (Q--) {
    int x = read(), y = read();
    int z = query(x, y);
    printf("%d\n", z);
  }
}
