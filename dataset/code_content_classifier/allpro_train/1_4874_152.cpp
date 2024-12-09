#include <bits/stdc++.h>
using namespace std;
long long n, l, v1, v2;
vector<long long> a;
vector<double> p;
int main() {
  cin >> n >> l >> v1 >> v2;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a.push_back(a[i] + 2 * l);
  a.push_back(a[0] + 4 * l);
  p.assign(n + 1, 0.0);
  double d = (double)v2 / (v1 + v2) * l;
  int L = 0;
  int R = 0;
  for (int i = 0; i <= n; i++) {
    long long x = a[i] - a[0];
    if (x * (v1 + v2) > l * v2) {
      R = i;
      break;
    }
  }
  bool start = true;
  while (1) {
    if (L == n && start) break;
    double dist = 0.0;
    if (start) {
      L++;
      if (L != R && a[L] * (v1 + v2) <= a[R] * (v1 + v2) - l * v2) {
        dist = a[L] - a[L - 1];
        p[R - L] += dist / 2 / l;
        if (a[L] * (v1 + v2) == a[R] * (v1 + v2) - l * v2) R++;
      } else {
        dist = a[R] - (a[L - 1] + d);
        start = false;
        p[R - L] += dist / 2 / l;
        R++;
      }
    } else {
      if (a[L] * (v1 + v2) + l * v2 <= a[R] * (v1 + v2)) {
        dist = a[L] - (a[R - 1] - d);
        start = true;
        p[R - L] += dist / 2 / l;
        if (a[L] * (v1 + v2) + l * v2 == a[R] * (v1 + v2)) R++;
      } else {
        dist = a[R] - a[R - 1];
        p[R - L] += dist / 2 / l;
        R++;
      }
    }
  }
  for (int i = 0; i <= n; i++) printf("%.10lf\n", p[i]);
  return 0;
}
