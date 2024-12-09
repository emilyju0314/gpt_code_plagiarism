#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
const long long kInf = 1e18 + 10;
int n, q;
long long a[kN], b[kN];
vector<int> g[kN];
int in[kN], out[kN], dfs_clock;
pair<long long, long long> p1[kN], p2[kN];
void dfs(int u) {
  in[u] = ++dfs_clock;
  for (int v : g[u]) {
    a[v] += a[u], b[v] += b[u];
    dfs(v);
  }
  out[u] = dfs_clock;
}
struct SegmentTree {
  pair<long long, long long> pos[kN << 2];
  struct Node {
    long long a, b;
    long long wait, tg;
  };
  Node seg[kN << 2];
  void init(pair<long long, long long> *a) {
    for (int i = 1; i <= n; i++) pos[i] = a[i];
  }
  void push_down(int o) {
    if (seg[o].tg == 0) return;
    seg[(o << 1)].tg += seg[o].tg, seg[(o << 1 | 1)].tg += seg[o].tg;
    seg[(o << 1)].wait -= seg[o].tg, seg[(o << 1 | 1)].wait -= seg[o].tg;
    seg[(o << 1)].a += seg[o].tg, seg[(o << 1 | 1)].a += seg[o].tg;
    seg[o].tg = 0;
  }
  void push_up(int o) {
    long long a1 = seg[(o << 1)].a, b1 = seg[(o << 1)].b;
    long long a2 = seg[(o << 1 | 1)].a, b2 = seg[(o << 1 | 1)].b;
    if (a1 * b1 > a2 * b2)
      seg[o].a = a1, seg[o].b = b1;
    else
      seg[o].a = a2, seg[o].b = b2;
    seg[o].wait = min(seg[(o << 1)].wait, seg[(o << 1 | 1)].wait);
    if (b1 != b2) {
      long long tmp = (a2 * b2 - a1 * b1) / (b1 - b2);
      if (tmp >= 0) seg[o].wait = min(seg[o].wait, tmp);
    }
  }
  void build(int l = 1, int r = n, int o = 1) {
    if (l == r) {
      seg[o] = {pos[l].first, pos[l].second, kInf, 0};
      return;
    }
    int m = (l + r) >> 1;
    build(l, m, (o << 1)), build(m + 1, r, (o << 1 | 1));
    push_up(o);
  }
  void update(int ql, int qr, int x, int l = 1, int r = n, int o = 1) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr && seg[o].wait >= x) {
      seg[o].tg += x, seg[o].wait -= x, seg[o].a += x;
      return;
    }
    push_down(o);
    int m = (l + r) >> 1;
    if (ql <= m) update(ql, qr, x, l, m, (o << 1));
    if (qr > m) update(ql, qr, x, m + 1, r, (o << 1 | 1));
    push_up(o);
  }
  long long query(int ql, int qr, int l = 1, int r = n, int o = 1) {
    if (ql > r || qr < l) return -kInf;
    if (ql <= l && r <= qr) return seg[o].a * seg[o].b;
    push_down(o);
    int m = (l + r) >> 1;
    return max(query(ql, qr, l, m, (o << 1)),
               query(ql, qr, m + 1, r, (o << 1 | 1)));
  }
};
SegmentTree t1, t2;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2, x; i <= n; i++) {
    scanf("%d", &x);
    g[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 1; i <= n; i++) scanf("%lld", b + i);
  dfs(1);
  for (int i = 1; i <= n; i++) {
    p1[in[i]] = {a[i], b[i]}, p2[in[i]] = {a[i], -b[i]};
  }
  t1.init(p1), t2.init(p2);
  t1.build(), t2.build();
  while (q--) {
    int op, v;
    scanf("%d%d", &op, &v);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      t1.update(in[v], out[v], x);
      t2.update(in[v], out[v], x);
    } else {
      printf("%lld\n", max(t1.query(in[v], out[v]), t2.query(in[v], out[v])));
    }
  }
  return 0;
}
