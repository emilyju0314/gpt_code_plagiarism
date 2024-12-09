#include <bits/stdc++.h>
using namespace std;
struct timer {
  time_t start;
  timer() { start = clock(); }
  ~timer() {
    cerr << 1. * (clock() - start) / CLOCKS_PER_SEC << " secs" << endl;
  }
};
int N, X[100010], cx[100010], n, x[200010];
int m, t[100010], q1[100010], q2[100010];
int init[200010];
int inf = 2 * 1070000000LL;
struct data {
  long long num, lx, rx;
  long long L, R, S;
  data() {}
  data(long long num, long long lx, long long rx, long long L, long long R,
       long long S)
      : num(num), lx(lx), rx(rx), L(L), R(R), S(S) {}
};
struct segtree {
  int l, r, mid;
  segtree *cl, *cr;
  data d;
  segtree(int l, int r) : l(l), r(r) {
    mid = l + r >> 1;
    if (l + 1 == r) {
      d.num = init[l];
      if (d.num == 1)
        d.lx = d.rx = x[l];
      else
        d.lx = inf, d.rx = -inf;
      d.L = d.R = d.S = 0;
      return;
    }
    cl = new segtree(l, mid);
    cr = new segtree(mid, r);
    d = merge(cl->d, cr->d);
  }
  void change(int pos, int val) {
    if (pos < l || r <= pos) return;
    if (l + 1 == r) {
      d.num = val;
      if (val == 1)
        d.lx = d.rx = x[l];
      else
        d.lx = inf, d.rx = -inf;
      return;
    }
    cl->change(pos, val);
    cr->change(pos, val);
    d = merge(cl->d, cr->d);
  }
  data query(int L, int R) {
    if (L <= l && r <= R) return d;
    if (R <= l || r <= L) return data(0, inf, -inf, 0, 0, 0);
    return merge(cl->query(L, R), cr->query(L, R));
  }
  data merge(const data& a, const data& b) {
    data res;
    res.num = a.num + b.num;
    res.lx = min(a.lx, b.lx);
    res.rx = max(a.rx, b.rx);
    if (a.num == 0)
      res.L = b.L;
    else if (b.num == 0)
      res.L = a.L;
    else
      res.L = a.L + b.L + (b.lx - a.lx) * b.num;
    if (a.num == 0)
      res.R = b.R;
    else if (b.num == 0)
      res.R = a.R;
    else
      res.R = a.R + b.R + (b.rx - a.rx) * a.num;
    if (a.num == 0)
      res.S = b.S;
    else if (b.num == 0)
      res.S = a.S;
    else
      res.S =
          a.S + b.S + a.R * b.num + b.L * a.num + (b.lx - a.rx) * a.num * b.num;
    return res;
  }
} * root;
int main() {
  cin >> N;
  for (int i = 0; i < (N); i++) {
    cin >> X[i];
    cx[i] = x[i] = X[i];
  }
  cin >> m;
  for (int i = 0; i < (m); i++) {
    cin >> t[i] >> q1[i] >> q2[i];
  }
  n = N;
  for (int i = 0; i < (m); i++)
    if (t[i] == 1) {
      cx[q1[i] - 1] += q2[i];
      x[n++] = cx[q1[i] - 1];
    }
  sort(x, x + n);
  n = unique(x, x + n) - x;
  for (int i = 0; i < (N); i++) {
    init[lower_bound(x, x + n, X[i]) - x] = 1;
  }
  root = new segtree(0, n);
  for (int i = 0; i < (N); i++) cx[i] = X[i];
  for (int i = 0; i < (m); i++) {
    if (t[i] == 1) {
      root->change(lower_bound(x, x + n, cx[q1[i] - 1]) - x, 0);
      cx[q1[i] - 1] += q2[i];
      root->change(lower_bound(x, x + n, cx[q1[i] - 1]) - x, 1);
    } else {
      cout << root->query(lower_bound(x, x + n, q1[i]) - x,
                          upper_bound(x, x + n, q2[i]) - x)
                  .S
           << endl;
    }
  }
}
