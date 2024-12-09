#include <bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int n, m, q;
char L[100010], R[100010], U[100010], D[100010];
struct seg {
  int c;
  struct node {
    array<int, 4> f, rf;
    int lcnt, rcnt, tag;
    void init(int a, int b) {
      f = {a + b, inf, inf, !a + !b};
      rf = {a + !b, inf, inf, !a + b};
      lcnt = a, rcnt = b;
    }
  } tr[400010];
  node merge(node &a, node &b) {
    node res;
    res.lcnt = a.lcnt + b.lcnt, res.rcnt = a.rcnt + b.rcnt, res.tag = 0;
    for (int l = 0; l < 2; l++)
      for (int r = 0; r < 2; r++) {
        int &nf = res.f[l << 1 | r], &nrf = res.rf[l << 1 | r];
        nf = nrf = inf;
        for (int i = 0; i < 2; i++)
          for (int j = 0; j < 2; j++) {
            nf = min(nf, a.f[l << 1 | i] + b.f[j << 1 | r] + (i != j) * c);
            nrf = min(nrf, a.rf[l << 1 | i] + b.rf[j << 1 | r] + (i != j) * c);
          }
      }
    return res;
  }
  void build(int l, int r, int t, char *L, char *R) {
    if (l == r) return tr[t].init(L[l] == 'R', R[r] == 'R');
    int mid = (l + r) >> 1;
    build(l, mid, t << 1, L, R);
    build(mid + 1, r, t << 1 | 1, L, R);
    tr[t] = merge(tr[t << 1], tr[t << 1 | 1]);
  }
  void rev(int l, int r, int t, int c) {
    tr[t].tag ^= c;
    if (c & 2) tr[t].lcnt = r - l + 1 - tr[t].lcnt;
    if (c & 1) tr[t].rcnt = r - l + 1 - tr[t].rcnt;
    if (c ^ 3) tr[t].f.swap(tr[t].rf);
    if (c & 2)
      reverse(tr[t].f.begin(), tr[t].f.end()),
          reverse(tr[t].rf.begin(), tr[t].rf.end());
  }
  void pushdown(int l, int r, int t) {
    int mid = (l + r) >> 1;
    rev(l, mid, t << 1, tr[t].tag), rev(mid + 1, r, t << 1 | 1, tr[t].tag);
    tr[t].tag = 0;
  }
  void rev(int ll, int rr, int l, int r, int t, int c) {
    if (ll <= l && r <= rr) return rev(l, r, t, c);
    int mid = (l + r) >> 1;
    if (tr[t].tag) pushdown(l, r, t);
    if (ll <= mid) rev(ll, rr, l, mid, t << 1, c);
    if (mid < rr) rev(ll, rr, mid + 1, r, t << 1 | 1, c);
    tr[t] = merge(tr[t << 1], tr[t << 1 | 1]);
  }
} H, W;
int qry() {
  seg::node &h = H.tr[1], &w = W.tr[1];
  int res = inf;
  for (int l = 0; l < 2; l++)
    for (int r = 0; r < 2; r++) {
      res = min(res, h.f[l << 1 | r] + (l ? m - w.lcnt : w.lcnt) +
                         (r ? m - w.rcnt : w.rcnt));
      res = min(res, w.f[l << 1 | r] + (l ? n - h.lcnt : h.lcnt) +
                         (r ? n - h.rcnt : h.rcnt));
    }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  scanf("%s%s%s%s", L + 1, R + 1, U + 1, D + 1);
  H.c = m, H.build(1, n, 1, L, R), W.c = n, W.build(1, m, 1, U, D);
  printf("%d\n", qry());
  while (q--) {
    char op;
    int l, r;
    scanf(" %c%d%d", &op, &l, &r);
    if (op == 'L') H.rev(l, r, 1, n, 1, 2);
    if (op == 'R') H.rev(l, r, 1, n, 1, 1);
    if (op == 'U') W.rev(l, r, 1, m, 1, 2);
    if (op == 'D') W.rev(l, r, 1, m, 1, 1);
    printf("%d\n", qry());
  }
}
