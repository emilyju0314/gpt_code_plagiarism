#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

#include <complex>

typedef complex<double> Point;
typedef vector<Point> Polygon;

static const double INF = 1e+10;

#define CURR(P, i) (P[i])
#define NEXT(P, i) (P[(i + 1) % P.size()])

struct Line : public vector<Point> {
  Line() {;}
  Line(Point a, Point b) { push_back(a); push_back(b); }
};

struct Circle {
  Point p;
  double r;
  Circle() {;}
  Circle(Point p, double r) : p(p), r(r) {;}
};

namespace std {
  bool operator<(const Point &lhs, const Point &rhs) {
    return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
  }
}

inline double cross(const Point &a, const Point &b) {
  return imag(conj(a) * b);
}

inline double dot(const Point &a, const Point &b) {
  return real(conj(a) * b);
}

inline int ccw(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) { return 1; }
  if (cross(b, c) < 0) { return -1; }
  if (dot(b, c) < 0) { return 2; }
  if (norm(b) < norm(c)) { return -2; }
  return 0;
}


bool intersectSS(const Line &s, const Line &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

bool intersectSP(const Line &s, const Point &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}


double pv, dv;
struct Segs {
  vector<Line> lines;
  vector<double> sumDist;
  double AllTime() const { return sumDist.back() / dv; }
  Point pos(double t) const {
    if (t - AllTime() >= -EPS) { return lines.back()[1]; }
    Point ret;
    REP(i, sumDist.size()) {
      assert(i != (int)sumDist.size() - 1);
      if (t > sumDist[i + 1] / dv) { continue; }
      t -= sumDist[i] / dv;
      ret = lines[i][0];
      Point vect = lines[i][1] - lines[i][0];
      vect /= abs(vect);
      ret += vect * t * dv;
      break;
    }
    return ret;
  }
  Segs() {;}
};

int n;
double px, py;
double dx, dy;
Point ps[1010];
Segs segs[2];

double BiSearch(const Segs &segs, double startT, Point s) {
  double left = startT;
  double right = 1e+9;
  REP(iter, 200) {
    double mid = (left + right) / 2.0;
    Point p = segs.pos(mid);
    double d = abs(p - s);
    if (d / pv <= mid - startT) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return left;
}

int main() {
  while (scanf("%d", &n) > 0) {
    segs[0] = Segs();
    segs[1] = Segs();
    REP(i, n) {
      double x, y;
      scanf("%lf %lf", &x, &y);
      ps[i] = Point(x, y);
    }
    scanf("%lf %lf %lf", &dx, &dy, &dv);
    scanf("%lf %lf %lf", &px, &py, &pv);
    REP(i, n - 1) {
      if (intersectSP(Line(ps[i], ps[i + 1]), Point(dx, dy))) {
        Point pp = Point(dx, dy);
        segs[0].sumDist.push_back(0);
        for (int j = i; j >= 0; j--) {
          segs[0].lines.push_back(Line(pp, ps[j]));
          double d = segs[0].sumDist.back() + abs(ps[j] - pp);
          segs[0].sumDist.push_back(d);
          pp = ps[j];
        }
        pp = Point(dx, dy);
        segs[1].sumDist.push_back(0);
        for (int j = i + 1; j < n; j++) {
          segs[1].lines.push_back(Line(pp, ps[j]));
          double d = segs[1].sumDist.back() + abs(ps[j] - pp);
          segs[1].sumDist.push_back(d);
          pp = ps[j];
        }
        break;
      }
      assert(i != n - 2);
    }
    double ans = max(segs[0].AllTime() , segs[1].AllTime());
    Point s = Point(px, py);
    {
      // 0 -> 1
      double t = BiSearch(segs[0], 0, s);
      Point np = segs[0].pos(t);
      ans = min(ans, BiSearch(segs[1], t, np));
    }
    {
      // 1 -> 0
      double t = BiSearch(segs[1], 0, s);
      Point np = segs[1].pos(t);
      ans = min(ans, BiSearch(segs[0], t, np));
    }
    {
      // 0
      ans = min(ans, max(BiSearch(segs[0], 0, s), segs[1].AllTime()));
    }
    {
      // 1
      ans = min(ans, max(BiSearch(segs[1], 0, s), segs[0].AllTime()));
    }
    printf("%.8f\n", ans);
  }
}