#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
int a[2 * 100000 + 5];
int n;
int i, j;
double X(double x) {
  vector<double> v;
  for (int j = 0; j < n; j++) v.push_back(a[j] - x);
  double curmax = 0;
  double sum = 0;
  for (j = 0; j < n; j++) {
    sum += v[j];
    if (curmax < 0 && sum >= 0) {
      if (abs(curmax) < abs(sum - curmax)) {
        double k = curmax;
        curmax = sum - k;
        sum = sum - k;
      }
    } else if (curmax >= 0 && sum <= 0) {
      if (abs(curmax) < abs(-curmax + sum)) {
        double k = curmax;
        curmax = -k + sum;
        sum = -k + sum;
      }
    } else {
      if (abs(curmax) < abs(sum)) {
        curmax = sum;
      }
    }
  }
  return abs(curmax);
}
int main() {
  scanf("%d", &n);
  for (j = 0; j < n; j++) scanf("%d", &a[j]);
  double lo = -10001;
  double hi = 10001;
  i = 0;
  while (i != 300) {
    double g = lo + (hi - lo) / 3.0;
    double h = hi - (hi - lo) / 3.0;
    if (X(g) < X(h)) {
      hi = h;
    } else
      lo = g;
    i++;
  }
  cout << fixed << setprecision(10) << X(lo);
  return 0;
}
