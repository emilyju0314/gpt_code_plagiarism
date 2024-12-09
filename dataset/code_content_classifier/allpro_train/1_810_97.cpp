#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:600000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "d";
const int NMAX = 101010;
const int XMAX = 2001010;
int n, x[NMAX], y[NMAX];
int l[XMAX], r[XMAX], zn[XMAX];
void update(int x1, int qqqqqqq, int x2, int y2) {
  if (x1 == x2) {
    l[x1] = min(l[x1], min(qqqqqqq, y2));
    r[x1] = max(r[x1], max(qqqqqqq, y2));
    return;
  }
  if (x1 > x2) {
    swap(x1, x2);
    swap(qqqqqqq, y2);
  }
  for (int i = x1; i <= x2; ++i) {
    int now;
    now = qqqqqqq + (double)(i - x1) * (y2 - qqqqqqq) / (x2 - x1) - 1e-7 + 1;
    l[i] = min(l[i], now);
    now = qqqqqqq + (double)(i - x1) * (y2 - qqqqqqq) / (x2 - x1) + 1e-7;
    r[i] = max(r[i], now);
  }
}
double solve() {
  x[n] = x[0], y[n] = y[0];
  for (int i = 0; i < (int)XMAX; i++) l[i] = inf, r[i] = -inf;
  for (int i = 0; i < (int)n; i++) update(x[i], y[i], x[i + 1], y[i + 1]);
  for (int i = 0; i < (int)XMAX; i++) zn[i] = max(0, r[i] - l[i] + 1);
  double ans = 0, now = 0, cnt = 0, dist = 0;
  for (int i = 0; i < (int)XMAX; i++) {
    ans += zn[i] * now;
    cnt += zn[i];
    now += 2 * dist + cnt;
    dist += cnt;
  }
  return ans / (cnt * (cnt - 1) / 2);
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; i++) scanf("%d%d", &x[i], &y[i]);
  int xmin = 0, ymin = 0;
  for (int i = 0; i < (int)n; i++) {
    xmin = min(xmin, x[i]);
    ymin = min(ymin, y[i]);
  }
  for (int i = 0; i < (int)n; i++) {
    x[i] -= xmin;
    y[i] -= ymin;
  }
  double ans = solve();
  for (int i = 0; i < (int)n; i++) swap(x[i], y[i]);
  ans += solve();
  printf("%.10lf\n", ans / 2);
  return 0;
}
