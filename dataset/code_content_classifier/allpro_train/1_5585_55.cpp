#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 7;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
int f[N], es[N], et[N], ew[N];
vector<int> g[N], num[N];
int hv[N], h[N], hed[N], pe[N], adr[N], n, m, par[N];
inline int build_dfs(int x, int pr = -1, int ep = -1) {
  int o = 0, sz = 0;
  h[x] = (pr != -1 ? h[pr] + 1 : 0);
  pe[x] = ep;
  par[x] = pr;
  for (auto e : g[x])
    if ((es[e] ^ et[e] ^ x) != pr) {
      int i = es[e] ^ et[e] ^ x;
      int szi = build_dfs(i, x, e);
      sz += szi;
      if (szi > o) hv[x] = i, o = szi;
    }
  return ++sz;
}
int pos[N];
inline void build_hld() {
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (!i || hv[par[i]] != i) {
      int j = i;
      while (true) {
        if (j) {
          adr[pe[j]] = cnt;
        }
        pos[j] = cnt++, hed[j] = i;
        j = hv[j];
        if (j == -1) break;
      }
    }
}
bool cmp(int x, int y) { return ew[x] > ew[y]; }
int cnt = 1;
struct node {
  int ans, sz, pre, suf;
  node() {
    ans = pre = suf = 0;
    sz = 1;
  }
  node(int _ans, int _sz, int _pre, int _suf) {
    ans = _ans;
    sz = _sz;
    pre = _pre;
    suf = _suf;
  }
} seg[22 * N];
int xl[22 * N], xr[22 * N], root[N], order[N];
bool is[22 * N];
node operator^(node x, node y) {
  return node(x.ans + y.ans - f[x.suf] - f[y.pre] + f[x.suf + y.pre],
              x.sz + y.sz, x.pre + y.pre * (x.sz == x.pre),
              x.suf * (y.sz == y.suf) + y.suf);
}
int make(int tag) {
  xl[cnt] = xl[tag];
  xr[cnt] = xr[tag];
  seg[cnt] = seg[tag];
  return cnt++;
}
node update(int p, int tag, int s = 0, int e = n) {
  int id = make(tag);
  if (e - s == 1) {
    seg[id] = node(f[1], 1, 1, 1);
    return seg[id];
  }
  int mid = (e + s) / 2;
  if (p < mid)
    xl[id] = cnt, seg[id] = update(p, xl[tag], s, mid) ^ seg[xr[tag]];
  else
    xr[id] = cnt, seg[id] = seg[xl[tag]] ^ update(p, xr[tag], mid, e);
  return seg[id];
}
node query(int l, int r, int tag, int s = 0, int e = n) {
  if (s >= r || e <= l) return node(0, 0, 0, 0);
  if (s >= l && e <= r) return seg[tag];
  int mid = (s + e) / 2;
  return query(l, r, xl[tag], s, mid) ^ query(l, r, xr[tag], mid, e);
}
node rev(node x) {
  swap(x.pre, x.suf);
  return x;
}
int get_path(int x, int y, int rut) {
  node l = node(0, 0, 0, 0), r = node(0, 0, 0, 0);
  while (hed[x] != hed[y]) {
    int a = hed[x], b = hed[y];
    if (h[a] > h[b]) {
      l = l ^ rev(query(pos[a], pos[x] + 1, rut));
      x = par[a];
    } else {
      r = query(pos[b], pos[y] + 1, rut) ^ r;
      y = par[b];
    }
  }
  if (h[x] > h[y])
    l = l ^ rev(query(pos[y] + 1, pos[x] + 1, rut));
  else
    r = query(pos[x] + 1, pos[y] + 1, rut) ^ r;
  return (l ^ r).ans;
}
int32_t main() {
  memset(hv, -1, sizeof hv);
  n = in(), m = in();
  for (int i = 1; i <= n - 1; i++) f[i] = in();
  for (int i = 0; i < n - 1; i++) {
    int x = in() - 1, y = in() - 1, w = in();
    es[i] = x;
    et[i] = y;
    ew[i] = w;
    g[x].push_back(i);
    g[y].push_back(i);
    order[i] = i;
  }
  sort(order, order + n - 1, cmp);
  build_dfs(0);
  build_hld();
  vector<int> v;
  for (int i = 0; i < n - 1; i++) {
    int x = order[i];
    root[i + 1] = cnt;
    update(adr[x], root[i]);
  }
  int x, y;
  while (m--) {
    x = in() - 1, y = in() - 1, ew[n] = in();
    printf("%d\n",
           get_path(x, y,
                    root[upper_bound(order, order + n - 1, n, cmp) - order]));
  }
}
