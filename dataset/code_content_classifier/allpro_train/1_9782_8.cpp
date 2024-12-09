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

const int MAX_N = 100;
const int MAX_M = 10;

/* typedef */

struct Ball {
  int x, y, dx, dy, sc;
  Ball() {}
  Ball(int _x, int _y, int _dx, int _dy, int _sc):
    x(_x), y(_y), dx(_dx), dy(_dy), sc(_sc) {}
};

struct Pt {
  double x, y;

  Pt() {}
  Pt(double _x, double _y) : x(_x), y(_y) {}
  Pt(const Pt& pt) : x(pt.x), y(pt.y) {}

  Pt operator+(const Pt pt) const { return Pt(x + pt.x, y + pt.y); }
  Pt operator-() const { return Pt(-x, -y); }
  Pt operator-(const Pt pt) const { return Pt(x - pt.x, y - pt.y); }
  Pt operator*(double t) const { return Pt(x * t, y * t); }
  Pt operator/(double t) const { return Pt(x / t, y / t); }
  double dot(Pt v) { return x * v.x + y * v.y; }
  double cross(Pt v) { return x * v.y - y * v.x; }
  Pt mid(const Pt pt) { return Pt((x + pt.x) / 2, (y + pt.y) / 2); }
  
  string to_s() {
    char s[1000];
    sprintf(s, "(%f,%f)", x, y);
    return string(s);
  }
};

struct CL {
  Pt pt;
  double t0, t1;
  CL() {}
  CL(const Pt& _pt, double _t0, double _t1) : pt(_pt), t0(_t0), t1(_t1) {}
};

typedef vector<Pt> vpt;

/* global variables */

int n, m;
Pt pts[MAX_N];
Ball bs[MAX_M];
double evs[MAX_N];

/* subroutines */

bool cross_lines(const Pt& a0, const Pt& a1, const Pt& b0, const Pt& b1,
		 CL& cl) {
  Pt da = a1 - a0;
  Pt db = b1 - b0;

  double op01 = da.cross(db);
  if (op01 == 0.0) return false; /* need to handle parallel?? */

  Pt v = b0 - a0;
  double op0 = v.cross(da);
  double op1 = v.cross(db);

  double t0 = op1 / op01;
  double t1 = op0 / op01;

  cl.pt = db * t1 + b0;
  cl.t0 = t0;
  cl.t1 = t1;
  return true;
}

void convex_cut(const vpt& scpol, vpt& dcpol, const Pt& pt0, const Pt& pt1) {
  int n = scpol.size();
  Pt v = pt1 - pt0;
  dcpol.clear();

  for (int i = 0; i < n; i++) {
    Pt cpt0 = scpol[i];
    double cr0 = v.cross(cpt0 - pt0);
    if (cr0 >= 0.0) dcpol.push_back(cpt0);
    
    Pt cpt1 = scpol[(i + 1) % n];
    double cr1 = v.cross(cpt1 - pt0);
    if (cr0 * cr1 < 0.0) {
      CL cl;
      cross_lines(pt0, pt1, cpt0, cpt1, cl);
      dcpol.push_back(cl.pt);
    }
  }
}

double calc_area(const vpt& cpol) {
  int nc = cpol.size();
  if (nc < 3) return 0.0;

  Pt pt0 = cpol[0];
  Pt v0 = cpol[1] - pt0;
  double area = 0.0;
  
  for (int i = 2; i < nc; i++) {
    Pt v1 = cpol[i] - pt0;
    area += v0.cross(v1);
    v0 = v1;
  }

  return area / 2;
}

/* main */

int main() {
  for (;;) {
    cin >> n >> m;
    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      cin >> pts[i].x >> pts[i].y;
      evs[i] = 0.0;
    }

    for (int i = 0; i < m; i++)
      cin >> bs[i].x >> bs[i].y >> bs[i].dx >> bs[i].dy >> bs[i].sc;

    vpt cpols[2];

    for (int k = 0; k < m; k++) {
      Ball& bk = bs[k];
      double totalarea = 4 * bk.dx * bk.dy;
      
      for (int i = 0; i < n; i++) {
	Pt& pti = pts[i];
	int cur = 0, nxt = 1;

	cpols[0].clear();
	cpols[0].push_back(Pt(bk.x - bk.dx, bk.y - bk.dy));
	cpols[0].push_back(Pt(bk.x + bk.dx, bk.y - bk.dy));
	cpols[0].push_back(Pt(bk.x + bk.dx, bk.y + bk.dy));
	cpols[0].push_back(Pt(bk.x - bk.dx, bk.y + bk.dy));

	for (int j = 0; j < n; j++) {
	  if (i == j) continue;

	  Pt& ptj = pts[j];
	  Pt pm = pti.mid(ptj);
	  Pt vij = ptj - pti;
	  Pt v(-vij.y, vij.x);

	  convex_cut(cpols[cur], cpols[nxt], pm - v, pm + v);
	  cur ^= 1;
	  nxt ^= 1;
	}	

	double area = calc_area(cpols[cur]);
	evs[i] += bk.sc * area / totalarea;
      }
    }

    double maxev = 0.0;
    for (int i = 0; i < n; i++)
      if (maxev < evs[i]) maxev = evs[i];

    printf("%.6lf\n", maxev);
  }

  return 0;
}