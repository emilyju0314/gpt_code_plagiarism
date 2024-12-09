#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long double sum_a = 0, sum_b = 0;
  vector<long double> a(n), b(n), a_1(n), b_1(n);
  cout << fixed << setprecision(20);
  for (int i = 0; i < n; ++i) cin >> a_1[i];
  for (int i = 0; i < n; ++i) cin >> b_1[i];
  for (int i = 0; i < n; ++i) {
    long double s = a_1[i] + b_1[i];
    long double p = sum_b - s - sum_a;
    long double q = a_1[i] - s * sum_b;
    b[i] = (-p + sqrt(max((long double)0, p * p - 4 * q))) / 2.;
    a[i] = s - b[i];
    sum_a += a[i];
    sum_b += b[i];
  }
  for (int i = 0; i < n; ++i) {
    cout << abs(a[i]) << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    cout << abs(b[i]) << ' ';
  }
  return 0;
}
