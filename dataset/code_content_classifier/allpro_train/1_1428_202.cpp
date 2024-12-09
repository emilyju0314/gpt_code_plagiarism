#include <bits/stdc++.h>
using namespace std;
long double intersect(int k, int b, int kk, int bb) {
  return (long double)(b - bb) / (kk - k);
}
struct ConvexHull {
  int *k, *b;
  int len;
  ConvexHull() : k(0), b(0), len(0) {}
  void addLine(int kk, int bb) {
    if (len == 1 && k[len - 1] == kk) {
      bb = max(b[len - 1], bb);
      len = 0;
    }
    if (len <= 1) {
      k[len] = kk;
      b[len] = bb;
      len++;
      return;
    }
    while (len >= 2 &&
           ((k[len - 1] == kk && b[len - 1] > bb) ||
            (kk != k[len - 1] &&
             intersect(k[len - 2], b[len - 2], k[len - 1], b[len - 1]) >=
                 intersect(k[len - 1], b[len - 1], kk, bb))))
      len--;
    while (len >= 1 && k[len - 1] == kk && b[len - 1] > bb) len--;
    if (len >= 1 && k[len - 1] == kk && b[len - 1] <= bb) return;
    k[len] = kk;
    b[len] = bb;
    len++;
  }
  int get(int idx, int x) { return k[idx] * x + b[idx]; }
  bool f(int idx, int x) { return get(idx, x) >= get(idx + 1, x); }
  int getMin(int x) {
    int l = -1, r = len - 1;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (f(mid, x))
        l = mid;
      else
        r = mid;
    }
    return get(r, x);
  }
};
const int maxn = 100500;
int n, q, a[maxn], s[maxn];
ConvexHull t[maxn * 4];
void mergeCHs(ConvexHull& res, ConvexHull& a, ConvexHull& b) {
  res.len = 0;
  res.k = new int[a.len + b.len];
  res.b = new int[a.len + b.len];
  int l = 0, r = 0;
  while (l + r != a.len + b.len)
    if (l == a.len) {
      res.addLine(b.k[r], b.b[r]);
      r++;
    } else if (r == b.len) {
      res.addLine(a.k[l], a.b[l]);
      l++;
    } else if (a.k[l] > b.k[r]) {
      res.addLine(a.k[l], a.b[l]);
      l++;
    } else {
      res.addLine(b.k[r], b.b[r]);
      r++;
    }
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v].k = new int[1];
    t[v].b = new int[1];
    t[v].k[0] = a[tl];
    t[v].b[0] = a[tl] * tl - s[tl];
    t[v].len = 1;
    return;
  }
  int tm = (tl + tr) >> 1;
  build((v << 1) + 1, tl, tm);
  build((v << 1) + 2, tm + 1, tr);
  mergeCHs(t[v], t[(v << 1) + 1], t[(v << 1) + 2]);
}
int treeQuery(int v, int tl, int tr, int l, int r, int x) {
  if (tl == l && tr == r) {
    return t[v].getMin(x);
  }
  int tm = (tl + tr) >> 1;
  if (r <= tm)
    return treeQuery((v << 1) + 1, tl, tm, l, r, x);
  else if (l > tm)
    return treeQuery((v << 1) + 2, tm + 1, tr, l, r, x);
  else
    return min(treeQuery((v << 1) + 1, tl, tm, l, tm, x),
               treeQuery((v << 1) + 2, tm + 1, tr, tm + 1, r, x));
}
int query(int x, int y) {
  int l = y - x + 1;
  int r = y;
  return treeQuery(0, 1, n, l, r, x - y) + s[y];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  build(0, 1, n);
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << query(x, y) << endl;
  }
  return 0;
}
