#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-7;
const double MUL_EPS = 1 + EPS;
const double PI = acos(-1);
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point(const Point &p) : x(p.x), y(p.y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double c) const { return Point(x * c, y * c); }
  Point operator/(double c) const { return Point(x / c, y / c); }
};
double dot(Point p, Point q) { return p.x * q.x + p.y * q.y; }
double dist2(Point p, Point q) { return dot(p - q, p - q); }
double dist(Point p, Point q) { return sqrtl(dist2(p, q)); }
double cross(Point p, Point q) { return p.x * q.y - p.y * q.x; }
double disto2(Point p) { return p.x * p.x + p.y * p.y; }
double disto(Point p) { return sqrtl(disto2(p)); }
double angle(Point p) { return atan2(p.y, p.x); }
ostream &operator<<(ostream &os, const Point &p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
Point RotateCCW90(Point p) { return Point(-p.y, p.x); }
Point RotateCW90(Point p) { return Point(p.y, -p.x); }
Point RotateCCW(Point p, double a) {
  return Point(p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a));
}
Point ProjectPointLine(Point a, Point b, Point c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
Point ProjectPointSegment(Point a, Point b, Point c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double DistancePointSegment(Point a, Point b, Point c) {
  return sqrtl(dist2(c, ProjectPointSegment(a, b, c)));
}
double DistancePointPlane(double x, double y, double z, double a, double b,
                          double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrtl(a * a + b * b + c * c);
}
bool LinesParallel(Point a, Point b, Point c, Point d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesColLinear(Point a, Point b, Point c, Point d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
  if (LinesColLinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return 1;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return 0;
    return 1;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
  return 1;
}
Point ComputeLineIntersection(Point a, Point b, Point c, Point d) {
  b = b - a;
  d = c - d;
  c = c - a;
  return a + b * cross(c, d) / cross(b, d);
}
Point ComputeCircleCenter(Point a, Point b, Point c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
double ComputeCircleRadius(Point a, Point b, Point c) {
  return disto(b - a) * disto(c - b) * disto(a - c) / abs(cross(b - a, c - a)) /
         2;
}
pair<Point, double> MimimumEnlcosingCircle(vector<Point> v) {
  shuffle(v.begin(), v.end(), mt19937(time(0)));
  Point c = v[0];
  double r = 0;
  for (long long i = 0; i < v.size(); i++) {
    if (disto(c - v[i]) > r * MUL_EPS) {
      c = v[i];
      r = 0;
      for (long long j = 0; j < i; j++) {
        if (disto(c - v[j]) > r * MUL_EPS) {
          c = (v[i] + v[j]) / 2;
          r = disto(c - v[i]);
          for (long long k = 0; k < j; k++) {
            if (disto(c - v[k]) > r * MUL_EPS) {
              c = ComputeCircleCenter(v[i], v[j], v[k]);
              r = disto(c - v[i]);
            }
          }
        }
      }
    }
  }
  return {c, r};
}
bool PointInPolygon(const vector<Point> &p, Point q) {
  bool c = 0;
  long long sz = p.size();
  for (long long i = 0; i < sz; i++) {
    long long j = (i + 1) % sz;
    if (((p[i].y <= q.y && q.y < p[j].y) || (p[j].y <= q.y && q.y < p[i].y)) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
bool PointOnPolygon(const vector<Point> &p, Point q) {
  long long sz = p.size();
  for (long long i = 0; i < sz; i++) {
    long long j = (i + 1) % sz;
    if (dist2(ProjectPointSegment(p[i], p[j], q), q) < EPS) return 1;
  }
  return 0;
}
vector<Point> CLIntersection(Point a, Point b, Point c, double r) {
  vector<Point> res;
  b = b - a;
  a = a - c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r * r;
  double D = B * B - A * C;
  if (D < -EPS) return res;
  res.push_back(c + a + b * (-B + sqrtl(D + EPS)) / A);
  if (D > EPS) res.push_back(c + a + b * (-B - sqrtl(D)) / A);
  return res;
}
vector<Point> CCIntersection(Point a, Point b, double r, double R) {
  vector<Point> res;
  double d = sqrtl(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return res;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrtl(r * r - x * x);
  Point v = (b - a) / d;
  res.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
  return res;
}
double ComputeSignedArea(const vector<Point> &p) {
  double area = 0;
  long long sz = p.size();
  for (long long i = 0; i < sz; i++) {
    long long j = (i + 1) % sz;
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
double ComputeArea(const vector<Point> &p) {
  return fabs(ComputeSignedArea(p));
}
Point ComputeCentroid(const vector<Point> &p) {
  Point c(0, 0);
  double scale = 6.0 * ComputeSignedArea(p);
  long long sz = p.size();
  for (long long i = 0; i < sz; i++) {
    long long j = (i + 1) % sz;
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}
bool IsSimple(const vector<Point> &p) {
  long long sz = p.size();
  for (long long i = 0; i < sz; i++) {
    for (long long k = i + 1; k < sz; k++) {
      long long j = (i + 1) % sz;
      long long l = (k + 1) % sz;
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return 0;
    }
  }
  return 1;
}
bool RayOnPoint(Point a, Point v, Point b) {
  b = b - a;
  if (abs(b.x * v.y - b.y * v.x) < EPS) {
    if (b.x * v.x >= -EPS && b.y * v.y >= -EPS) return 1;
    return 0;
  }
  return 0;
}
long long sign(Point a, Point b, Point c) {
  return (cross(b - a, c - b) < 0 ? -1 : 1);
}
double ArcArea(Point a, Point b, Point c, double r) {
  double cosa = dot(a - c, b - c) / (disto(a - c) * disto(b - c));
  double ang = acos(cosa);
  if (ang > 2 * PI) ang = 2 * PI - ang;
  return 0.5 * r * r * ang;
}
double TCArea(Point a1, Point a2, Point c, double r) {
  double ans = 0;
  double d1 = dist2(a1, c), d2 = dist2(a2, c);
  if (d1 > d2) {
    swap(d1, d2);
    swap(a1, a2);
  }
  if (d2 <= r * r)
    ans = 0.5 * abs(cross(a1 - c, a2 - c));
  else if (d1 <= r * r) {
    auto vv = CLIntersection(a1, a2, c, r);
    Point C = vv[0];
    if (vv.size() > 1 && dot(vv[1] - a1, vv[1] - a2) < 0) C = vv[1];
    vv = CLIntersection(a2, c, c, r);
    Point D = vv[0];
    if (vv.size() > 1 && dot(vv[1] - a2, vv[1] - c) < 0) D = vv[1];
    ans = ArcArea(C, D, c, r) + 0.5 * abs(cross(C - c, a1 - c));
  } else {
    auto vv = CLIntersection(a1, a2, c, r);
    if (vv.size() <= 1 || dot(a1 - vv[0], a2 - vv[0]) > 0)
      ans = ArcArea(a1, a2, c, r);
    else {
      if (dist2(a1, vv[1]) < dist2(a1, vv[0])) swap(vv[0], vv[1]);
      ans = ArcArea(a1, vv[0], c, r) + ArcArea(a2, vv[1], c, r) +
            0.5 * abs(cross(vv[0] - c, vv[1] - c));
    }
  }
  return abs(ans);
}
double PolyCircArea(vector<Point> &a, Point c, double r) {
  long long sz = a.size();
  if (sz <= 2) return 0;
  double ans = 0;
  for (long long i = 0; i < sz; i++) {
    long long j = (i + 1) % sz;
    ans += TCArea(a[i], a[j], c, r) * sign(c, a[i], a[j]);
  }
  return abs(ans);
}
struct Line {
  double a, b, c;
  Line() {}
  Line(double A, double B, double C) { a = A, b = B, c = C; }
};
bool areParallel(Line l1, Line l2) {
  return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}
bool areSame(Line l1, Line l2) {
  return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}
struct Circle : Point {
  double r;
  Circle() {}
  Circle(Point c, double r) : Point(c.x, c.y), r(r) {}
  bool strictContains(Point p) { return dist2((*this), p) < r * r; }
  bool onBorder(Point p) { return abs(dist2((*this), p) - r * r) < EPS; }
  bool contains(Point p) { return strictContains(p) || onBorder(p); }
};
bool CircleInside(double dist, double r1, double r2) {
  return fabs(dist - r2) <= r1 && dist + r2 <= r1;
}
bool CircleOutside(double dist, double r1, double r2) {
  return fabs(dist - r2) >= r1 && dist + r2 >= r1;
}
void tangents(Point c, double r1, double r2, vector<Line> &ans) {
  double r = r2 - r1;
  double z = c.x * c.x + c.y * c.y;
  double d = z - r * r;
  if (d < -EPS) return;
  d = sqrt(fabs(d));
  Line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
  ans.push_back(l);
}
vector<Line> tangents(Circle a, Circle b) {
  vector<Line> ans;
  for (long long i : {-1, 1}) {
    for (long long j : {-1, 1}) tangents(b - a, a.r * i, b.r * j, ans);
  }
  long long sz = ans.size();
  for (long long i = 0; i < sz; i++)
    ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
  vector<Line> res;
  for (long long i = 0; i < sz; i++) {
    bool ok = true;
    for (long long j = 0; j < i; j++) {
      if (areSame(res[j], ans[i])) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res.push_back(ans[i]);
    }
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    double r1, R1, r2, R2;
    Point c1, c2;
    cin >> c1.x >> c1.y >> r1 >> R1;
    cin >> c2.x >> c2.y >> r2 >> R2;
    long long cnt = 0;
    double d = dist(c1, c2);
    if (CircleInside(d, r1, r2) || CircleOutside(d, R1, r2)) cnt++;
    if (CircleInside(d, r1, R2) || CircleOutside(d, R1, R2)) cnt++;
    if (CircleInside(d, r2, r1) || CircleOutside(d, R2, r1)) cnt++;
    if (CircleInside(d, r2, R1) || CircleOutside(d, R2, R1)) cnt++;
    cout << cnt << '\n';
  }
  return 0;
}
