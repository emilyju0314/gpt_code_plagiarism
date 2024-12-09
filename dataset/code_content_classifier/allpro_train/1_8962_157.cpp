#include <bits/stdc++.h>
using namespace std;
long double x[2], y[2], r[2];
inline long double sqr(long double x) { return x * x; }
inline long long sqrl(long long x) { return x * x; }
inline long double fcos(long double a, long double b, long double c) {
  return acosl((a * a + b * b - c * c) / (2 * a * b));
}
inline long double cut(long double ang, long double r) {
  long double s1 = ang * r * r;
  long double s2 = sinl(ang) * cosl(ang) * r * r;
  return s1 - s2;
}
const long double pi = acosl(-1);
double solve() {
  if (r[0] > r[1]) {
    swap(r[0], r[1]);
    swap(x[0], x[1]);
    swap(y[0], y[1]);
  }
  long long dx = x[0] - x[1], dy = y[0] - y[1];
  long long ds = sqrl(dx) + sqrl(dy);
  if (ds >= sqrl(r[0] + r[1])) return 0;
  long double d = sqrtl(ds);
  if (d + r[0] <= r[1]) return sqr(r[0]) * pi;
  long double ang[2];
  ang[0] = fcos(d, r[0], r[1]);
  ang[1] = fcos(d, r[1], r[0]);
  return cut(ang[0], r[0]) + cut(ang[1], r[1]);
}
int main() {
  cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
  printf("%.10f\n", solve());
  return 0;
}
