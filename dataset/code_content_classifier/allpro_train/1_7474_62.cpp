#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
struct sound {
  double l, p;
  bool operator<(const sound s) const {
    return l * p * (1 - s.p) > s.l * s.p * (1 - p);
  }
};
int n, m, j, l, i, h, t, mn, f[155555], q1, q2, q, p1, p2, d, st, b[100500];
sound a[155555];
double ans, s;
void init() {
  scanf("%d", &n);
  for (j = 1; j <= n; j++) {
    scanf("%lf%lf", &a[j].l, &a[j].p);
    a[j].p /= 100.0;
  }
  sort(a + 1, a + n + 1);
}
void solve() {
  for (j = 1; j <= n; j++) {
    ans += a[j].l;
    ans += s * (1.0 - a[j].p);
    s += a[j].l * a[j].p;
  }
  printf("%.9f", ans);
}
void solwe_slow() {}
void stress() {}
void answer() {}
int main() {
  init();
  solve();
  return 0;
}
