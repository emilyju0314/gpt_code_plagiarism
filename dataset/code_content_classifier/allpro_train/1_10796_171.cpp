#include <bits/stdc++.h>
using namespace std;
int x[1010];
long double y[1010];
using LD = long double;
LD eps = 1e-6;
long double dist(LD x1, LD y1, LD x2, LD y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  cerr.setf(ios::fixed);
  cerr.precision(10);
  int n;
  int r;
  cin >> n >> r;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) {
    long double cury = r;
    for (int j = 0; j < i; ++j) {
      if (abs(x[i] - x[j]) <= 2 * r) {
        long double l = y[j], r1 = 10000000;
        int it = 150;
        while (it--) {
          long double m = (l + r1) / 2.0;
          long double d = dist(x[i], m, x[j], y[j]);
          if (d + eps < 2.0 * r)
            l = m;
          else
            r1 = m;
        }
        cury = max(cury, l);
      }
    }
    y[i] = cury;
  }
  for (int i = 0; i < n; ++i) cout << y[i] << ' ';
  cout << endl;
}
