#include <bits/stdc++.h>
using namespace std;
const double eps1 = 1e-5;
const double eps2 = 1e-8;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  void input() { scanf("%lf%lf", &x, &y); }
  double dist(Point a) {
    return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
  }
  Point zz(Point a) { return Point(x * 2 - a.x, y * 2 - a.y); }
  Point Circumcenter(Point a, Point b) {
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2.0;
    double a2 = x - a.x, b2 = y - a.y, c2 = (a2 * a2 + b2 * b2) / 2.0;
    double d = a1 * b2 - a2 * b1;
    return Point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
  }
};
double Cross(Point p, Point p1, Point p2) {
  return (p.x - p1.x) * (p.y - p2.y) - (p.y - p1.y) * (p.x - p2.x);
}
bool issame(double x, double y) {
  if (fabs(x - y) < eps2) {
    return true;
  } else {
    return false;
  }
}
bool Isconvex(Point a, Point b, Point c, Point d) {
  double t1 = Cross(a, b, c);
  double t2 = Cross(b, c, d);
  double t3 = Cross(c, d, a);
  double t4 = Cross(d, a, b);
  if (t1 * t2 <= eps1 || t2 * t3 <= eps1 || t3 * t4 <= eps1 || t4 * t1 <= eps1)
    return false;
  return true;
}
bool solve(Point k, Point l, Point m) {
  if (Cross(k, l, m) == 0) return false;
  Point b = k.Circumcenter(l.zz(m), l), a = k.zz(b), c = l.zz(b), d = m.zz(c);
  if (!issame(a.dist(b), b.dist(c)) || !issame(b.dist(c), c.dist(d)))
    return false;
  if (!Isconvex(a, b, c, d)) return false;
  printf("YES\n");
  printf("%.9f %.9f %.9f %.9f %.9f %.9f %.9f %.9f\n", a.x, a.y, b.x, b.y, c.x,
         c.y, d.x, d.y);
  return true;
}
int main() {
  Point k, l, m;
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    k.input(), l.input(), m.input();
    if (solve(k, l, m)) continue;
    if (solve(k, m, l)) continue;
    if (solve(l, k, m)) continue;
    if (solve(l, m, k)) continue;
    if (solve(m, k, l)) continue;
    if (solve(m, l, k)) continue;
    printf("NO\n\n");
  }
  return 0;
}
