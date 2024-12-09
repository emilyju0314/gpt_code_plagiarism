#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1);
int n, m, tot, pos[1000001];
pair<int, int> gg[3];
struct info {
  pair<int, int> mx;
  int cnt, L, R;
} a[N << 2];
info operator+(const info& a, const info& b) {
  info c;
  c.cnt = a.cnt + b.cnt;
  c.mx = max(a.mx, b.mx);
  c.L = min(a.L, b.L);
  c.R = max(a.R, b.R);
  if (a.cnt && b.cnt && a.R + 1 < b.L) {
    int p = (b.L + a.R) / 2;
    c.mx = max(c.mx, make_pair(min(b.L - p, p - a.R), -p));
  }
  return c;
}
void build(int l, int r, int rt) {
  if (l == r) {
    a[rt].cnt = 0;
    a[rt].L = inf;
    a[rt].R = -inf;
    a[rt].mx = make_pair(0, 0);
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  a[rt] = a[rt << 1] + a[rt << 1 | 1];
}
void update(int p, int op, int l, int r, int rt) {
  if (l == r) {
    if (op == 1) {
      a[rt].cnt = 1;
      a[rt].L = a[rt].R = p;
      a[rt].mx = make_pair(0, 0);
    } else {
      a[rt].cnt = 0;
      a[rt].L = inf;
      a[rt].R = -inf;
      a[rt].mx = make_pair(0, 0);
    }
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid)
    update(p, op, l, mid, rt << 1);
  else
    update(p, op, mid + 1, r, rt << 1 | 1);
  a[rt] = a[rt << 1] + a[rt << 1 | 1];
}
int main() {
  scanf("%d%d", &n, &m);
  build(1, n, 1);
  while (m--) {
    int op, x;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      tot = 0;
      if (a[1].mx.second) gg[tot++] = a[1].mx;
      if (a[1].L != 1 && a[1].cnt) gg[tot++] = make_pair(a[1].L - 1, -1);
      if (a[1].R != n && a[1].cnt) gg[tot++] = make_pair(n - a[1].R, -n);
      if (!tot) gg[tot++] = make_pair(inf, -1);
      sort(gg, gg + tot);
      reverse(gg, gg + tot);
      pos[x] = -gg[0].second;
      update(-gg[0].second, 1, 1, n, 1);
      printf("%d\n", -gg[0].second);
    } else {
      update(pos[x], -1, 1, n, 1);
    }
  }
  return 0;
}
