#include <iostream>
#include <cmath>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
using namespace std;
typedef long long ll;

struct Point { double x, y, z; };
struct Line { Point p, q; };

int N, Q;
ll R[50], L[50];
Point P[50];
Line C[50];

double distance(Line l, Point p) {
  double x0 = p.x, y0 = p.y, z0 = p.z;
  double x1 = l.p.x, y1 = l.p.y, z1 = l.p.z;
  double x2 = l.q.x, y2 = l.q.y, z2 = l.q.z;
  double a = x2 - x1;
  double b = y2 - y1;
  double c = z2 - z1;
  double a2 = a * a;
  double b2 = b * b;
  double c2 = c * c;
  double r2 = a2 + b2 + c2;
  double t2 = -(a * (x1 - x0) + b * (y1 - y0) + c * (z1 - z0));
  if(t2 < 0) return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0));
  if(t2 > r2) return sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0) + (z2 - z0) * (z2 - z0));
  double fx = b * (z1 - z0) - c * (y1 - y0);
  double fy = c * (x1 - x0) - a * (z1 - z0);
  double fz = a * (y1 - y0) - b * (x1 - x0);
  double f2 = fx * fx + fy * fy + fz * fz;
  return sqrt(f2 / r2);
}

int main(void) {
  cin >> N >> Q;
  REP(i, 0, N) cin >> P[i].x >> P[i].y >> P[i].z >> R[i] >> L[i];
  REP(i, 0, Q) cin >> C[i].p.x >> C[i].p.y >> C[i].p.z >> C[i].q.x >> C[i].q.y >> C[i].q.z;

  REP(i, 0, Q) {
    ll ans = 0;
    REP(j, 0, N) if(distance(C[i], P[j]) <= R[j]) ans += L[j];
    cout << ans << endl;
  }

  return 0;
}