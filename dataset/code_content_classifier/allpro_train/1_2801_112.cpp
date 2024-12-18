#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
struct point {
  double x, y;
} a, b, w1, w2, m1, m2;
point operator+(point a, point b) {
  point ret;
  ret.x = a.x + b.x;
  ret.y = a.y + b.y;
  return ret;
}
point operator-(point a, point b) {
  point ret;
  ret.x = a.x - b.x;
  ret.y = a.y - b.y;
  return ret;
}
point operator*(point ret, double k) {
  ret.x *= k;
  ret.y *= k;
  return ret;
}
double operator*(point a, point b) { return a.x * b.x + a.y * b.y; }
double cross(point a, point b) { return a.x * b.y - b.x * a.y; }
bool intersect(point a, point b, point c, point d) {
  bool ret = cross(b - a, c - a) * cross(b - a, d - a) < eps &&
             cross(d - c, a - c) * cross(d - c, b - c) < eps;
  ret &= max(min(a.x, b.x), min(c.x, d.x)) <= min(max(a.x, b.x), max(c.x, d.x));
  ret &= max(min(a.y, b.y), min(c.y, d.y)) <= min(max(a.y, b.y), max(c.y, d.y));
  return ret;
}
point symetric(point a, point p, point q) {
  point d = q - p, c = p + d * 0.5, s;
  s.x = c.x + c.x - a.x;
  s.y = c.y + c.y - a.y;
  double k = (a * d - d * s) / (d * d);
  s = s + d * k;
  return s;
}
int main() {
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &w1.x,
        &w1.y, &w2.x, &w2.y, &m1.x, &m1.y, &m2.x, &m2.y);
  if (!intersect(a, b, w1, w2) &&
      (!intersect(a, b, m1, m2) || fabs(cross(a - b, m1 - m2)) < eps))
    printf("YES");
  else {
    point w3 = symetric(w1, m1, m2), w4 = symetric(w2, m1, m2),
          c = symetric(b, m1, m2);
    if (cross(a - m1, m1 - m2) * cross(b - m1, m1 - m2) > eps &&
        !intersect(a, c, w1, w2) && !intersect(a, c, w3, w4) &&
        intersect(a, c, m1, m2) && fabs(cross(a - c, m1 - m2)) > eps)
      printf("YES");
    else
      printf("NO");
  }
}
