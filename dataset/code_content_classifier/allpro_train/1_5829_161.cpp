#include <bits/stdc++.h>
using namespace std;
int n, a[55], p;
double f[55][55], g[55];
void run() {
  double ans = 0;
  for (int i = 1; i <= n; i++) g[i] = 1. / i;
  for (int i = 1; i <= n; i++)
    if (a[i] <= p) {
      memset(f, 0, sizeof(f));
      f[0][0] = 1. / n;
      int m = p - a[i];
      int c = 0;
      for (int j = 1; j <= n; j++)
        if (i != j) {
          c++;
          for (int t = m - a[j]; t >= 0; t--) {
            for (int k = 0; k < c; k++) {
              f[k + 1][t + a[j]] += f[k][t] * (k + 1) / (n - 1 - k);
            }
          }
        }
      for (int j = 0; j <= n; j++)
        for (int k = 0; k <= m; k++) ans += f[j][k];
    }
  printf("%.12lf\n", ans);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%d", &p);
  run();
  return 0;
}
