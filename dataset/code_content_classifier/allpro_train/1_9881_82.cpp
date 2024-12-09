#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline int dcmp(const double &x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
inline double sqr(const double &x) { return x * x; }
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator/(double scale) const { return Point(x / scale, y / scale); }
  Point operator*(double scale) const { return Point(x * scale, y * scale); }
  double operator*(const Point &rhs) const { return x * rhs.x + y * rhs.y; }
  double operator^(const Point &rhs) const { return x * rhs.y - y * rhs.x; }
  Point operator-=(const Point &rhs) { return *this = *this - rhs; }
  Point operator+=(const Point &rhs) { return *this = *this + rhs; }
  Point operator/=(double scale) { return *this = *this / scale; }
  Point operator*=(double scale) { return *this = *this * scale; }
  bool operator<(const Point &rhs) const {
    return dcmp(x - rhs.x) < 0 || (dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) < 0);
  }
  bool operator==(const Point &rhs) const {
    return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
  }
  double vlen() const { return sqrt(sqr(x) + sqr(y)); }
  Point normal() const {
    double L = this->vlen();
    return Point(-y / L, x / L);
  }
  bool read() { return scanf("%lf%lf", &x, &y) == 2; }
  void print() const { printf("(%f, %f)\n", x, y); }
};
struct Line {
  Point P;
  Point v;
  double ang;
  Line() {}
  Line(Point P, Point v) : P(P), v(v) { ang = atan2(v.y, v.x); }
  bool operator<(const Line &rhs) const { return ang < rhs.ang; }
};
inline double Dist(const Point &A, const Point &B) {
  return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}
