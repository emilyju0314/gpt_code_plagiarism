#include <bits/stdc++.h>
using namespace std;
const double INF = 1e12;
namespace ddd {
void main() {
  int n;
  double x, y, vv1, vv2, xx0, xx1, yy0, yy1;
  double l = 0.0, r = INF;
  scanf("%d %lf %lf %lf %lf", &n, &xx0, &yy0, &xx1, &yy1);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf %lf %lf", &x, &y, &vv1, &vv2);
    double u = 0, v = 0;
    if (vv1 == 0.0) {
      if (xx0 < x && x < xx1)
        u = 0, v = INF;
      else {
        puts("-1");
        return;
      }
    } else {
      u = (xx0 - x) / vv1, v = (xx1 - x) / vv1;
      if (u > v) swap(u, v);
    }
    l = max(l, u), r = min(r, v);
    if (vv2 == 0.0) {
      if (yy0 < y && y < yy1)
        u = 0, v = INF;
      else {
        puts("-1");
        return;
      }
    } else {
      u = (yy0 - y) / vv2, v = (yy1 - y) / vv2;
      if (u > v) swap(u, v);
    }
    l = max(l, u), r = min(r, v);
  }
  if (l >= r)
    puts("-1");
  else
    printf("%.10lf", l);
}
}  // namespace ddd
int main() {
  ddd::main();
  return 0;
}
