#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 100000;

const double INF = 1e70;

/* typedef */

template <typename T>
struct Pt {
  T x, y;

  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt& pt) : x(pt.x), y(pt.y) {}

  bool operator==(const Pt pt) const { return x == pt.x && y == pt.y; }
  Pt<T> operator+(const Pt pt) const { return Pt<T>(x + pt.x, y + pt.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt pt) const { return Pt<T>(x - pt.x, y - pt.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt v) const { return x * v.x + y * v.y; }
  T cross(Pt v) const { return x * v.y - y * v.x; }
  Pt<T> mid(const Pt pt) { return Pt<T>((x + pt.x) / 2, (y + pt.y) / 2); }
  T d2() { return x * x + y * y; }
  double d() { return sqrt(d2()); }

  Pt<T> rot(double th) {
    double c = cos(th), s = sin(th);
    return Pt<T>(c * x - s * y, s * x + c * y);
  }

  bool operator<(const Pt& pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }

  void print(string format) {
    printf(("(" + format + ", " + format + ")\n").c_str(), x, y);
  }
  void print() { print("%.6lf"); }
};

typedef Pt<double> pt;

struct Robot {
  pt p;
  int drc;
  Robot() {}
  Robot(pt _p, int _drc) : p(_p), drc(_drc) {}
  bool operator<(const Robot& r0) const { return p.x < r0.p.x; }
};

typedef set<Robot> srbt;

/* global variables */

int n;
pt v;
double r;
Robot rbts[MAX_N];

/* subroutines */

bool lessy(const Robot& r0, const Robot& r1) { return r0.p.y < r1.p.y; }

/* main */

int main() {
  for (;;) {
    cin >> n;
    if (n == 0) break;

    cin >> v.x >> v.y >> r;

    double th = -atan2(v.y, v.x);
    pt v0 = v.rot(th);
    //v0.print(); printf("th=%.6lf\n", th);

    double rr = r * 2;
    double dvx = v0.x * 2;
    
    for (int i = 0; i < n; i++) {
      pt p;
      cin >> p.x >> p.y >> rbts[i].drc;
      rbts[i].p = p.rot(th);
    }
    sort(rbts, rbts + n, lessy);
    
    double min_t = INF;
    srbt srl, srr;
    
    for (int i0 = 0, i1 = 0; i1 < n; i1++) {
      Robot& r1 = rbts[i1];

      while (i0 < i1 && r1.p.y - rbts[i0].p.y > rr) {
	if (rbts[i0].drc > 0) srl.erase(rbts[i0]);
	else srr.erase(rbts[i0]);
	i0++;
      }
      
      if (r1.drc < 0) {
	if (! srl.empty()) {
	  srbt::iterator rit = srl.lower_bound(r1);
	  if (rit != srl.begin()) {
	    rit--;
	    pt dp = r1.p - rit->p;
	    double t = (dp.x - sqrt(rr * rr - dp.y * dp.y)) / dvx;
	    if (min_t > t) min_t = t;
	  }
	}

	srr.insert(r1);
      }
      else {
	if (! srr.empty()) {
	  srbt::iterator rit = srr.lower_bound(r1);
	  if (rit != srr.end()) {
	    pt dp = rit->p - r1.p;
	    double t = (dp.x - sqrt(rr * rr - dp.y * dp.y)) / dvx;
	    if (min_t > t) min_t = t;
	  }
	}

	srl.insert(r1);
      }
    }

    if (min_t >= INF)
      cout << "SAFE" << endl;
    else 
      printf("%.6lf\n", min_t);
  }

  return 0;
}