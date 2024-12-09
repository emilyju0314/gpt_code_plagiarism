#include <bits/stdc++.h>
using namespace std;
const double lif = 1e-8;
double f, h, ans;
int x[1011], n;
int judge(double x) {
  if (x > lif)
    return 1;
  else if (x < -lif)
    return -1;
  else
    return 0;
}
double calc(double x1, double x2) {
  double S = 0, x3, x4;
  x3 = x1 * (f + h) / (f - h);
  x4 = x2 * (f + h) / (f - h);
  if (judge(x1 - x4) == -1 && judge(x3 - x2) == -1) return (x1 + x3) * h;
  if (judge(x1 - x4) == 1 && judge(x3 - x2) == 1) return (x2 + x4) * h;
  if (judge((x1 + x2) - (x3 + x4)) == 1) swap(x1, x4), swap(x2, x3);
  S = (x1 + x2) * h;
  if (judge(x4 - x1) == 1 && judge(x3 - x2) == 1) {
    double a = (x4 - x1), b = (x3 - x2);
    double h1 = h * b / (a + b), h2 = h - h1;
    S += ((a + b) * h - (b * h1 + a * h2)) * 0.5;
  }
  return S;
}
double calc(int x1, int x2) { return calc(double(x1), double(x2)); }
int main() {
  scanf("%d%lf%lf", &n, &h, &f);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i + i - 1], &x[i + i]);
  sort(x + 1, x + n + n + 1);
  double a, b;
  for (int i = 1; i <= n; ++i) {
    a = x[i + i] - x[i + i - 1];
    b = a * (f + h) / (f - h);
    ans += (a + b) * h * 2;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      ans -= calc(x[i + i], x[j + j]);
      ans -= calc(x[i + i - 1], x[j + j - 1]);
      ans += calc(x[i + i], x[j + j - 1]);
      ans += calc(x[i + i - 1], x[j + j]);
    }
  printf("%.10lf\n", ans);
  return 0;
}
