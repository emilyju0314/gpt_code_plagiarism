#include <bits/stdc++.h>
using namespace std;
int n, from, xxx, yyy, k;
int xx[100010];
double getmin(double x, double y) {
  if (x < y) return x;
  return y;
}
double getabs(double x) {
  if (x > 0) return x;
  return -x;
}
double dist(double x) {
  return sqrt(1.0 * (xxx - x) * (xxx - x) + (long long)yyy * yyy);
}
double calc1(int l, int r) {
  if (l > r) return 0;
  return getmin(getabs(xx[l] - from) + dist(xx[r]) + xx[r] - xx[l],
                getabs(xx[r] - from) + dist(xx[l]) + xx[r] - xx[l]);
}
double calc2(int l, int r) {
  if (l > r) return 0;
  return getmin(dist(xx[r]) + xx[r] - xx[l], dist(xx[l]) + xx[r] - xx[l]);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &xx[i]);
  scanf("%d%d", &xxx, &yyy);
  if (k == n + 1) {
    sort(xx + 1, xx + n + 1);
    printf("%.10lf\n", getmin(dist(xx[1]), dist(xx[n])) + xx[n] - xx[1]);
    return 0;
  }
  if (n == 1) {
    printf("%.10f\n", dist(xx[1]));
    return 0;
  }
  from = xx[k];
  sort(xx + 1, xx + n + 1);
  double ans = 1e20;
  if (from == xx[1]) {
    ans = getmin(ans, dist(xx[1]) + dist(xx[n]) + xx[n] - xx[2]);
    ans = getmin(ans, dist(xx[n]) + xx[n] - xx[1]);
    for (int i = 1; i < n; i++)
      ans = getmin(ans, calc2(1, i) + calc2(i + 1, n));
    printf("%.10lf\n", ans);
    return 0;
  }
  if (from == xx[n]) {
    ans = getmin(ans, dist(xx[1]) + dist(xx[n]) + xx[n - 1] - xx[1]);
    ans = getmin(ans, dist(xx[1]) + xx[n] - xx[1]);
    for (int i = 1; i < n; i++)
      ans = getmin(ans, calc2(1, i) + calc2(i + 1, n));
    printf("%.10lf\n", ans);
    return 0;
  }
  ans = calc1(1, n);
  for (int i = 1; i <= n; i++) {
    if (i != 1) ans = getmin(ans, calc1(1, i - 1) + calc2(i, n));
    if (i != n) ans = getmin(ans, calc1(i + 1, n) + calc2(1, i));
  }
  printf("%.10lf\n", ans);
}
