#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void umin(T &x, T y) {
  if (y < x) x = y;
}
const int N = 2e5 + 5, B = 0x7fffffff;
int in[N], out[N], lvl[N], now[N];
int st[4 * N], ger[N];
int n, m, tim;
vector<int> g[N];
void dfs(int nd, int par) {
  in[nd] = ++tim;
  ger[tim] = now[nd];
  lvl[nd] = lvl[par] + 1;
  for (auto adj : g[nd])
    if (adj != par) dfs(adj, nd);
  out[nd] = tim;
}
void upd(int l, int r, int id, int ql, int qr, int x) {
  if (r < ql || l > qr) return;
  if (l >= ql && r <= qr) {
    st[id] += x;
    return;
  }
  int mid = (l + r) >> 1;
  upd(l, mid, id << 1, ql, qr, x);
  upd(mid + 1, r, id << 1 | 1, ql, qr, x);
}
int get(int l, int r, int id, int u) {
  if (l == r) return st[id];
  int mid = (l + r) >> 1;
  if (u <= mid)
    return st[id] + get(l, mid, id << 1, u);
  else
    return st[id] + get(mid + 1, r, id << 1 | 1, u);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &now[i]);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int ty, no, x;
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d%d", &no, &x);
      if (lvl[no] % 2 == 0)
        upd(1, n, 1, in[no], out[no], x);
      else
        upd(1, n, 1, in[no], out[no], -x);
    } else {
      scanf("%d", &no);
      if (lvl[no] % 2 == 0)
        printf("%d\n", ger[in[no]] + get(1, n, 1, in[no]));
      else
        printf("%d\n", ger[in[no]] - get(1, n, 1, in[no]));
    }
  }
  return !1;
}
