#include <bits/stdc++.h>
using namespace std;
const int MAX = 100032;
const double EPS = 1e-10;
struct point {
  long long x, y, id;
  void print() { cout << x << " " << y << endl; }
};
point P[MAX], C[MAX], P0;
inline long long triArea2(const point &a, const point &b, const point &c) {
  return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}
inline long long sqDist(const point &a, const point &b) {
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double dist(const point &a, const point &b) {
  return hypot((double)(a.x - b.x), (double)(a.y - b.y));
}
inline bool comp(const point &a, const point &b) {
  long long d = triArea2(P0, a, b);
  if (d < 0) return false;
  if (!d && sqDist(P0, a) > sqDist(P0, b)) return false;
  return true;
}
inline bool normal(const point &a, const point &b) {
  return ((a.x == b.x) ? a.y < b.y : a.x < b.x);
}
inline bool issame(const point &a, const point &b) {
  return (a.x == b.x && a.y == b.y);
}
inline void makeUnique(int &np) {
  sort(P, P + np, normal);
  np = unique(P, P + np, issame) - P;
}
void convexHull(int &np, int &nc) {
  int i, j, pos = 0;
  for (i = 1; i < np; i++)
    if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x)) pos = i;
  swap(P[0], P[pos]);
  P0 = P[0];
  sort(&P[1], &P[np], comp);
  for (i = 0; i < 3; i++) C[i] = P[i];
  for (i = j = 3; i < np; i++) {
    while (triArea2(C[j - 2], C[j - 1], P[i]) < 0) j--;
    C[j++] = P[i];
  }
  nc = j;
}
void compress(int &nc) {
  int i, j;
  long long d;
  for (i = j = 1; i < nc; i++) {
    d = triArea2(C[j - 1], C[i], C[i + 1]);
    if (d || (!d && C[j - 1].id == C[i + 1].id)) C[j++] = C[i];
  }
  nc = j;
}
long long val(long long p, long long q, point r) { return r.x * q - r.y * p; }
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  long long mxa, mxb;
  mxa = mxb = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> P[i].x >> P[i].y;
    mxa = max(mxa, P[i].x);
    mxb = max(mxb, P[i].y);
  }
  P[n].x = mxa, P[n++].y = 0;
  P[n].x = 0, P[n++].y = mxb;
  P[n].x = 0, P[n++].y = 0;
  for (int i = 0; i < n; i++) P[i].id = i + 1;
  makeUnique(n);
  int nc;
  convexHull(n, nc);
  C[nc] = C[0];
  point zr;
  zr.x = zr.y = 0;
  double ax;
  for (int i = 0; i < nc; i++) {
    if (issame(C[i], zr) || issame(C[i + 1], zr)) continue;
    long long x = val(p, q, C[i]);
    long long y = val(p, q, C[i + 1]);
    if (x == 0) {
      ax = C[i].x;
      break;
    }
    if (y == 0) {
      ax = C[i + 1].x;
      break;
    }
    if (x > 0 && y > 0) {
      continue;
    }
    if (x < 0 && y < 0) continue;
    double x1, y1, x2, y2;
    x1 = C[i].x, y1 = C[i].y, x2 = C[i + 1].x, y2 = C[i + 1].y;
    double t = (y2 * p - x2 * q) / ((x1 - x2) * q - (y1 - y2) * p);
    ax = x1 * t + (1 - t) * x2;
  }
  double ans = p / ax;
  printf("%.10f\n", ans);
  return 0;
}
