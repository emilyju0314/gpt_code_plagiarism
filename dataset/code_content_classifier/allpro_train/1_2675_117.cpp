#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ld INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct Point {
  ld x, y;

  Point(ld x = 0, ld y = 0): x(x), y(y) {}

  Point operator + (Point &p) {
    return Point(x + p.x, y + p.y);
  }

  Point operator - (Point &p) {
    return Point(x - p.x, y - p.y);
  }

  Point operator * (ld k) {
    return Point(x * k, y * k);
  }

  Point operator / (ld k) {
    return Point(x / k, y / k);
  }

  bool operator < (const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

ld norm(Point p) {
  return p.x * p.x + p.y * p.y;
}

ld dist(Point p) {
  return sqrt(norm(p));
}

ld dot(Point p1, Point p2) {
  return p1.x * p2.x + p1.y * p2.y;
}

ld cross(Point p1, Point p2) {
  return p1.x * p2.y - p1.y * p2.x;
}

Point rotate(Point p, ld theta) {
  return Point(p.x * cos(theta) - p.y * sin(theta), p.x * sin(theta) + p.y * cos(theta));
}

//1:反時計回り
//-1:時計回り
//2:p2, p0, p1の順で同一直線上
//-2:p0, p1, p2の順
//0:p2が線分p0, p1上
int ccw(Point p0, Point p1, Point p2) {
  Point v1 = p1 - p0, v2 = p2 - p0;
  if (cross(v1, v2) > 0) return 1;
  else if (cross(v1, v2) < 0) return -1;
  else if (dot(v1, v2) < 0) return 2;
  else if (norm(v1) < norm(v2)) return -2;
  else return 0;
}

//線分p1, p2がp3, p4と交差するか
bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

//直線p2-p1と点p3の距離
ld getDistanceLP(Point p1, Point p2, Point p3) {
  return fabs(cross(p2-p1, p3-p1) / dist(p2-p1));
}

//線分s(p2-p1)と点p3の距離
ld getDistanceSP(Point p1, Point p2, Point p3) {
  if (dot(p2-p1, p3-p1) < 0) return dist(p3-p1);
  else if (dot(p1-p2, p3-p2) < 0) return dist(p3-p2);
  else return getDistanceLP(p1, p2, p3);
}

//線分s1(p2-p1)と線分s2(p4-p3)の距離
ld getDistanceTS(Point p1, Point p2, Point p3, Point p4) {
  if (intersect(p1, p2, p3, p4)) return 0;
  ld ans = INF;
  ans = min(ans, getDistanceSP(p1, p2, p3));
  ans = min(ans, getDistanceSP(p1, p2, p4));
  ans = min(ans, getDistanceSP(p3, p4, p1));
  ans = min(ans, getDistanceSP(p3, p4, p2));
  return ans;
}

vector<Point> convex_hull(vector<Point>& ps, int n) {
  sort(ps.begin(), ps.end());
  int k = 0;
  vector<Point> qs(2 * n);
  rep(i, n) {
    while (k > 1 && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && (cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)) k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

//円
struct Circle {
  Point p;
  ld r;

  Circle() {}
  Circle(Point p, ld r): p(p), r(r) {}
};

//２円の交点
array<Point, 2> getIntersections(Circle c1, Circle c2) {
  ld d = dist(c2.p - c1.p);
  ld rc = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * d);
  ld rs = sqrt(c1.r * c1.r - rc * rc);
  Point e1 = (c2.p - c1.p) / d;
  Point e2 = rotate(e1, M_PI / 2) * rs;
  Point e3 = rotate(e1, -M_PI / 2) * rs;
  e1 = e1 * rc;
  Point a = c1.p + e1 + e2;
  Point b = c1.p + e1 + e3;
  return {a, b};
}

int n;
Circle c[105];

Point p[205];
ld d[205][205];

void init() {
  rep(i, 205) rep(j, 205) d[i][j] = INF;
  rep(i, 205) d[i][i] = 0;
}

bool check(Point p1, Point p2, int s, int t) {
  FOR(i, s, t) {
    if (!intersect(p1, p2, p[i * 2], p[i * 2 + 1])) return false;
  }
  return true;
}

void solve() {
  rep(i, n - 1) {
    array<Point, 2> a = getIntersections(c[i], c[i + 1]);
    rep(j, 2) p[i * 2 + j] = a[j];
  }
  int s = n * 2 - 2, t = s + 1;
  p[s] = c[0].p;
  p[t] = c[n - 1].p;
  rep(i, s) {
    rep(j, i) {
      if (check(p[i], p[j], j / 2, i / 2)) {
        d[i][j] = d[j][i] = dist(p[i] - p[j]);
      }
    }
  }
  rep(i, s) {
    if (check(p[s], p[i], 0, i / 2)) {
      d[s][i] = d[i][s] = dist(p[s] - p[i]);
    }
    if (check(p[i], p[t], i / 2, n - 1)) {
      d[i][t] = d[t][i] = dist(p[i] - p[t]);
    }
  }
  if (check(p[s], p[t], 0, n - 1)) {
    d[s][t] = d[t][s] = dist(p[s] - p[t]);
  }
  rep(k, t + 1) {
    rep(i, t + 1) {
      rep(j, t + 1) {
        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  cout << d[s][t] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  while (cin >> n, n) {
    init();

    rep(i, n) {
      cin >> c[i].p.x >> c[i].p.y >> c[i].r;
    }

    solve();
  }

  

  




  
  return 0;
}
