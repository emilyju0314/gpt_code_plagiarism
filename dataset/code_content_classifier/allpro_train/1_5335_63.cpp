#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int inf = 1e9 + 8;
int a[maxn], b[maxn];
inline pair<int, int> mergep(pair<int, int> l, pair<int, int> r) {
  if (a[l.first] + b[l.second] < a[r.first] + b[r.second])
    return l;
  else
    return r;
}
struct dat {
  pair<int, int> p1, p2, p3;
  int ma, mb, a1, b1, fw;
};
inline dat merged(dat l, dat r) {
  dat res;
  if (a[l.ma] < a[r.ma])
    res.ma = l.ma;
  else
    res.ma = r.ma;
  if (b[l.mb] < b[r.mb])
    res.mb = l.mb;
  else
    res.mb = r.mb;
  res.p1 = mergep(make_pair(l.ma, r.mb), mergep(l.p1, r.p1));
  res.p2 = mergep(make_pair(r.ma, l.mb), mergep(l.p2, r.p2));
  res.fw = min(l.fw, r.fw);
  if (l.fw < r.fw) {
    res.p3 = mergep(mergep(make_pair(r.ma, l.b1), r.p2), mergep(l.p3, r.p3));
    res.a1 = l.a1;
    if (b[r.mb] < b[l.b1])
      res.b1 = r.mb;
    else
      res.b1 = l.b1;
  } else if (l.fw > r.fw) {
    res.p3 = mergep(mergep(make_pair(r.a1, l.mb), l.p2), mergep(l.p3, r.p3));
    res.b1 = r.b1;
    if (a[l.ma] < a[r.a1])
      res.a1 = l.ma;
    else
      res.a1 = r.a1;
  } else {
    res.p3 = mergep(make_pair(r.a1, l.b1), mergep(l.p3, r.p3));
    res.b1 = r.b1;
    res.a1 = l.a1;
  }
  return res;
}
struct node {
  dat cur;
  int tag;
};
node t1[maxn * 4];
inline int lc(int u) { return u << 1; }
inline int rc(int u) { return u << 1 | 1; }
inline void co(int u) { t1[u].cur = merged(t1[lc(u)].cur, t1[rc(u)].cur); }
inline void givet(int u, int x) {
  t1[u].cur.fw += x;
  t1[u].tag += x;
  return;
}
inline void pushdown(int u) {
  if (t1[u].tag == 0) return;
  givet(lc(u), t1[u].tag);
  givet(rc(u), t1[u].tag);
  t1[u].tag = 0;
  return;
}
inline void add(int u, int l, int r, int ql, int qr, int d) {
  if (ql <= l && r <= qr) {
    givet(u, d);
    return;
  }
  int mid = (l + r) / 2;
  pushdown(u);
  if (ql <= mid) add(lc(u), l, mid, ql, qr, d);
  if (mid + 1 <= qr) add(rc(u), mid + 1, r, ql, qr, d);
  co(u);
  return;
}
inline void upd(int u, int l, int r, int id) {
  if (l == r) {
    return;
  }
  pushdown(u);
  int mid = (l + r) / 2;
  if (id <= mid)
    upd(lc(u), l, mid, id);
  else
    upd(rc(u), mid + 1, r, id);
  co(u);
  return;
}
inline void build(int u, int l, int r) {
  if (l == r) {
    t1[u].cur.ma = t1[u].cur.mb = t1[u].cur.a1 = l;
    t1[u].cur.p1 = t1[u].cur.p2 = make_pair(l, l);
    return;
  }
  int mid = (l + r) / 2;
  build(lc(u), l, mid);
  build(rc(u), mid + 1, r);
  co(u);
  return;
}
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  a[0] = b[0] = inf;
  build(1, 1, n);
  long long ans = 0;
  while (k--) {
    pair<int, int> pt = mergep(t1[1].cur.p3, t1[1].cur.p1);
    ans += a[pt.first] + b[pt.second];
    if (pt.first < pt.second) add(1, 1, n, pt.first, pt.second - 1, 1);
    if (pt.first > pt.second) add(1, 1, n, pt.second, pt.first - 1, -1);
    a[pt.first] = b[pt.second] = inf;
    upd(1, 1, n, pt.first);
    upd(1, 1, n, pt.second);
  }
  cout << ans << endl;
}
