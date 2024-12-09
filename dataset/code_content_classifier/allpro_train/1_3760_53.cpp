#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point() {}
  void read() { cin >> x >> y; }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  double det(const Point& p) const { return x * p.y - y * p.x; }
  double dist(const Point& p) const { return hypot(x - p.x, y - p.y); }
  Point operator*(double d) const { return Point(x * d, y * d); }
  Point operator/(double d) const { return Point(x / d, y / d); }
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
};
const double EPS = 1e-6;
inline int compare(double a, double b) {
  return a < b - EPS ? -1 : a > b + EPS;
}
const int MAX_NPOINTS = 6000;
Point ps[301][MAX_NPOINTS];
int n, k;
double width, height;
Point init[MAX_NPOINTS];
int nInit;
Point isSS(const Point& p1, const Point& p2, const Point& q1, const Point& q2) {
  double a1 = ((q2.x - q1.x) * (p1.y - q1.y) - (q2.y - q1.y) * (p1.x - q1.x)),
         a2 = -((q2.x - q1.x) * (p2.y - q1.y) - (q2.y - q1.y) * (p2.x - q1.x));
  return (p1 * a2 + p2 * a1) / (a1 + a2);
}
Point qs[MAX_NPOINTS];
void convexCut(Point ps[], int& nPs, const Point& q1, const Point& q2) {
  int nQs = 0;
  for (int i = 0; i < nPs; ++i) {
    Point p1 = ps[i];
    Point p2 = ps[(i + 1) % nPs];
    int d1 = compare(
        ((q2.x - q1.x) * (p1.y - q1.y) - (q2.y - q1.y) * (p1.x - q1.x)), 0);
    int d2 = compare(
        ((q2.x - q1.x) * (p2.y - q1.y) - (q2.y - q1.y) * (p2.x - q1.x)), 0);
    if (d1 >= 0) qs[nQs++] = p1;
    if (d1 * d2 < 0) qs[nQs++] = isSS(p1, p2, q1, q2);
  }
  nPs = nQs;
  memcpy(ps, qs, sizeof(Point) * nPs);
}
void inputData() {
  cin >> n >> k;
  for (int j = 1; j <= n; j++) {
    ps[j][0] = Point(0, 0);
    ps[j][k + 2] = Point(k, 0);
    for (int i = 1; i <= k + 1; ++i) {
      ps[j][i].x = i;
      scanf("%lf", &ps[j][i].y);
    }
  }
}
void initPolygon(Point x, Point y, Point z, Point a) {
  nInit = 0;
  init[nInit++] = x;
  init[nInit++] = y;
  init[nInit++] = z;
  init[nInit++] = a;
}
double area(Point ps[], int nps) {
  double x = 0;
  for (int i = 0; i < nps; i++) x += ps[i].det(ps[(i + 1) % nps]);
  return fabs(x / 2.0);
}
Point poly[MAX_NPOINTS];
void work() {
  for (int i = 1; i <= n; i++) {
    double ans = 0.0;
    for (int j = 2; j <= k + 1; j++) {
      initPolygon(Point(j - 1, 0), Point(j, 0), ps[i][j], ps[i][j - 1]);
      int nPoly = nInit;
      for (int h = 0; h < nPoly; h++) poly[h] = init[h];
      for (int h = 1; h < i; h++) {
        Point p1 = ps[h][j - 1], p2 = ps[h][j];
        convexCut(poly, nPoly, p1, p2);
      }
      ans += area(poly, nPoly);
    }
    printf("%.10f\n", ans);
  }
}
int main() {
  inputData();
  work();
}
