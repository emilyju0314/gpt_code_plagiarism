#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, x[200000], y[200000], l[200000];
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &y[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &l[i]);
  double Min = 1e18, nn = -1, mm = -1;
  for (int j = 0; j < m; ++j) {
    double t = l[j];
    double yy = 1.0 * y[j] * a / b;
    int ind = lower_bound(x, x + n, yy) - x;
    for (int i = ind - 1; i <= ind; ++i)
      if (i >= 0 && i < n) {
        double second =
            sqrt(1.0 * a * a + 1.0 * x[i] * x[i]) +
            sqrt(1.0 * (a - b) * (a - b) + 1.0 * (x[i] - y[j]) * (x[i] - y[j]));
        if (Min > second + t + 1e-8) {
          Min = second + t;
          nn = i + 1, mm = j + 1;
        }
      }
  }
  cout << nn << ' ' << mm;
  return 0;
}
