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

const double DINF = 1e70;

/* typedef */

typedef pair<double,int> pdi;
typedef vector<pdi> vpdi;

template <typename T>
struct Pt3D {
  T x, y, z;

  Pt3D() {}
  Pt3D(T _x, T _y, T _z) { x = _x; y = _y; z = _z; }

  bool operator==(const Pt3D<T>& pt) const {
    return x == pt.x && y == pt.y && z == pt.z;
  }

  bool operator<(const Pt3D<T>& pt) const {
    return x < pt.x || (x == pt.x && (y < pt.y || (y == pt.y && z < pt.z)));
  }
  
  Pt3D<T> operator+(const Pt3D<T>& pt) const {
    return Pt3D<T>(x + pt.x, y + pt.y, z + pt.z);
  }

  Pt3D<T> operator-(const Pt3D<T>& pt) const {
    return Pt3D<T>(x - pt.x, y - pt.y, z - pt.z);
  }
  
  Pt3D<T> operator-() const { return Pt3D<T>(-x, -y, -z); }
  Pt3D<T> operator*(const T& t) const { return Pt3D<T>(x * t, y * t, z * t); }
  Pt3D<T> operator/(const T& t) const { return Pt3D<T>(x / t, y / t, z / t); }

  T dot(const Pt3D<T>& v) const { return x * v.x + y * v.y + z * v.z; }

  Pt3D<T> cross(const Pt3D<T>& v) const {
    return Pt3D<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
  }

  T d2() const { return x * x + y * y + z * z; }
  double d() const { return sqrt(d2()); }
  Pt3D<T> normalize() const { return *this / d(); }

  void print(string format) {
    printf(("(" + format + ", " + format + ", " + format + ")\n").c_str(),
           x, y, z);
  }
  void print() { print("%.6lf"); }
};

typedef Pt3D<double> pt3d;

struct Line {
  pt3d p0, p1, v;
};

/* global variables */

int n;
pt3d st, gl;
Line lines[MAX_N];
double dls[MAX_N][MAX_N], dists[MAX_N];

/* subroutines */

bool on_line(const pt3d& p0, const Line& l0) {
  return (p0 - l0.p0).cross(l0.v).d2() == 0.0;
}

double det3(const pt3d& v0, const pt3d& v1, const pt3d& v2) {
  return
    v0.x * v1.y * v2.z + v0.y * v1.z * v2.x + v0.z * v1.x * v2.y
    - v0.z * v1.y * v2.x - v0.y * v1.x * v2.z - v0.x * v1.z * v2.y;
}

double dist_lines(const Line& l0, const Line& l1) {
  pt3d v00 = l1.p0 - l0.p0;
  pt3d v01 = l1.p1 - l0.p0;

  if (det3(l0.v, v00, v01) == 0.0) {	// on plane
    if (l0.v.cross(l1.v).d2() > 0.0) return 0.0; // not parallel -> cross
    return v00.cross(v01).d() / l1.v.d(); // parallel
  }

  // not on plane
  pt3d nv = l0.v.cross(l1.v).normalize();
  return abs(v00.dot(nv));
}

/* main */

int main() {
  for (;;) {
    cin >> n;
    if (n == 0) break;

    cin >> st.x >> st.y >> st.z;
    cin >> gl.x >> gl.y >> gl.z;

    for (int i = 0; i < n; i++) {
      cin >> lines[i].p0.x >> lines[i].p0.y >> lines[i].p0.z
	  >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p1.z;
      lines[i].v = lines[i].p1 - lines[i].p0;
    }

    int sti = -1, gli = -1;

    for (int i = 0; i < n; i++) {
      if (sti < 0 && on_line(st, lines[i])) sti = i;
      if (gli < 0 && on_line(gl, lines[i])) gli = i;
    }
    //printf("sti=%d, gli=%d\n", sti, gli);

    for (int i = 0; i < n; i++) {
      dists[i] = DINF;
      dls[i][i] = 0.0;
      for (int j = i + 1; j < n; j++)
	dls[i][j] = dls[j][i] = dist_lines(lines[i], lines[j]);
    }

    priority_queue<pdi,vpdi,greater<pdi> > q;
    q.push(pdi(0.0, sti));
    dists[sti] = 0.0;

    while (! q.empty()) {
      pdi u = q.top();
      q.pop();

      double ud = u.first;
      int ui = u.second;
      if (ud != dists[ui]) continue;
      if (ui == gli) break;

      for (int vi = 0; vi < n; vi++) {
	if (ui == vi) continue;

	double vd = ud + dls[ui][vi];
	if (dists[vi] > vd) {
	  dists[vi] = vd;
	  q.push(pdi(vd, vi));
	}
      }
    }

    printf("%.3lf\n", dists[gli]);
  }

  return 0;
}