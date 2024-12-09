#include <bits/stdc++.h>
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, q;
int fir[100010], dis[100010], nxt[100010], id;
inline void link(int a, int b) { nxt[++id] = fir[a], fir[a] = id, dis[id] = b; }
struct node {
  int sum, sufmx;
  node(int _sum = -1, int _sufmx = -1) { sum = _sum, sufmx = _sufmx; }
};
inline node operator+(const node& a, const node& b) {
  return (node){a.sum + b.sum, std::max(b.sufmx, b.sum + a.sufmx)};
}
int siz[100010], son[100010], top[100010], fa[100010], dfn[100010];
inline void dfs(int x) {
  siz[x] = 1;
  for (int i = fir[x]; i; i = nxt[i]) {
    fa[dis[i]] = x;
    dfs(dis[i]);
    siz[x] += siz[dis[i]];
    if (siz[son[x]] < siz[dis[i]]) son[x] = dis[i];
  }
}
inline void dfs(int x, int tp) {
  dfn[x] = ++dfn[0];
  top[x] = tp;
  if (son[x]) dfs(son[x], tp);
  for (int i = fir[x]; i; i = nxt[i])
    if (fa[x] != dis[i] && son[x] != dis[i]) dfs(dis[i], dis[i]);
}
node S[400010];
bool LZ[400010];
inline void updc(int x, int l, int r) {
  LZ[x] = 1, S[x] = (node){-(r - l + 1), -1};
}
inline void down(int x, int l, int r) {
  if (LZ[x])
    LZ[x] = 0, updc(x << 1, l, ((l + r) >> 1)),
    updc(x << 1 | 1, ((l + r) >> 1) + 1, r);
}
inline void build(int x, int l, int r) {
  if (l == r) return;
  build(x << 1, l, ((l + r) >> 1)), build(x << 1 | 1, ((l + r) >> 1) + 1, r);
  S[x] = S[x << 1] + S[x << 1 | 1];
}
inline void update_d(int x, int l, int r, const int& p, const int& d) {
  if (l == r) {
    S[x].sum += d, S[x].sufmx += d;
    return;
  }
  down(x, l, r);
  if (p <= ((l + r) >> 1))
    update_d(x << 1, l, ((l + r) >> 1), p, d);
  else
    update_d(x << 1 | 1, ((l + r) >> 1) + 1, r, p, d);
  S[x] = S[x << 1] + S[x << 1 | 1];
}
inline void update_c(int x, int l, int r, const int& L, const int& R) {
  if (L <= l && r <= R) return updc(x, l, r);
  down(x, l, r);
  if (L <= ((l + r) >> 1)) update_c(x << 1, l, ((l + r) >> 1), L, R);
  if (((l + r) >> 1) < R) update_c(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
  S[x] = S[x << 1] + S[x << 1 | 1];
}
inline node query(int x, int l, int r, const int& L, const int& R) {
  if (L <= l && r <= R) return S[x];
  down(x, l, r);
  if (L <= ((l + r) >> 1))
    if (((l + r) >> 1) < R)
      return query(x << 1, l, ((l + r) >> 1), L, R) +
             query(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
    else
      return query(x << 1, l, ((l + r) >> 1), L, R);
  else
    return query(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
}
inline int query(int x) {
  node ret(0, -1e9);
  while (x) {
    ret = query(1, 1, n, dfn[top[x]], dfn[x]) + ret;
    x = fa[top[x]];
  }
  return ret.sufmx;
}
int main() {
  n = gi(), q = gi();
  for (int i = 2; i <= n; ++i) link(gi(), i);
  build(1, 1, n);
  dfs(1), dfs(1, 1);
  int opt, x;
  while (q--) {
    opt = gi(), x = gi();
    if (opt == 1)
      update_d(1, 1, n, dfn[x], 1);
    else if (opt == 2)
      update_c(1, 1, n, dfn[x], dfn[x] + siz[x] - 1),
          update_d(1, 1, n, dfn[x], -1 - query(x));
    else if (query(x) < 0)
      puts("white");
    else
      puts("black");
  }
  return 0;
}
