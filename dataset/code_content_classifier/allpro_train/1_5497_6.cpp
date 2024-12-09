#include <bits/stdc++.h>
double const PI = 4 * atan(1.0);
using namespace std;
long double f[1111][1111], p[1111], k;
long long l, r;
int n, m;
long long tinh(long long x) {
  long long t = 1, res = 0;
  while (t <= x) {
    if (x < 2 * t) {
      res += x - t + 1;
      break;
    } else
      res += t;
    if (t > 1e17 + 10) break;
    t *= 10;
  }
  return res;
}
void debug() { cout << " ??" << endl; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    p[i] = (long double)(tinh(r) - tinh(l - 1)) / (long double)(r - l + 1);
  }
  cin >> k;
  m = (int)(k / 100 * n - 0.00001 + 1);
  memset(f, 0, sizeof(f));
  f[1][1] = p[1];
  f[1][0] = 1 - p[1];
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        f[i][j] = f[i - 1][j] * (1 - p[i]);
      else
        f[i][j] = f[i - 1][j - 1] * p[i] + f[i - 1][j] * (1 - p[i]);
    }
  }
  long double kq = 0.0;
  for (int i = m; i <= n; i++) kq += f[n][i];
  cout.precision(12);
  cout << fixed << kq;
}
