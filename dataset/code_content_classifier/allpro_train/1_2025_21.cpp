#include <bits/stdc++.h>
using namespace std;
int a, b, ns;
string s;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
string d = "UDLR";
map<char, int> M;
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) {
    x = a;
    y = b;
  }
  double mod2() { return x * x + y * y; }
  double mod() { return sqrt(x * x + y * y); }
  double arg() { return atan2(y, x); }
  Point ort() { return Point(-y, x); }
  Point unit() {
    double k = mod();
    return Point(x / k, y / k);
  }
};
Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
Point operator/(const Point &a, double k) { return Point(a.x / k, a.y / k); }
Point operator*(const Point &a, double k) { return Point(a.x * k, a.y * k); }
bool operator==(const Point &a, const Point &b) {
  return fabs(a.x - b.x) < 1e-8 && fabs(a.y - b.y) < 1e-8;
}
bool operator!=(const Point &a, const Point &b) { return !(a == b); }
bool operator<(const Point &a, const Point &b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
double dist(const Point &A, const Point &B) {
  return hypot(A.x - B.x, A.y - B.y);
}
double cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }
double dot(const Point &A, const Point &B) { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) {
  return cross(B - A, C - A);
}
double get_angle(Point A, Point P, Point B) {
  double ang = (A - P).arg() - (B - P).arg();
  while (ang < 0) ang += 2 * acos(-1);
  while (ang > 2 * acos(-1)) ang -= 2 * acos(-1);
  return min(ang, 2 * acos(-1) - ang);
}
bool isInt(double k) { return abs(k - int(k + 0.5)) < 1e-5; }
bool isIn(Point O, Point A, Point B, Point X) {
  return abs(abs(area(O, A, B)) - (abs(area(O, A, X)) + abs(area(A, B, X)) +
                                   abs(area(O, B, X)))) < 1e-8;
}
double f(double a) {
  if (a < 0) a += 2 * acos(-1);
  return a;
}
double areaHeron(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
double circumradius(double a, double b, double c) {
  return a * b * c / (4 * areaHeron(a, b, c));
}
double areaHeron(double a, double b, double c, double d) {
  double s = (a + b + c + d) / 2;
  return sqrt((s - a) * (s - b) * (s - c) * (s - d));
}
double circumradius(double a, double b, double c, double d) {
  return sqrt((a * b + c * d) * (a * c + b * d) * (a * d + b * c)) /
         (4 * areaHeron(a, b, c, d));
}
bool between(const Point &A, const Point &B, const Point &P) {
  return P.x + 1e-8 >= min(A.x, B.x) && P.x <= max(A.x, B.x) + 1e-8 &&
         P.y + 1e-8 >= min(A.y, B.y) && P.y <= max(A.y, B.y) + 1e-8;
}
bool onSegment(const Point &A, const Point &B, const Point &P) {
  return abs(area(A, B, P)) < 1e-8 && between(A, B, P);
}
bool intersects(const Point &P1, const Point &P2, const Point &P3,
                const Point &P4) {
  double A1 = area(P3, P4, P1);
  double A2 = area(P3, P4, P2);
  double A3 = area(P1, P2, P3);
  double A4 = area(P1, P2, P4);
  if (((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) &&
      ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0)))
    return true;
  else if (A1 == 0 && onSegment(P3, P4, P1))
    return true;
  else if (A2 == 0 && onSegment(P3, P4, P2))
    return true;
  else if (A3 == 0 && onSegment(P1, P2, P3))
    return true;
  else if (A4 == 0 && onSegment(P1, P2, P4))
    return true;
  else
    return false;
}
bool sameLine(Point P1, Point P2, Point P3, Point P4) {
  return area(P1, P2, P3) == 0 && area(P1, P2, P4) == 0;
}
bool isParallel(const Point &P1, const Point &P2, const Point &P3,
                const Point &P4) {
  return abs(cross(P2 - P1, P4 - P3)) <= 1e-8;
}
int main() {
  for (int i = 0; i < (4); i++) M[d[i]] = i;
  while (cin >> a >> b >> s) {
    ns = s.size();
    Point V = Point(0, 0), A = Point(a, b), O = V;
    vector<Point> T(ns + 1);
    T[0] = O;
    bool solve = 0;
    for (int i = 0; i < (ns); i++) {
      int ind = M[s[i]];
      V = V + Point(dx[ind], dy[ind]);
      if (V == A) solve = 1;
      T[i + 1] = V;
    }
    if (A == O || solve) {
      puts("Yes");
      continue;
    }
    for (int i = 0; i < (ns + 1); i++) {
      Point Temp = A - T[i];
      if (Temp != O && V != O && isParallel(O, Temp, O, V)) {
        double k;
        if (abs(V.x) <= 1e-8)
          k = Temp.y / V.y;
        else
          k = Temp.x / V.x;
        if (isInt(k) && k >= 0) solve = 1;
      }
    }
    puts(solve ? "Yes" : "No");
  }
}
