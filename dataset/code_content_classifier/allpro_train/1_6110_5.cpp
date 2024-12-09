#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q;
const double PI = std::acos(-1);
struct Point {
  double x, y;
};
inline Point operator+(const Point &a, const Point &b) {
  return {a.x + b.x, a.y + b.y};
}
inline Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}
inline Point operator*(const Point &a, double b) { return {a.x * b, a.y * b}; }
inline Point operator/(const Point &a, double b) { return {a.x / b, a.y / b}; }
inline double cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
const double EPS = 1e-8;
Point a[N], p;
double s[N];
inline Point intersect(Point p, Point v, Point q, Point u) {
  return q + u * ((cross(p, v) - cross(q, v)) / cross(u, v));
}
double calc(double m) {
  Point v = {cos(m), sin(m)};
  auto dis = [&](Point pp) { return cross(v, pp - p); };
  int l = 0, r = n - 2, lp = 0, rp = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    bool ok;
    if (dis(a[0]) > dis(a[n - 1]))
      ok = dis(a[mid + 1]) <= dis(a[mid]) || dis(a[mid]) >= dis(a[0]);
    else
      ok = dis(a[mid + 1]) <= dis(a[mid]) && dis(a[mid]) <= dis(a[0]);
    if (ok)
      lp = l = mid + 1;
    else
      r = mid - 1;
  }
  l = 0, r = n - 2;
  while (l <= r) {
    int mid = (l + r) >> 1;
    bool ok;
    if (dis(a[0]) < dis(a[n - 1]))
      ok = dis(a[mid + 1]) >= dis(a[mid]) || dis(a[mid]) <= dis(a[0]);
    else
      ok = dis(a[mid + 1]) >= dis(a[mid]) && dis(a[mid]) >= dis(a[0]);
    if (ok)
      rp = l = mid + 1;
    else
      r = mid - 1;
  }
  int t1 = 0, t2 = 0;
  l = lp, r = rp;
  if (r <= l) r += n;
  --r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (dis(a[mid]) < 0)
      t1 = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  l = rp, r = lp;
  if (r <= l) r += n;
  --r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (dis(a[mid]) > 0)
      t2 = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  if (t1 >= n) t1 -= n;
  if (t2 >= n) t2 -= n;
  if (t1 > t2) t2 += n;
  Point p1 = intersect(p, v, a[t1], a[t1 + 1] - a[t1]);
  Point p2 = intersect(p, v, a[t2], a[t2 + 1] - a[t2]);
  return s[t2] - s[t1 + 1] + cross(a[t1 + 1], p1) + cross(p1, p2) +
         cross(p2, a[t2]);
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) a[i + n] = a[i];
  for (int i = 1; i < n * 2; i++) s[i] = s[i - 1] + cross(a[i], a[i - 1]);
  double tot = s[n];
  for (int _ = 1; _ <= q; _++) {
    scanf("%lf%lf", &p.x, &p.y);
    double l = 0, r = PI;
    bool sgn = calc(0) * 2 >= tot;
    for (int _ = 1; _ <= 60; _++) {
      double mid = (l + r) / 2;
      double tmp = calc(mid) * 2;
      if ((tmp >= tot) == sgn)
        l = mid;
      else
        r = mid;
    }
    printf("%.15lf\n", (l + r) / 2);
  }
  return 0;
}
