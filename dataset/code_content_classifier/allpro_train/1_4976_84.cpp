#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
} a[100500];
int n;
long long det(int a, int b, int c, int d) { return 1ll * a * d - 1ll * b * c; }
int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
pair<long long, int> f(int i, int j) {
  int lgcd = abs(gcd(a[j].x - a[i].x, a[i].y - a[j].y));
  long long d = det(a[i].x, a[i].y, a[j].x, a[j].y) - lgcd;
  return make_pair(d, lgcd);
}
double pw2[1024];
double prob(int k, int n) {
  if (n - k >= 1024 || k > n) return 0;
  double e = k < 1024 ? 1 / pw2[k] : 0;
  return (1 - e) / (pw2[n - k] - e * (1 + n + n * (n - 1) / 2));
}
long long F[200500];
int main() {
  pw2[0] = 1;
  for (int _n(1024), k(1); k < _n; k++) pw2[k] = pw2[k - 1] * 2;
  scanf("%d", &n);
  for (int _n(n), i(0); i < _n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  a[n] = a[0];
  for (int _n(2 * n), j(0); j < _n; j++) {
    int i = j < n ? j : j - n;
    F[j + 1] = F[j] + f(i, i + 1).first;
  }
  assert(F[n] % 2 == 0);
  double res = F[n] / 2 + 1;
  int m = min(n - 1, 100);
  for (int _n(n), i(0); i < _n; i++) {
    for (int _n(m), k(1); k < _n; k++) {
      int j = i + k;
      auto val = f(j < n ? j : j - n, i);
      long long s = F[j] - F[i] + val.first;
      assert(s % 2 == 0);
      s = s / 2 + val.second;
      double pr = prob(n - 1 - k, n);
      res -= s * pr;
    }
  }
  printf("%.12lf\n", res);
  return 0;
}
