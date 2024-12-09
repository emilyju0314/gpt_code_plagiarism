#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5, mod = 1e9 + 7;
long long n, m, tot, head[N], fa[N], siz[N], son[N], dep[N], dfn[N], tim,
    top[N];
struct node {
  long long to, nex;
} e[N];
struct tree {
  long long l, r, tag, val;
} tr[N << 2];
void add(long long x, long long y) {
  e[++tot] = (node){y, head[x]};
  head[x] = tot;
}
void dfs(long long x, long long f) {
  dep[x] = dep[f] + 1;
  siz[x] = 1;
  fa[x] = f;
  long long k;
  for (long long i = head[x]; i; i = e[i].nex) {
    k = e[i].to;
    dfs(k, x);
    siz[x] += siz[k];
    if (siz[son[x]] < siz[k]) son[x] = k;
  }
}
void dfs2(long long x, long long f) {
  dfn[x] = ++tim;
  top[x] = f;
  if (!son[x]) return;
  dfs2(son[x], f);
  long long k;
  for (long long i = head[x]; i; i = e[i].nex) {
    k = e[i].to;
    if (k == son[x]) continue;
    dfs2(k, k);
  }
}
void build(long long k, long long l, long long r) {
  tr[k].l = l;
  tr[k].r = r;
  if (l == r) return;
  long long mid = (l + r) / 2;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void update(long long k) {
  if (!tr[k].tag) return;
  tr[k << 1].val =
      (tr[k << 1].val + tr[k].tag * (tr[k << 1].r - tr[k << 1].l + 1) % mod) %
      mod;
  tr[k << 1 | 1].val =
      (tr[k << 1 | 1].val +
       tr[k].tag * (tr[k << 1 | 1].r - tr[k << 1 | 1].l + 1) % mod) %
      mod;
  tr[k << 1].tag = (tr[k << 1].tag + tr[k].tag) % mod;
  tr[k << 1 | 1].tag = (tr[k << 1 | 1].tag + tr[k].tag) % mod;
  tr[k].tag = 0;
}
void change(long long k, long long st, long long ed, long long v) {
  if (tr[k].l > ed || tr[k].r < st) return;
  if (tr[k].l >= st && tr[k].r <= ed) {
    tr[k].val = (tr[k].val + v * (tr[k].r - tr[k].l + 1) % mod) % mod;
    tr[k].tag = (tr[k].tag + v) % mod;
    return;
  }
  update(k);
  change(k << 1, st, ed, v);
  change(k << 1 | 1, st, ed, v);
  tr[k].val = (tr[k << 1].val + tr[k << 1 | 1].val) % mod;
}
long long query(long long k, long long st, long long ed) {
  if (tr[k].l > ed || tr[k].r < st) return 0;
  if (tr[k].l >= st && tr[k].r <= ed) return tr[k].val;
  update(k);
  return (query(k << 1, st, ed) + query(k << 1 | 1, st, ed)) % mod;
}
long long Ask(long long x, long long y) {
  long long res = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    res = (res + query(1, dfn[top[x]], dfn[x])) % mod;
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  res = (res + query(1, dfn[x], dfn[y])) % mod;
  return (res % mod + mod) % mod;
}
signed main() {
  scanf("%lld", &n);
  long long u;
  for (long long i = 2; i <= n; i++) {
    scanf("%lld", &u);
    add(u, i);
  }
  dfs(1, 0);
  dfs2(1, 1);
  build(1, 1, n);
  scanf("%lld", &m);
  long long opt, v, w;
  while (m--) {
    scanf("%lld %lld", &opt, &u);
    if (opt == 1) {
      scanf("%lld %lld", &v, &w);
      change(1, dfn[u], dfn[u], v);
      change(1, dfn[u] + 1, dfn[u] + siz[u] - 1, mod - w);
    } else
      printf("%lld\n", Ask(1, u) % mod);
  }
  return 0;
}
