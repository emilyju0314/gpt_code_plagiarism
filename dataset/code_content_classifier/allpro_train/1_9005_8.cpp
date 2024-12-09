#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define double long double
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
const double EPS = 1e-10;
struct Point {
  double x;
  double y;

  Point() : x(0.0),y(0.0){}
  Point(double _x,double _y) :x(_x),y(_y){}

  Point operator+(const Point& other) const { return { x + other.x , y + other.y }; }
  Point operator-(const Point& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Point& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); }

  double dot(const Point& other) const { return x * other.x + y * other.y; }
  double cross(const Point& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }
};
// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Point A, const Point B) { return A.dot(B) / (A.length()*B.length()); }
double Sin(const Point A, const Point B) { return A.cross(B) / (A.length()*B.length()); }

struct Line {
  Point s;
  Point t;
  Point v;
  
  Line() : s({0,0}), t({0,0}) {}
  Line(Point s, Point t) : s(s), t(t) { v = t - s; }

  double length() { return sqrt(v.x*v.x + v.y*v.y); }
};

double Dist(const Point &A, const Point &B) { return (A -B).length(); }

// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Line A, const Line B) { return (A.v).dot(B.v) / ((A.v).length()*(B.v).length()); }
double Sin(const Line A, const Line B) { return (A.v).cross(B.v) / ((A.v).length()*(B.v).length()); }

Point CrossPoint(const Line a, const Line b) {
  if( abs(Sin(a, b)) < EPS) {
    cout << "Pararell" << "\n";
    return Point(0,0);
  }
  if(abs(a.v.x) < EPS) {
    double alpha2 = b.v.y / b.v.x;
    double beta2 = b.s.y - alpha2 * b.s.x;
    double resX = a.s.x;
    double resY = alpha2 * resX + beta2;
    return Point(resX, resY);
  }
  else if( abs(b.v.x) < EPS) {
    double alpha1 = a.v.y / a.v.x;
    double beta1 = a.s.y - alpha1 * a.s.x;
    double resX = b.s.x;
    double resY = alpha1 * resX + beta1;
    return Point(resX, resY);
  }
  else {
    double alpha1 = a.v.y / a.v.x;
    double beta1 = a.s.y - alpha1 * a.s.x;
    double alpha2 = b.v.y / b.v.x;
    double beta2 = b.s.y - alpha2 * b.s.x;
    double resX = (beta2 - beta1) / (alpha1 - alpha2);
    double resY = alpha1 * resX + beta1;
    return Point(resX, resY);
  }
}

Line OrthogonalLine(const Line &a, const Point &s) {
  Point t(s.x + a.v.y, s.y - a.v.x);
  return Line(s, t);

}

Line Bisector(Line &a,  Line &b) {
  double l = min(a.length(), b.length());
  Line v(Point(0,0), Point(1,0));
  Point c = a.s;
  c.x += l * Cos(v, a);
  c.y += l * Sin(v, a);
  Point d = b.s;
  d.x += l * Cos(v, b);
  d.y += l * Sin(v, b);
  
  Line ac = OrthogonalLine(a, c);
  Line bd = OrthogonalLine(b, d);
  
  Point t = CrossPoint(ac, bd);
  return Line(a.s, t);
}

double DistPointLine(const Line &a, const Point &c) {
  double Z = (a.v.x)*(a.v.x) + (a.v.y)*(a.v.y);
  double dy = ( (c.x - a.t.x)*(a.v.x)*(a.v.y) + a.t.y*(a.v.x)*(a.v.x) + c.y*(a.v.y)*(a.v.y) )/Z;
  double dx;
  if(abs(a.v.x) > EPS) {
    dx = c.x - (a.v.y)*(dy - c.y) / (a.v.x);
  }
  else {
    dx = a.t.x + (a.v.x)*(dy - a.t.y) / (a.v.y);
  }
  return Dist(c, Point(dx, dy));
}

struct Circle {
  Point p;
  double r;

  Circle() : p({0,0}), r(0) {}
  Circle(Point p, double r) : p(p), r(r) {}
};

Circle InscribedCircle(const Point &a, const Point &b, const Point &c) {
  Line ab(a, b), ac(a, c);
  Line bisA = Bisector(ab, ac);
  Line bc(b, c), ba(b, a);
  Line bisB = Bisector(bc, ba);  


  
  Point d = CrossPoint(bisA, bisB);
  return Circle(d, DistPointLine(ab, d));
}

int main()
{
  Point p1,p2,p3;
  cin >> p1.x >> p1.y;
  cin >> p2.x >> p2.y;
  cin >> p3.x >> p3.y;
  Circle c = InscribedCircle(p1, p2, p3);
  printf("%.10Lf %.10Lf %.10Lf\n", c.p.x, c.p.y, c.r);
  
  return 0;
}

