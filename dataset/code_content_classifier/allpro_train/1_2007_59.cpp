#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 9;
struct Point {
  long long x, y;
  double ang;
  Point(long long _x = 0, long long _y = 0) {
    x = _x;
    y = _y;
    ang = atan2(y, x);
  }
  Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
  long long cross(const Point& b) const { return x * b.y - b.x * y; }
  bool operator<(const Point& b) const {
    if (fabs(ang - b.ang) > 1e-7) return ang < b.ang;
    return cross(b) >= 0;
  }
} p[N], tem[N];
long long C4(long long x) { return x * (x - 1) * (x - 2) * (x - 3) / 24; }
long long C3(long long x) { return x * (x - 1) * (x - 2) / 6; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld %lld", &p[i].x, &p[i].y);
  long long ans = n * C4(n - 1);
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (j == i) continue;
      tem[++cnt] = p[j] - p[i];
    }
    sort(tem + 1, tem + 1 + cnt);
    for (int j = 1; j <= cnt; ++j) tem[j + cnt] = tem[j];
    for (int j = 1, k = 2; j <= cnt; ++j) {
      for (; tem[j].cross(tem[k]) >= 0 && k < j + cnt; ++k)
        ;
      ans -= C3(k - j - 1);
    }
  }
  printf("%lld", ans);
  return 0;
}
