#include <bits/stdc++.h>
using namespace std;
int ch[200010][2], fa[200010], v[200010], s[200010], mx[200010], mn[200010],
    h[100010], nex[100010], to[100010], prt[100010], tmp[100010], p[200010], M,
    rt;
void add(int a, int b) {
  M++;
  to[M] = b;
  nex[M] = h[a];
  h[a] = M;
}
void dfs(int x) {
  M++;
  p[M] = (x << 1) - 1;
  v[(x << 1) - 1] = 1;
  for (int i = h[x]; i; i = nex[i]) {
    prt[to[i]] = x;
    dfs(to[i]);
  }
  M++;
  p[M] = x << 1;
  v[x << 1] = -1;
}
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
void pushup(int x) {
  s[x] = s[ch[x][0]] + s[ch[x][1]] + v[x];
  mx[x] = max(mx[ch[x][0]], s[ch[x][0]] + v[x] + max(mx[ch[x][1]], 0));
  mn[x] = min(mn[ch[x][0]], s[ch[x][0]] + v[x] + min(mn[ch[x][1]], 0));
}
int build(int l, int r) {
  int mid = (l + r) >> 1;
  int& x = p[mid];
  if (l < mid) {
    ch[x][0] = build(l, mid - 1);
    fa[ch[x][0]] = x;
  }
  if (mid < r) {
    ch[x][1] = build(mid + 1, r);
    fa[ch[x][1]] = x;
  }
  pushup(x);
  return x;
}
void rot(int x) {
  int y, z, f, B;
  y = fa[x];
  z = fa[y];
  f = (ch[y][0] == x);
  B = ch[x][f];
  fa[x] = z;
  fa[y] = x;
  if (B) fa[B] = y;
  ch[x][f] = y;
  ch[y][f ^ 1] = B;
  if (ch[z][0] == y) ch[z][0] = x;
  if (ch[z][1] == y) ch[z][1] = x;
  pushup(y);
  pushup(x);
}
void splay(int x, int gl) {
  int y, z;
  while (fa[x] != gl) {
    y = fa[x];
    z = fa[y];
    if (z != gl)
      rot((ch[z][0] == y && ch[y][0] == x) || (ch[z][1] == y && ch[y][1] == x)
              ? y
              : x);
    rot(x);
  }
}
int getdis(int x, int y) {
  x = (x << 1) - 1;
  y = (y << 1) - 1;
  int dx, dy, dl;
  splay(x, 0);
  dx = s[ch[x][0]] + v[x];
  splay(y, 0);
  dy = s[ch[y][0]] + v[y];
  splay(x, 0);
  splay(y, x);
  rt = x;
  dl = min(dx, dy);
  if (ch[x][0] == y)
    dl = min(dl, s[ch[y][0]] + v[y] + mn[ch[y][1]]);
  else
    dl = min(dl, s[ch[x][0]] + v[x] + mn[ch[y][0]]);
  return dx + dy - (dl << 1);
}
int find(int x, int d) {
  if (mx[ch[x][1]] >= d - s[ch[x][0]] - v[x] &&
      mn[ch[x][1]] <= d - s[ch[x][0]] - v[x])
    return find(ch[x][1], d - s[ch[x][0]] - v[x]);
  if (s[ch[x][0]] + v[x] == d) return (x & 1) ? (x + 1) >> 1 : prt[x >> 1];
  return find(ch[x][0], d);
}
int pre(int x) {
  splay(x, 0);
  for (x = ch[x][0]; ch[x][1]; x = ch[x][1])
    ;
  return x;
}
int nx(int x) {
  splay(x, 0);
  for (x = ch[x][1]; ch[x][0]; x = ch[x][0])
    ;
  return x;
}
void change(int u, int h) {
  int x = (u << 1) - 1, L, R, t;
  splay(x, 0);
  prt[u] = find(ch[x][0], s[ch[x][0]] + v[x] - h);
  L = pre(x);
  R = nx(u << 1);
  splay(L, 0);
  splay(R, L);
  t = ch[R][0];
  ch[R][0] = 0;
  pushup(R);
  pushup(L);
  L = pre(prt[u] << 1);
  R = (prt[u] << 1);
  splay(L, 0);
  splay(R, L);
  ch[R][0] = t;
  fa[t] = R;
  pushup(R);
  pushup(L);
  rt = L;
}
int main() {
  mx[0] = -1000000000;
  mn[0] = 1000000000;
  int n, m, i, x, y;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &y);
    for (x = 1; x <= y; x++) scanf("%d", tmp + x);
    for (x = y; x > 0; x--) add(i, tmp[x]);
  }
  M = 0;
  dfs(1);
  rt = build(1, n << 1);
  while (m--) {
    scanf("%d%d", &i, &x);
    if (i != 3) scanf("%d", &y);
    if (i == 1) printf("%d\n", getdis(x, y));
    if (i == 2) change(x, y);
    if (i == 3) printf("%d\n", find(rt, x + 1));
  }
}
