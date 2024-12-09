#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int MAX = 1e5 + 9;
int n;
complex<double> a[MAX], z;
double ans = 1e18;
double cross(complex<double> a, complex<double> b) {
  return a.real() * b.imag() - b.real() * a.imag();
}
double dot(complex<double> a, complex<double> b) {
  return a.real() * b.real() + a.imag() * b.imag();
}
double cross(complex<double> a, complex<double> b, complex<double> c) {
  return abs(cross(b - a, c - a));
}
double dot(complex<double> a, complex<double> b, complex<double> c) {
  return dot(b - a, c - a);
}
double p(double x) { return x * x; }
double dis(complex<double> a, complex<double> b) {
  return p(a.real() - b.real()) + p(a.imag() - b.imag());
}
void cal() {
  int p = 1;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    while (dot(a[i], a[p], a[(i + 1) % n]) <
           dot(a[i], a[(p + 1) % n], a[(i + 1) % n]))
      sum += cross(a[i], a[p], a[(p + 1) % n]), p = (p + 1) % n;
    ans = min(ans, dot(a[i], a[p], a[(i + 1) % n]) / dis(a[i], a[(i + 1) % n]) *
                           cross(a[i], a[p], a[(i + 1) % n]) / 2.0 -
                       sum / 2.0);
    sum -= abs(cross(a[p], a[i], a[(i + 1) % n]));
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0, x, y; i < n; i++) cin >> x >> y, a[i] = {1.0 * x, 1.0 * y};
  cal(), reverse(a, a + n), cal();
  cout << fixed << setprecision(9) << ans << endl;
  return 0;
}
