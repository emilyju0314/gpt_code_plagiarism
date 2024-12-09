#include <bits/stdc++.h>
using namespace std;
double INF = 1e100;
double EPS = 1e-7;
struct pt {
  double x, y;
  pt() {}
  pt(double x, double y) : x(x), y(y) {}
  pt(const pt &p) : x(p.x), y(p.y) {}
  pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  pt operator*(double c) const { return pt(x * c, y * c); }
  pt operator/(double c) const { return pt(x / c, y / c); }
};
double dot(pt p, pt q) { return p.x * q.x + p.y * q.y; }
double dist2(pt p, pt q) { return dot(p - q, p - q); }
double cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
ostream &operator<<(ostream &os, const pt &p) {
  return os << "(" << p.x << "," << p.y << ")";
}
pt RotateCCW90(pt p) { return pt(-p.y, p.x); }
pt RotateCW90(pt p) { return pt(p.y, -p.x); }
pt RotateCCW(pt p, double t) {
  return pt(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
pt ProjectPointLine(pt a, pt b, pt c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
pt ProjectPointSegment(pt a, pt b, pt c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double DistancePointSegment(pt a, pt b, pt c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
double DistancePointPlane(double x, double y, double z, double a, double b,
                          double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
bool LinesParallel(pt a, pt b, pt c, pt d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(pt a, pt b, pt c, pt d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(pt a, pt b, pt c, pt d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
pt ComputeLineIntersection(pt a, pt b, pt c, pt d) {
  b = b - a;
  d = c - d;
  c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
}
pt ComputeCircleCenter(pt a, pt b, pt c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
bool PointInPolygon(const vector<pt> &p, pt q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
bool PointOnPolygon(const vector<pt> &p, pt q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}
vector<pt> CircleLineIntersection(pt a, pt b, pt c, double r) {
  vector<pt> ret;
  b = b - a;
  a = a - c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r * r;
  double D = B * B - A * C;
  if (D < -EPS) return ret;
  ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
  if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
  return ret;
}
vector<pt> CircleCircleIntersection(pt a, pt b, double r, double R) {
  vector<pt> ret;
  double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  pt v = (b - a) / d;
  ret.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) ret.push_back(a + v * x - RotateCCW90(v) * y);
  return ret;
}
double ComputeSignedArea(const vector<pt> &p) {
  double area = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
double ComputeArea(const vector<pt> &p) { return fabs(ComputeSignedArea(p)); }
pt ComputeCentroid(const vector<pt> &p) {
  pt c(0, 0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}
bool IsSimple(const vector<pt> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i + 1; k < p.size(); k++) {
      int j = (i + 1) % p.size();
      int l = (k + 1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
    }
  }
  return true;
}
double coefOnLine(pt a, pt b, pt c) {
  if (abs(a.x - c.x) < EPS) return (b.y - a.y) / (c.y - a.y);
  return (b.x - a.x) / (c.x - a.x);
}
void Union(vector<pair<double, double>> &segs) {
  sort(segs.begin(), segs.end());
  int sz = 0;
  for (auto [l, r] : segs)
    if (l <= r)
      if (!sz || l > segs[sz - 1].second + EPS)
        segs[sz++] = {l, r};
      else
        segs[sz - 1].second = max(segs[sz - 1].second, r);
  segs.resize(sz);
}
vector<pair<double, double>> PolygonSegmentIntersection(vector<pt> &pol, pt a,
                                                        pt b) {
  vector<pair<double, double>> segs;
  vector<pt> impos({a, b});
  for (int k = 0; k < pol.size(); k++)
    if (SegmentsIntersect(a, b, pol[k], pol[(k + 1) % pol.size()]))
      impos.push_back(
          ComputeLineIntersection(a, b, pol[k], pol[(k + 1) % pol.size()]));
  sort(impos.begin(), impos.end(),
       [&](pt x, pt y) { return coefOnLine(a, x, b) < coefOnLine(a, y, b); });
  for (int k = 0; k < impos.size() - 1; k++) {
    pt mid = (impos[k] + impos[k + 1]) / 2;
    if (PointInPolygon(pol, mid))
      segs.emplace_back(coefOnLine(a, impos[k], b),
                        coefOnLine(a, impos[k + 1], b));
  }
  return segs;
}
pair<double, double> CircleSegmentIntersection(pt a, pt b, pt c, double r) {
  vector<pt> ret = CircleLineIntersection(a, b, c, r);
  if (ret.size() < 2) return {0, 0};
  return {
      max<double>(0, min(coefOnLine(a, ret[0], b), coefOnLine(a, ret[1], b))),
      min<double>(1, max(coefOnLine(a, ret[0], b), coefOnLine(a, ret[1], b)))};
}
const int maxn = 1e6;
vector<pt> polygon[maxn];
int n, q;
double s[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cout << fixed;
  {
    double tmp;
    scanf("%lf%lf%d", &tmp, &tmp, &n);
  }
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    polygon[i].resize(v);
    for (auto &p : polygon[i]) scanf("%lf%lf", &p.x, &p.y);
    s[i] = ComputeArea(polygon[i]);
  }
  scanf("%d", &q);
  while (q--) {
    double x, y, r;
    scanf("%lf%lf%lf", &x, &y, &r);
    double ans_area = 0;
    vector<int> ans_polygons;
    for (int i = 0; i < n; i++) {
      bool in = PointInPolygon(polygon[i], pt(x, y));
      for (int j = 0; !in && j < polygon[i].size(); j++) {
        in |= dist2(pt(x, y), polygon[i][j]) <= r * r + EPS;
        in |= DistancePointSegment(polygon[i][j],
                                   polygon[i][(j + 1) % polygon[i].size()],
                                   pt(x, y)) <= r + EPS;
      }
      if (in) {
        ans_area += s[i];
        ans_polygons.push_back(i);
      }
    }
    cout << ans_area << ' ' << ans_polygons.size() << ' ';
    for (auto i : ans_polygons) cout << i << ' ';
    cout << '\n';
  }
}
