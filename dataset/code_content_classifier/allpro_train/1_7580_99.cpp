#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n;
double a[100500], k;
bool can(double m) {
  double l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < m) {
      l += m - a[i];
    } else
      r += a[i] - m;
  }
  r = r - r * k;
  return (r + eps > l);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  k /= 100.0;
  double l = 0.0, r = 1000.0;
  for (int i = 0; i < 100; i++) {
    double mid = (l + r) / 2.0;
    if (can(mid)) {
      l = mid;
    } else
      r = mid;
  }
  printf("%.7lf", (l + r) / 2.0);
  return 0;
}
