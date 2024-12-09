#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
struct Pt {
  int x, y;
};
Pt gen[100005];
Pt poly[100005];
int n, m;
static inline double value_of(double x, double y) {
  double ret = 0;
  for (int i = 0; i < n; ++i) {
    const double u = x - gen[i].x;
    const double v = y - gen[i].y;
    ret += u * u + v * v;
  }
  return ret;
}
static inline double value_of_x(double x) {
  double ret = 0;
  for (int i = 0; i < n; ++i) {
    const double u = x - gen[i].x;
    ret += u * u;
  }
  return ret;
}
static inline double value_of_y(double y) {
  double ret = 0;
  for (int i = 0; i < n; ++i) {
    const double v = y - gen[i].y;
    ret += v * v;
  }
  return ret;
}
static inline double find_one(int s, int t) {
  double ret = 1e30;
  double a = 0, b = 1;
  double dx = poly[t].x - poly[s].x;
  double dy = poly[t].y - poly[s].y;
  for (int i = 0; i < 60; ++i) {
    if (fabs(b - a) < 1e-8) break;
    const double d = b - a;
    double u = a + d / 3;
    double v = a + d * 2 / 3;
    double ans_u = value_of(poly[s].x + u * dx, poly[s].y + u * dy);
    double ans_v = value_of(poly[s].x + v * dx, poly[s].y + v * dy);
    if (ans_u < ret) ret = ans_u;
    if (ans_v < ret) ret = ans_v;
    if (ans_u > ans_v)
      a = u;
    else
      b = v;
  }
  double u = (a + b) * 0.5;
  double ans_u = value_of(poly[s].x + u * dx, poly[s].y + u * dy);
  if (ans_u < ret) ret = ans_u;
  return ret;
}
double find_x() {
  double a = -1000000, b = 1000000;
  for (int i = 0; i < 100; ++i) {
    if (fabs(b - a) < 1e-9) break;
    const double d = b - a;
    double u = a + d / 3;
    double v = a + d * 2 / 3;
    double ans_u = value_of_x(u);
    double ans_v = value_of_x(v);
    if (ans_u > ans_v)
      a = u;
    else
      b = v;
  }
  return (a + b) * 0.5;
}
double find_y() {
  double a = -1000000, b = 1000000;
  for (int i = 0; i < 100; ++i) {
    if (fabs(b - a) < 1e-9) break;
    const double d = b - a;
    double u = a + d / 3;
    double v = a + d * 2 / 3;
    double ans_u = value_of_y(u);
    double ans_v = value_of_y(v);
    if (ans_u > ans_v)
      a = u;
    else
      b = v;
  }
  return (a + b) * 0.5;
}
int test_in(double x, double y) {
  int flag = -2;
  for (int i = 0; i < m; ++i) {
    const double dx1 = poly[i].x - x;
    const double dy1 = poly[i].y - y;
    const double dx2 = poly[i + 1].x - x;
    const double dy2 = poly[i + 1].y - y;
    double f = dx1 * dy2 - dy1 * dx2;
    int t = 0;
    if (fabs(f) > 1e-6) {
      t = f > 0 ? 1 : -1;
    }
    if (flag == -2)
      flag = t;
    else if (t != 0 && t != flag)
      return 0;
  }
  return 1;
}
int main() {
  n = Rint();
  for (int i = (0); i < (n); ++i) gen[i].x = Rint(), gen[i].y = Rint();
  m = Rint();
  for (int i = (0); i < (m); ++i) poly[i].x = Rint(), poly[i].y = Rint();
  poly[m] = poly[0];
  int ref = -1;
  double ans = 1e30;
  for (int i = 0; i < m; ++i) {
    double value = value_of(poly[i].x, poly[i].y);
    if (value < ans) {
      ans = value, ref = i;
    }
  }
  for (int d = -3; d <= 3; ++d) {
    int now = ((ref + d) % m + m) % m;
    double value = find_one(now, (now + 1) % m);
    if (value < ans) ans = value;
  }
  const double x = find_x(), y = find_y();
  if (test_in(x, y)) {
    double temp = value_of(x, y);
    if (temp < ans) ans = temp;
  }
  printf("%.16f\n", ans);
  return 0;
}
