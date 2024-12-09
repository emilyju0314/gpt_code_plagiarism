#include <bits/stdc++.h>
using namespace std;
int n, s;
int x[100100], y[100100], p[100100];
int check(double r) {
  int cnt = s;
  for (int i = 0; i < n; i++)
    if (x[i] * x[i] + y[i] * y[i] <= r * r) cnt += p[i];
  if (cnt >= 1000000) return 1;
  return 0;
}
int main() {
  while (scanf("%d%d", &n, &s) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d%d%d", x + i, y + i, p + i);
    double l = 0, r = 1000000, mid;
    while (l + 1e-8 < r) {
      mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    if (l > 100000)
      printf("-1\n");
    else
      printf("%.6lf\n", l);
  }
}