inline Point Rotate(const Point &P, double rad) {
  return Point(P.x * cos(rad) - P.y * sin(rad),
               P.x * sin(rad) + P.y * cos(rad));
}
double Cross(Point A, Point B) { return A ^ B; }
double Cross(Point O, Point A, Point B) { return Cross(A - O, B - O); }
double Dot(Point A, Point B) { return A * B; }
Point Rotate(Point P, Point O, double alpha) {
  P -= O;
  O.x += P.x * cos(alpha) - P.y * sin(alpha);
  O.y += P.y * cos(alpha) + P.x * sin(alpha);
  return O;
}
double Angle(const Point &A, const Point &B) {
  return acos(A * B / A.vlen() / B.vlen());
}
double Area2(Point A, Point B, Point C) { return (B - A) ^ (C - A); }
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
  Point u = P - Q;
  double t = (w ^ u) / (v ^ w);
  return P + v * t;
}
bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp((a1 - p) ^ (a2 - p)) == 0 && dcmp((a1 - p) * (a2 - p)) < 0;
}
int seg_inter_seg(Point a, Point b, Point c, Point d, Point &k) {
  double s1, s2, s3, s4;
  int d1, d2, d3, d4;
  d1 = dcmp(s1 = (b - a) ^ (c - a));
  d2 = dcmp(s2 = (b - a) ^ (d - a));
  d3 = dcmp(s3 = (d - c) ^ (a - c));
  d4 = dcmp(s4 = (d - c) ^ (b - c));
  if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) {
    k = Point((c.x * s2 - d.x * s1) / (s2 - s1),
              (c.y * s2 - d.y * s1) / (s2 - s1));
    return 1;
  } else if (d1 == 0 && dcmp((a - c) * (b - c)) <= 0) {
    k = c;
    return 2;
  } else if (d2 == 0 && dcmp((a - d) * (b - d)) <= 0) {
    k = d;
    return 2;
  } else if (d3 == 0 && dcmp((c - a) * (d - a)) <= 0) {
    k = a;
    return 2;
  } else if (d4 == 0 && dcmp((c - b) * (d - b)) <= 0) {
    k = b;
    return 2;
  } else
    return 0;
}
double pnt_to_line(Point p, Point l1, Point l2) {
  return fabs((l1 - p) ^ (l2 - p)) / Dist(l1, l2);
}
double DistanceToSegment(Point P, Point A, Point B) {
  if (A == B) return (P - A).vlen();
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if (dcmp((Dot(v1, v2))) < 0)
    return v2.vlen();
  else if (dcmp(Dot(v1, v3)) > 0)
    return v3.vlen();
  else
    return fabs(Cross(v1, v2)) / v1.vlen();
}
Point intersection(Point u1, Point u2, Point v1, Point v2) {
  double t = ((u1 - v1) ^ (v1 - v2)) / ((u1 - u2) ^ (v1 - v2));
  return u1 + (u2 - u1) * t;
}
bool OnLeft(Line L, Point P) { return dcmp(Cross(L.v, P - L.P)) > 0; }
Point GetIntersection(Line a, Line b) {
  Point u = a.P - b.P;
  double t = Cross(b.v, u) / Cross(a.v, b.v);
  return a.P + a.v * t;
}
int HalfPlaneIntersection(Line *L, int n, Point *poly) {
  sort(L, L + n);
  int first, last;
  Point *p = new Point[n];
  Line *q = new Line[n];
  q[first = last = 0] = L[0];
  for (int i = 1; i < n; ++i) {
    while (first < last && !OnLeft(L[i], p[last - 1])) --last;
    while (first < last && !OnLeft(L[i], p[first])) ++first;
    q[++last] = L[i];
    if (fabs(Cross(q[last].v, q[last - 1].v)) < eps) {
      --last;
      if (OnLeft(q[last], L[i].P)) q[last] = L[i];
    }
    if (first < last) p[last - 1] = GetIntersection(q[last - 1], q[last]);
  }
  while (first < last && !OnLeft(q[first], p[last - 1])) --last;
  if (last - first <= 1) return 0;
  p[last] = GetIntersection(q[last], q[first]);
  int m = 0;
  for (int i = first; i <= last; ++i) poly[m++] = p[i];
  return m;
}
void GetLineVectorPoint(double A, double B, double C, Point &p, Point &v) {
  v = Point(B, -A);
  if (fabs(A) > fabs(B))
    p = Point(-C / A, 0);
  else
    p = Point(0, -C / B);
}
int ConvexHull(Point *p, int n, Point *ch) {
  sort(p, p + n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    while (m > 1 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
      --m;
    ch[m++] = p[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; --i) {
    while (m > k && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
      --m;
    ch[m++] = p[i];
  }
  if (n > 1) --m;
  return m;
}
int isPointInPolygon(Point p, Point *poly, int n) {
  int wn = 0;
  for (int i = 0; i < n; ++i) {
    Point &p1 = poly[i], p2 = poly[(i + 1) % n];
    if (p == p1 || p == p2 || OnSegment(p, p1, p2)) return -1;
    int k = dcmp(Cross(p2 - p1, p - p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if (k > 0 && d1 <= 0 && d2 > 0) ++wn;
    if (k < 0 && d2 <= 0 && d1 > 0) --wn;
  }
  if (wn) return 1;
  return 0;
}
double dispallseg(Point p0, Point p1, Point p2, Point p3) {
  double ans1 =
      min(DistanceToSegment(p0, p2, p3), DistanceToSegment(p1, p2, p3));
  double ans2 =
      min(DistanceToSegment(p2, p0, p1), DistanceToSegment(p3, p0, p1));
  return min(ans1, ans2);
}
double GetAngle(Point a1, Point a2, Point b1, Point b2) {
  return (a2 - a1) ^ (b1 - b2);
}
double rotating_calipers_min_dist(Point p[], int np, Point q[], int nq,
                                  int flag = true) {
  if (flag)
    return min(rotating_calipers_min_dist(p, np, q, nq, false),
               rotating_calipers_min_dist(q, nq, p, np, false));
  int sp = 0, sq = 0;
  for (int i = 0; i < np; i++)
    if (dcmp(p[i].y - p[sp].y) < 0) sp = i;
  for (int i = 0; i < nq; i++)
    if (dcmp(q[i].y - q[sq].y) > 0) sq = i;
  double tmp;
  double ans = Dist(p[sp], q[sq]);
  for (int i = 0; i < np; i++) {
    while (dcmp(tmp = GetAngle(p[sp], p[(sp + 1) % np], q[sq],
                               q[(sq + 1) % nq])) < 0)
      sq = (sq + 1) % nq;
    if (dcmp(tmp) == 0)
      ans = min(ans,
                dispallseg(p[sp], p[(sp + 1) % np], q[sq], q[(sq + 1) % nq]));
    else
      ans = min(ans, DistanceToSegment(q[sq], p[sp], p[(sp + 1) % np]));
    sp = (sp + 1) % np;
  }
  return ans;
}
double PolygonArea(Point *p, int n) {
  double area = 0;
  for (int i = 1; i < n - 1; ++i) area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  return area / 2;
}
const int N = 1024;
int n;
pair<double, int> c[10000];
double segP(Point p1, Point p2, Point p3) {
  if (dcmp(p2.x - p3.x))
    return (p1.x - p2.x) / (p3.x - p2.x);
  else
    return (p1.y - p2.y) / (p3.y - p2.y);
}
Point p[600][5];
double polyUnion() {
  int i, j, ii, jj, ta, tb, r, d;
  double z, w, s, sum, tc, td;
  Point tmp1, tmp2;
  sum = 0;
  for (i = 0; i < n; ++i)
    for (ii = 0; ii < 4; ++ii) {
      r = 0;
      c[r++] = make_pair(0., 0);
      c[r++] = make_pair(1., 0);
      for (j = 0; j < n; ++j)
        if (i - j)
          for (jj = 0; jj < 4; ++jj) {
            ta = dcmp(Cross(p[i][ii], p[i][ii + 1], p[j][jj]));
            tb = dcmp(Cross(p[i][ii], p[i][ii + 1], p[j][jj + 1]));
            if (!ta && !tb) {
              tmp1.x = p[j][jj + 1].x - p[j][jj].x;
              tmp1.y = p[j][jj + 1].y - p[j][jj].y;
              tmp2.x = p[i][ii + 1].x - p[i][ii].x;
              tmp2.y = p[i][ii + 1].y - p[i][ii].y;
              if (dcmp(Dot(tmp1, tmp2)) > 0 && j < i) {
                c[r++] = make_pair(segP(p[j][jj], p[i][ii], p[i][ii + 1]), 1);
                c[r++] =
                    make_pair(segP(p[j][jj + 1], p[i][ii], p[i][ii + 1]), -1);
              }
            } else if (ta >= 0 && tb < 0) {
              tc = Cross(p[j][jj], p[j][jj + 1], p[i][ii]);
              td = Cross(p[j][jj], p[j][jj + 1], p[i][ii + 1]);
              c[r++] = make_pair(tc / (tc - td), 1);
            } else if (ta < 0 && tb >= 0) {
              tc = Cross(p[j][jj], p[j][jj + 1], p[i][ii]);
              td = Cross(p[j][jj], p[j][jj + 1], p[i][ii + 1]);
              c[r++] = make_pair(tc / (tc - td), -1);
            }
          }
      sort(c, c + r);
      z = min(max(c[0].first, 0.), 1.);
      d = c[0].second;
      s = 0;
      for (j = 1; j < r; ++j) {
        w = min(max(c[j].first, 0.), 1.);
        if (!d) s += w - z;
        d += c[j].second;
        z = w;
      }
      tmp1.x = tmp1.y = 0;
      sum += Cross(tmp1, p[i][ii], p[i][ii + 1]) * s;
    }
  return 0.5 * sum;
}
Point tp[12];
int main() {
  while (~scanf("%d", &n)) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 4; ++j) tp[j].read();
      ConvexHull(tp, 4, p[i]);
      p[i][4] = p[i][0];
      sum += fabs(PolygonArea(p[i], 4));
    }
    double fuck = polyUnion();
    printf("%.10f\n", sum / fuck);
  }
  return 0;
}
