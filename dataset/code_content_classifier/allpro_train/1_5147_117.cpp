#include <bits/stdc++.h>
using namespace std;
const int N = 400005, INF = 1e9 + 7;
char buf[1 << 20], *p1, *p2;
inline int _R() {
  int d = 0;
  char t;
  bool ty = 1;
  while (t = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin),
                           p1 == p2)
                  ? 0
                  : *p1++),
         (t < '0' || t > '9') && t != '-')
    ;
  t == '-' ? (ty = 0) : (d = t - '0');
  while (t = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin),
                           p1 == p2)
                  ? 0
                  : *p1++),
         t >= '0' && t <= '9')
    d = (d << 3) + (d << 1) + t - '0';
  return ty ? d : -d;
}
inline void _S(char *c) {
  char *t = c, ch;
  while (ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin),
                            p1 == p2)
                   ? 0
                   : *p1++),
         ch == ' ' || ch == '\r' || ch == '\n')
    ;
  *t++ = ch;
  while (ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin),
                            p1 == p2)
                   ? 0
                   : *p1++),
         ch != ' ' && ch != '\r' && ch != '\n')
    *t++ = ch;
  *t = 0;
}
int n, m, q;
int w[N], b[N];
struct heap {
  priority_queue<int, vector<int>, greater<int> > Q, E;
  void del(const int &x) { E.push(x); }
  void push(const int &x) { Q.push(x); }
  int gmin() {
    while (!Q.empty() && !E.empty() && Q.top() == E.top()) Q.pop(), E.pop();
    return Q.top();
  }
} g[N];
int totn;
int Tote, Last[N], End[N], Next[N];
void ADDE(int x, int y) {
  End[++Tote] = y, Next[Tote] = Last[x], Last[x] = Tote;
  End[++Tote] = x, Next[Tote] = Last[y], Last[y] = Tote;
}
int vtt, fa[N], dfn[N], low[N];
int _Tote, _Last[N], _End[N], _Next[N];
void EDDA(int x, int y) {
  _End[++_Tote] = y, _Next[_Tote] = _Last[x], _Last[x] = _Tote;
  _End[++_Tote] = x, _Next[_Tote] = _Last[y], _Last[y] = _Tote;
}
int s[N], tops;
void tarjan(int x) {
  dfn[x] = low[x] = ++vtt;
  s[++tops] = x;
  for (int i = _Last[x], u; i; i = _Next[i])
    if (u = _End[i], u != fa[x])
      if (!dfn[u]) {
        fa[u] = x;
        tarjan(u);
        low[x] = min(low[x], low[u]);
        if (dfn[x] <= low[u]) {
          ++totn;
          ADDE(x, totn);
          do ADDE(s[tops], totn);
          while (s[tops--] != u);
        }
      } else
        low[x] = min(low[x], dfn[u]);
}
int dep[N], top[N], hson[N];
int dfs_init(int x) {
  int maxx = 0, sz = 1, tmp, i, u;
  dep[x] = dep[fa[x]] + 1;
  for (i = Last[x], u; i; i = Next[i])
    if (u = End[i], u != fa[x])
      if (fa[u] = x, tmp = dfs_init(u), sz += tmp, tmp > maxx)
        maxx = tmp, hson[x] = u;
  return sz;
}
void dfs_make(int x, int tp) {
  dfn[x] = ++vtt;
  top[x] = tp;
  if (fa[x] > n) g[fa[x]].push(w[x]);
  if (hson[x]) dfs_make(hson[x], tp);
  for (int i = Last[x], u; i; i = Next[i])
    if (u = End[i], u != fa[x] && u != hson[x]) dfs_make(u, u);
}
struct Node {
  Node *Son[2];
  int val;
} pool[N << 2], *tl, *root, *null;
void _pushup(Node *p) { p->val = min(p->Son[0]->val, p->Son[1]->val); }
void _build(Node *&p, int l, int r) {
  p = ++tl;
  if (l < r) {
    int mid = l + r >> 1;
    _build(p->Son[0], l, mid);
    _build(p->Son[1], mid + 1, r);
    _pushup(p);
  } else
    p->val = b[l];
}
void _init() {
  null = tl = pool;
  null->Son[0] = null->Son[1] = null;
  _build(root, 1, totn);
}
void _modify(Node *p, int l, int r, int k, int d) {
  if (l == r) {
    p->val = d;
    return;
  }
  int mid = l + r >> 1;
  if (k <= mid)
    _modify(p->Son[0], l, mid, k, d);
  else
    _modify(p->Son[1], mid + 1, r, k, d);
  _pushup(p);
}
int _query(Node *p, int l, int r, int x, int y) {
  if (x <= l && r <= y) return p->val;
  int mid = l + r >> 1, lm = INF, rm = INF;
  if (x <= mid) lm = _query(p->Son[0], l, mid, x, y);
  if (mid < y) rm = _query(p->Son[1], mid + 1, r, x, y);
  return min(lm, rm);
}
int gans(int x, int y) {
  int ret = INF;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ret = min(ret, _query(root, 1, totn, dfn[top[x]], dfn[x]));
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ret = min(ret, _query(root, 1, totn, dfn[x], dfn[y]));
  if (x > n) ret = min(ret, w[fa[x]]);
  return ret;
}
int main() {
  int i, j, k, x, y;
  char opt[3];
  totn = n = _R(), m = _R(), q = _R();
  for (i = 1; i <= n; i++) w[i] = _R();
  for (i = 1; i <= m; i++) {
    x = _R(), y = _R();
    EDDA(x, y);
  }
  tarjan(1);
  vtt = 0;
  dfs_init(1);
  dfs_make(1, 1);
  for (i = 1; i <= n; i++) b[dfn[i]] = w[i];
  for (i = n + 1; i <= totn; i++) b[dfn[i]] = g[i].gmin();
  _init();
  for (i = 1; i <= q; i++) {
    _S(opt), x = _R(), y = _R();
    if (opt[0] == 'A')
      printf("%d\n", gans(x, y));
    else {
      if (fa[x] > n) {
        k = fa[x];
        g[k].del(w[x]);
        g[k].push(y);
        _modify(root, 1, totn, dfn[k], g[k].gmin());
      }
      w[x] = y;
      _modify(root, 1, totn, dfn[x], y);
    }
  }
}
