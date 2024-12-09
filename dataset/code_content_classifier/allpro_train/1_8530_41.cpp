#include <bits/stdc++.h>
using namespace std;
double p, q, a[100101], b[100101];
int n;
double f(double x) {
  int i, j, k;
  double y = 1;
  for (i = 1; i <= n; i++) y = min(y, (1 - x * a[i]) / b[i]);
  return p * x + q * y;
}
int main() {
  int i, j, k;
  cin >> n >> p >> q;
  double maxx = 1;
  for (i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    maxx = min(maxx, 1.0 / a[i]);
  }
  double l = 0, r = maxx;
  for (i = 1; i <= 50; i++) {
    double ll = (r - l) / 3 + l, rr = ll + (r - l) / 3;
    if (f(ll) > f(rr))
      r = rr;
    else
      l = ll;
  }
  printf("%.10lf\n", f((l + r) / 2));
  return 0;
}
