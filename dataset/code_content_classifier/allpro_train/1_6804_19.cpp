#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
};
const int MAXN = 100005;
const double eps = 1e-9;
Point pa[MAXN], ba[MAXN];
int d[MAXN], totd;
int n, m;
vector<pair<double, int> > v;
double sqr(double x) { return x * x; }
int Symbol(double a, double b) {
  if (fabs(a - b) < eps)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}
Point Travel(Point p, int dd) {
  while (dd > 0) {
    int rem = d[p.x] * m - p.y;
    if (rem > dd)
      p.y += dd, dd = 0;
    else
      dd -= rem, p.x = (p.x + 1) % n, p.y = 0;
  }
  return p;
}
void SolveQEq(long long d0, int dd, Point p0, Point p1, double tryd,
              int &overcnt) {
  Point rp0, rp1;
  double A, B, C, Ax, Bx, Ay, By;
  double l, r;
  rp0.x = pa[p0.x].x * m + ba[p0.x].x * p0.y;
  rp0.y = pa[p0.x].y * m + ba[p0.x].y * p0.y;
  rp1.x = pa[p1.x].x * m + ba[p1.x].x * p1.y;
  rp1.y = pa[p1.x].y * m + ba[p1.x].y * p1.y;
  Ax = ba[p0.x].x - ba[p1.x].x;
  Bx = rp0.x - rp1.x;
  Ay = ba[p0.x].y - ba[p1.x].y;
  By = rp0.y - rp1.y;
  A = sqr(Ax) + sqr(Ay);
  B = 2 * Ax * Bx + 2 * Ay * By;
  C = sqr(Bx) + sqr(By) - sqr(tryd * m);
  if (Symbol(A, 0) == 0) {
    if (Symbol(C, 0) > 0) return;
    l = 0;
    r = dd;
  } else {
    double delta = sqr(B) - 4 * A * C;
    if (delta >= 0) {
      l = (-B - sqrt(delta)) / (2 * A);
      r = (-B + sqrt(delta)) / (2 * A);
      l = max(l, 0.0);
      r = min(r, (double)dd);
      if (l > r) return;
    } else
      return;
  }
  l += d0;
  r += d0;
  overcnt += (int)(floor(r / totd) - floor(l / totd));
  l = l - floor(l / totd) * totd;
  r = r - floor(r / totd) * totd;
  v.push_back(make_pair(l, 1));
  v.push_back(make_pair(r, -1));
  return;
}
bool Check(double tryd) {
  Point p0, p1;
  long long d0 = 0;
  int overcnt = 0;
  v.clear();
  p0.x = 0;
  p0.y = 0;
  p1 = Travel(p0, totd);
  do {
    int rem0 = d[p0.x] * m - p0.y;
    int rem1 = d[p1.x] * m - p1.y;
    int dd = min(rem0, rem1);
    SolveQEq(d0, dd, p0, p1, tryd, overcnt);
    p0 = Travel(p0, dd);
    p1 = Travel(p1, dd);
    d0 += dd;
  } while (!(p0.x == 0 && p0.y == 0));
  if (overcnt >= m) return true;
  sort(v.begin(), v.end());
  for (auto &p : v) {
    overcnt += p.second;
    if (overcnt >= m) return true;
  }
  return false;
}
int main() {
  double ansl = 0, ansr = 3000;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d%d", &pa[i].x, &pa[i].y);
  pa[n] = pa[0];
  for (int i = 0; i < n; ++i) {
    d[i] = abs(pa[i].x - pa[i + 1].x) + abs(pa[i].y - pa[i + 1].y);
    totd += d[i];
    ba[i].x = Symbol(pa[i + 1].x, pa[i].x);
    ba[i].y = Symbol(pa[i + 1].y, pa[i].y);
  }
  while (ansr - ansl > eps) {
    double mid = (ansl + ansr) / 2;
    if (Check(mid))
      ansr = mid;
    else
      ansl = mid;
  }
  printf("%.9lf\n", ansr);
  return 0;
}
