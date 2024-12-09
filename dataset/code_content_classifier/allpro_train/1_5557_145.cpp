#include <bits/stdc++.h>
using namespace std;
const int __ = 2e5 + 5;
struct node {
  int l, r;
} a[__];
double b[__ << 2];
struct SegmentTree {
  int n, ql, qr, val;
  struct node {
    int v, c;
    bool lv, rv;
    void putadd(int val) { c += val; }
  } t[__ << 5];
  void pushup(int x) {
    if (t[x].c) {
      t[x] = {1, t[x].c, true, true};
      return;
    }
    t[x].v = t[x << 1].v + t[x << 1 | 1].v;
    if (t[x << 1].rv && t[x << 1 | 1].lv) --t[x].v;
    t[x].lv = t[x << 1].lv;
    t[x].rv = t[x << 1 | 1].rv;
  }
  void build(int _n) {
    n = _n;
    build(1, 1, n);
  }
  void build(int x, int tl, int tr) {
    t[x] = {0, 0, false, false};
    t[x << 1] = {0, 0, false, false};
    t[x << 1 | 1] = {0, 0, false, false};
    if (tl == tr) return;
    int tm = (tl + tr) >> 1;
    build(x << 1, tl, tm);
    build(x << 1 | 1, tm + 1, tr);
    pushup(x);
  }
  void add(int _ql, int _qr, int v) {
    ql = _ql, qr = _qr, val = v;
    _add(1, 1, n);
  }
  void _add(int x, int tl, int tr) {
    if (ql > tr || qr < tl) return;
    if (ql <= tl && tr <= qr) {
      t[x].putadd(val);
      pushup(x);
      return;
    }
    int tm = (tl + tr) >> 1;
    _add(x << 1, tl, tm);
    _add(x << 1 | 1, tm + 1, tr);
    pushup(x);
  }
  int get() { return t[1].v; }
} T;
int main() {
  int _;
  for (scanf("%d", &_); _; --_) {
    int n, m = 0;
    scanf("%d", &n);
    for (int i = (1); i <= (n); ++i) {
      scanf("%d%d", &a[i].l, &a[i].r);
      b[++m] = a[i].l - 0.3;
      b[++m] = a[i].l;
      b[++m] = a[i].r;
      b[++m] = a[i].r + 0.3;
    }
    sort(b + 1, b + 1 + m);
    m = unique(b + 1, b + 1 + m) - b - 1;
    T.build(m);
    for (int i = 1; i <= n; ++i) {
      a[i].l = lower_bound(b + 1, b + 1 + m, a[i].l) - b;
      a[i].r = lower_bound(b + 1, b + 1 + m, a[i].r) - b;
      T.add(a[i].l, a[i].r, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      T.add(a[i].l, a[i].r, -1);
      ans = max(ans, T.get());
      T.add(a[i].l, a[i].r, 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
