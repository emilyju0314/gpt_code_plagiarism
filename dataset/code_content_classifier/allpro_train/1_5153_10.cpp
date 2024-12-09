#include <bits/stdc++.h>
#pragma warning(disable : 4786)
using namespace std;
struct Vector {
  double x, y;
  Vector(double x = 0, double y = 0) {
    this->x = x;
    this->y = y;
  }
  void scan() { cin >> x >> y; }
  void print() { cout << x << " " << y << endl; }
  bool isZero() { return (fabs(x) < 1e-10) && (fabs(y) < 1e-10); }
  double mag() { return sqrt(mag2()); }
  double mag2() { return ((x) * (x)) + ((y) * (y)); }
  void normalize() {
    double m = mag();
    x /= m;
    y /= m;
  }
  Vector unit() {
    Vector u(x, y);
    u.normalize();
    return u;
  }
};
double dotp(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double crossp(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator-(Vector a) { return Vector(-a.x, -a.y); }
Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
double operator*(Vector a, Vector b) { return crossp(a, b); }
Vector operator*(Vector a, double b) { return Vector(a.x * b, a.y * b); }
Vector operator*(double b, Vector a) { return Vector(a.x * b, a.y * b); }
Vector operator/(Vector a, double b) { return Vector(a.x / b, a.y / b); }
double angle(Vector a, Vector b) {
  double v = dotp(a, b) / (a.mag() * b.mag());
  v = ((v) < ((double)1) ? (v) : ((double)1));
  v = ((v) > ((double)-1) ? (v) : ((double)-1));
  return acos(v);
}
int Turn(Vector &V0, Vector &V1, Vector &V2) {
  double v = (V1 - V0) * (V2 - V0);
  if (fabs(v) < 1e-10) return 0;
  if (v > 0.0) return 1;
  return -1;
}
class LineSegment {
 public:
  Vector v0;
  Vector v1;
  LineSegment() {}
  LineSegment(const Vector &begin, const Vector &end) : v0(begin), v1(end) {}
  enum IntersectResult {
    PARALLEL,
    COINCIDENT,
    NOT_INTERESECTING,
    INTERESECTING
  };
  IntersectResult Intersect(const LineSegment &L, double &val) {
    double denom = ((L.v1.y - L.v0.y) * (v1.x - v0.x)) -
                   ((L.v1.x - L.v0.x) * (v1.y - v0.y));
    double nume_a = ((L.v1.x - L.v0.x) * (v0.y - L.v0.y)) -
                    ((L.v1.y - L.v0.y) * (v0.x - L.v0.x));
    double nume_b =
        ((v1.x - v0.x) * (v0.y - L.v0.y)) - ((v1.y - v0.y) * (v0.x - L.v0.x));
    if (denom == 0.0f) {
      if (nume_a == 0.0f && nume_b == 0.0f) {
        return COINCIDENT;
      }
      return PARALLEL;
    }
    double ua = nume_a / denom;
    double ub = nume_b / denom;
    if (ua >= 0.0f && ua <= 1.0f && ub >= 0.0f && ub <= 1.0f) {
      val = ua;
      return INTERESECTING;
    }
    return NOT_INTERESECTING;
  }
};
Vector T[104][3];
struct e {
  double st, en;
} E;
vector<e> Event;
stack<e> Stk;
bool cmp(e e1, e e2) { return e1.st < e2.st; }
int main() {
  int n, i, j, ii, jj, k;
  scanf("%d", &n);
  for (i = 0; i < (n); i++)
    for (j = 0; j < (3); j++) T[i][j].scan();
  vector<double> vd, vf;
  LineSegment L1, L2;
  double ans = 0, res;
  for (i = 0; i < (n); i++) {
    for (j = 0; j < (3); j++) {
      ((Event).clear());
      while (!Stk.empty()) Stk.pop();
      res = 0;
      L1.v0 = T[i][j];
      L1.v1 = T[i][(j + 1) % 3];
      for (ii = 0; ii < (n); ii++) {
        ((vd).clear());
        ((vf).clear());
        if (i == ii) continue;
        for (jj = 0; jj < (3); jj++) {
          L2.v0 = T[ii][jj];
          L2.v1 = T[ii][(jj + 1) % 3];
          double t0;
          if (L1.Intersect(L2, t0) == 3) {
            vd.push_back(t0);
          }
        }
        sort((vd).begin(), (vd).end());
        if (((int)(vd).size())) {
          vf.push_back(vd[0]);
          for (k = (1); k <= (((int)(vd).size()) - 1); k++) {
            if ((fabs(vd[k] - vd[k - 1]) < 1e-10)) continue;
            vf.push_back(vd[k]);
          }
        }
        if (((int)(vf).size()) <= 1) {
          set<int> Set;
          for (jj = 0; jj < (3); jj++) {
            Set.insert(Turn(T[ii][jj], T[ii][(jj + 1) % 3], T[i][j]));
          }
          if (((int)(Set).size()) == 1) vf.push_back(0);
          ((Set).clear());
          for (jj = 0; jj < (3); jj++) {
            Set.insert(Turn(T[ii][jj], T[ii][(jj + 1) % 3], T[i][(j + 1) % 3]));
          }
          if (((int)(Set).size()) == 1) vf.push_back(1);
        }
        sort((vf).begin(), (vf).end());
        if (((int)(vf).size()) != 2) continue;
        if (((int)(vf).size())) {
          E.st = vf[0];
          E.en = vf[1];
          Event.push_back(E);
        }
      }
      if (((int)(Event).size())) {
        sort((Event).begin(), (Event).end(), cmp);
        double t1 = Event[0].en - Event[0].st;
        int last = 0;
        for (k = (1); k <= (((int)(Event).size()) - 1); k++) {
          if (Event[k].st < Event[last].en) {
            if (Event[k].en > Event[last].en) {
              t1 += Event[k].en - Event[last].en;
              last = k;
            }
          } else {
            last = k;
            t1 += Event[k].en - Event[k].st;
          }
        }
        res += t1;
      }
      ans += (1 - res) * (T[i][j] - T[i][(j + 1) % 3]).mag();
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
