#include <bits/stdc++.h>
using namespace std;
int dcmp(double x) { return (x > 1e-8) - (x < -1e-8); }
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator-(const point& b) const { return point(x - b.x, y - b.y); }
  double len() { return sqrt(x * x + y * y); }
  double angle() { return atan2(y, x); }
  void input() { scanf("%lf%lf", &x, &y); }
} O[20005];
int R[20005], d;
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
int CirCrossCir(point c1, double r1, point c2, double r2, point& k1,
                point& k2) {
  double mx = c2.x - c1.x, sx = c2.x + c1.x, mx2 = mx * mx;
  double my = c2.y - c1.y, sy = c2.y + c1.y, my2 = my * my;
  double sq = mx2 + my2,
         d = -(sq - ((r1 - r2) * (r1 - r2))) * (sq - ((r1 + r2) * (r1 + r2)));
  if (dcmp(d) < 0) return 0;
  if (dcmp(d) == 0)
    d = 0;
  else
    d = sqrt(d);
  double x = mx * ((r1 + r2) * (r1 - r2) + mx * sx) + sx * my2;
  double y = my * ((r1 + r2) * (r1 - r2) + my * sy) + sy * mx2;
  double dx = mx * d, dy = my * d;
  sq *= 2;
  k1.x = (x - dy) / sq;
  k1.y = (y + dx) / sq;
  k2.x = (x + dy) / sq;
  k2.y = (y - dx) / sq;
  if (d > 1e-8)
    return 2;
  else
    return 1;
}
struct smx {
  double ang;
  int val, id;
  bool operator<(const smx& b) const {
    return dcmp(ang - b.ang) < 0 || dcmp(ang - b.ang) == 0 && val > b.val;
  }
} s[20005 * 50];
bool in[20005 * 50];
int init(int n) {
  int m = 0;
  point k1, k2;
  for (int i = 1; i <= n; ++i) {
    int l = ceil((O[i].len() - R[i]) / d - 1e-8);
    int r = floor((O[i].len() + R[i]) / d + 1e-8);
    for (int j = l; j <= r; ++j) {
      int k = CirCrossCir(O[i], R[i], point(0, 0), d * j, k1, k2);
      if (k == 0) continue;
      if (cross(k1, O[i]) < 0) swap(k1, k2);
      s[m].ang = k1.angle();
      s[m].val = 1;
      s[m].id = m / 2;
      m++;
      s[m].ang = k2.angle();
      s[m].val = -1;
      s[m].id = m / 2;
      m++;
    }
  }
  return m;
}
int solve(int n) {
  int m = init(n), ret = 0, cur = 0;
  sort(s, s + m);
  for (int j = 0; j < 2 * m; ++j) {
    int i = j < m ? j : j - m;
    if (s[i].val == 1)
      ++cur, in[s[i].id] = true;
    else if (in[s[i].id])
      --cur, in[s[i].id] = false;
    ret = max(ret, cur);
  }
  return ret;
}
int main() {
  int n;
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    O[i].input();
    scanf("%d", R + i);
  }
  printf("%d\n", solve(n));
  return 0;
}
