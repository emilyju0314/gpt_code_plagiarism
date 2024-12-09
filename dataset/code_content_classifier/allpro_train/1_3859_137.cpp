#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;
const double EPS = 1e-10;
struct PT {
  long double x, y, z;
  PT() {}
  PT(double a, double b, double c) : x(a), y(b), z(c) {}
  PT operator+(const PT &b) const { return PT(x + b.x, y + b.y, z + b.z); }
  PT operator-(const PT &b) const { return PT(x - b.x, y - b.y, z - b.z); }
  PT operator/(const double &b) const { return PT(x / b, y / b, z / b); }
  PT operator*(const double &b) const { return PT(x * b, y * b, z * b); }
  double operator*(const PT &b) const { return x * b.x + y * b.y + z * b.z; }
  double len() { return sqrt(x * x + y * y + z * z); }
} pt[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  double a, b, c;
  for (int i = 0; i <= n; i++) {
    scanf("%lf%lf%lf", &a, &b, &c);
    pt[i] = PT(a, b, c);
  }
  double vp, vs;
  scanf("%lf%lf", &vp, &vs);
  PT p;
  scanf("%lf%lf%lf", &a, &b, &c);
  p = PT(a, b, c);
  double curT = 0;
  for (int i = 0; i < n; i++) {
    PT vs2 = ((pt[i + 1] - pt[i]) * vs) / (pt[i + 1] - pt[i]).len();
    a = vs * vs - vp * vp;
    b = 2 * ((pt[i] - p) * vs2 - curT * vp * vp);
    c = (pt[i] - p) * (pt[i] - p) - curT * curT * vp * vp;
    double t1 =
        fabs(a) > EPS ? (-sqrt(b * b - 4 * a * c) - b) / (2 * a) : -c / b;
    double t2 =
        fabs(a) > EPS ? (sqrt(b * b - 4 * a * c) - b) / (2 * a) : -c / b;
    if (t1 > t2) swap(t1, t2);
    (void)0;
    if (-EPS <= t1 && t1 <= (pt[i + 1] - pt[i]).len() / vs + EPS) {
      puts("YES");
      PT x = pt[i] + (vs2 * t1);
      printf("%f\n", (double)(x - p).len() / vp);
      (void)0;
      printf("%.10f %.10f %.10f\n", (double)x.x, (double)x.y, (double)x.z);
      return 0;
    }
    if (-EPS <= t2 && t2 <= (pt[i + 1] - pt[i]).len() / vs + EPS) {
      puts("YES");
      PT x = pt[i] + (vs2 * t2);
      printf("%f\n", (double)(x - p).len() / vp);
      (void)0;
      printf("%.10f %.10f %.10f\n", (double)x.x, (double)x.y, (double)x.z);
      return 0;
    }
    curT += (pt[i + 1] - pt[i]).len() / vs;
  }
  puts("NO");
  return 0;
}
