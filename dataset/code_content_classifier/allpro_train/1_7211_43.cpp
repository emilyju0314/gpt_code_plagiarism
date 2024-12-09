#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int x[N], b[N];
double v[N];
struct Node {
  int l, r;
  double sum, s, ls, rs;
} a[N * 4];
void build(int l, int r, int p) {
  a[p].l = l;
  a[p].r = r;
  if (l == r) {
    a[p].sum = v[l];
    a[p].s = a[p].ls = a[p].rs = max(0.0, v[l]);
    return;
  } else {
    int mid = (l + r) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    a[p].sum = a[p * 2].sum + a[p * 2 + 1].sum;
    a[p].s =
        max(max(a[p * 2].s, a[p * 2 + 1].s), a[p * 2].rs + a[p * 2 + 1].ls);
    a[p].ls = max(a[p * 2].ls, a[p * 2].sum + a[p * 2 + 1].ls);
    a[p].rs = max(a[p * 2 + 1].rs, a[p * 2].rs + a[p * 2 + 1].sum);
  }
}
void cal(int l, int r, int p, double &x, double &y, double &z, double &s) {
  if (a[p].l == l && a[p].r == r) {
    x = a[p].ls;
    y = a[p].rs;
    z = a[p].s;
    s = a[p].sum;
    return;
  }
  int mid = (a[p].l + a[p].r) / 2;
  if (r <= mid)
    cal(l, r, p * 2, x, y, z, s);
  else if (l > mid)
    cal(l, r, p * 2 + 1, x, y, z, s);
  else {
    double x1, y1, z1, x2, y2, z2, s1, s2;
    cal(l, mid, p * 2, x1, y1, z1, s1);
    cal(mid + 1, r, p * 2 + 1, x2, y2, z2, s2);
    x = max(x1, s1 + x2);
    y = max(y1 + s2, y2);
    s = s1 + s2;
    z = max(max(z1, z2), y1 + x2);
  }
  return;
}
int main() {
  int n, m, c, i;
  double ans = 0;
  scanf("%d%d%d", &n, &m, &c);
  n--;
  for (i = 0; i <= n; i++) scanf("%d", &x[i]);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (i = 1; i <= n; i++)
    v[i] = (x[i] - x[i - 1]) / 2.0 - c * 1.0 * b[i] / 100.0;
  build(1, n, 1);
  for (i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    double x, y, z, s;
    cal(l, r - 1, 1, x, y, z, s);
    ans += z;
  }
  printf("%.9lf\n", ans);
}
