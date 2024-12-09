#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int R = 1500000;
const double M = 1.0 * R * R;
int n, x[N], y[N], v[N];
double func(long long x, long long y) { return 1.0 * x * x + 1.0 * y * y; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  long long first = 0ll, second = 0ll;
  for (int i = 1; i <= n; i++) {
    double r1 = func(first + x[i], second + y[i]);
    double r2 = func(first - x[i], second - y[i]);
    if (r1 < r2)
      v[i] = 1;
    else
      v[i] = -1;
    first += x[i] * v[i];
    second += y[i] * v[i];
  }
  while (func(first, second) > M) {
    for (int i = 1; i <= n; i++) {
      double r1 = func(first, second);
      double r2 = func(first - 2 * v[i] * x[i], second - 2 * v[i] * y[i]);
      if (r2 < r1) {
        first -= 2 * v[i] * x[i];
        second -= 2 * v[i] * y[i];
        v[i] = -v[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << v[i] << " ";
  printf("\n");
  return 0;
}
