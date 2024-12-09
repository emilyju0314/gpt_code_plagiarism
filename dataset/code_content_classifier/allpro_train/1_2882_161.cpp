#include <bits/stdc++.h>
using namespace std;
int n, m, p[20005], q[20005], a, b;
int main() {
  scanf("%d", &n);
  int Max = 0;
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    if (Max < x) Max = x;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  scanf("%d", &m);
  long long P = 0, Q = 1;
  for (int i = 1; i <= m; ++i) scanf("%d", &q[i]);
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int k1 = b * p[i], k2 = b * p[i] + a * q[j];
      if (Q * k1 > P * k2) P = k1, Q = k2;
    }
  double x = sqrt(1.0 * P / Q) * Max;
  printf("%.9lf\n", x);
  return 0;
}
