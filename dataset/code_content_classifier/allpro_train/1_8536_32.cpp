#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1);
struct pt {
  double x, y;
  pt() {}
  pt(double x, double y) : x(x), y(y) {}
  pt operator+(const pt& p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
  pt operator*(double c) const { return pt(x * c, y * c); }
  pt operator/(double c) const { return pt(x / c, y / c); }
};
ostream& operator<<(ostream& ss, pt p) {
  return (ss << "(" << p.x << "," << p.y << ")");
}
double dot(pt p, pt q) { return p.x * q.x + p.y * q.y; }
double norm(pt p) { return sqrt(dot(p, p)); }
double dist2(pt p, pt q) { return dot(p - q, p - q); }
double cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double angle(pt p) {
  double res = acos(p.x / norm(p));
  if (p.y > 0)
    return res;
  else
    return 2 * PI - res;
}
int n[2];
double ang[2][1100];
double d[2][1100];
pt a[2][1100];
struct ev {
  double ang;
  int op;
  int col;
  ev(double ang, int op, int col) : ang(ang), op(op), col(col) {}
};
int cmp(const ev& e1, const ev& e2) { return e1.ang < e2.ang; }
vector<ev> v;
int cnt[2];
double normal(double z) {
  if (z < 0) z += 2 * PI;
  if (z >= 2 * PI) z -= 2 * PI;
  return z;
}
int go(double r, int c0) {
  v.clear();
  cnt[0] = cnt[1] = 0;
  for (int(col) = (0); (col) < (2); (col)++) {
    for (int(i) = (0); (i) < (n[col]); (i)++)
      if (d[col][i] <= 2 * r) {
        double z = acos(d[col][i] / (2 * r));
        double a0 = normal(ang[col][i] - z);
        double a1 = normal(ang[col][i] + z);
        if (a0 > a1) cnt[col]++;
        v.push_back(ev(a0, 0, col));
        v.push_back(ev(a1, 1, col));
      }
  }
  sort((v).begin(), (v).end(), cmp);
  for (ev e : v) {
    if (e.op == 0)
      cnt[e.col]++;
    else
      cnt[e.col]--;
    if ((cnt[0] || (1 - c0)) && !cnt[1]) return 1;
  }
  return 0;
}
const double INF = 1e10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n[0] >> n[1];
  for (int(col) = (0); (col) < (2); (col)++)
    for (int(i) = (0); (i) < (n[col]); (i)++) cin >> a[col][i].x >> a[col][i].y;
  double ans = 0;
  for (int(i) = (0); (i) < (n[0]); (i)++) {
    double curr = INF;
    for (int(j) = (0); (j) < (n[1]); (j)++)
      curr = min(curr, norm(a[0][i] - a[1][j]));
    ans = max(ans, curr);
  }
  ans *= (1 + 1e-5);
  for (int(z) = (0); (z) < (2); (z)++) {
    for (int(c0) = (0); (c0) < (2); (c0)++) {
      for (int(j) = (0); (j) < (n[c0]); (j)++) {
        double lo = INF;
        for (int(col) = (0); (col) < (2); (col)++)
          for (int(i) = (0); (i) < (n[col]); (i)++)
            if (col != c0 || i != j) {
              ang[col][i] = angle(a[col][i] - a[c0][j]);
              d[col][i] = norm(a[col][i] - a[c0][j]);
              if (c0 && !col) lo = min(lo, d[col][i] / 2);
            }
        lo = max(lo * (1 + 1e-5), ans);
        d[c0][j] = INF * INF;
        if (!go(lo, c0)) continue;
        double hi = 2 * lo;
        while (go(hi, c0)) {
          hi *= 2;
          lo *= 2;
          if (hi > INF) {
            cout << -1 << endl;
            return 0;
          }
        }
        while (abs(hi - lo) / max(1.0, lo) >= 1e-4) {
          double r = (hi + lo) / 2;
          if (go(r, c0))
            lo = r;
          else
            hi = r;
        }
        ans = max(ans, lo);
      }
    }
  }
  cout << setprecision(9) << fixed << ans << endl;
  return 0;
}
