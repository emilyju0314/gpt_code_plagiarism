#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
long long t1, t2, x1, x2, t0;
long long xx = 0, yy = 0;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void update(long long x, long long y) {
  if (x < 0) x = 0;
  if (x > x1) x = x1;
  if (y < 0) y = 0;
  if (y > x2) y = x2;
  if (((long long)xx * t1 + yy * (long long)t2) >= (xx + yy) * t0) {
    if ((x + y) * t0 <= ((long long)x * t1 + y * (long long)t2)) {
      if ((long long)(x + y) * ((long long)xx * t1 + yy * (long long)t2) ==
          (long long)(xx + yy) * ((long long)x * t1 + y * (long long)t2)) {
        if (x + y > xx + yy) xx = x, yy = y;
      } else {
        long long up = ((long long)xx * t1 + yy * (long long)t2),
                  down = (xx + yy);
        long long upp = ((long long)x * t1 + y * (long long)t2), downn = x + y;
        if (up * downn > upp * down) xx = x, yy = y;
      }
    }
  } else
    xx = x, yy = y;
}
int main() {
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t0 == t1 || t0 == t2) {
    if (t0 == t1) xx = x1;
    if (t0 == t2) yy = x2;
    cout << xx << " " << yy << endl;
    return 0;
  }
  if (t0 < t1 && t0 < t2) {
    if (t1 == t2) xx = x1, yy = x2;
    if (t1 < t2) xx = x1, yy = 0;
    if (t2 < t1) xx = 0, yy = x2;
    cout << xx << " " << yy << endl;
    return 0;
  }
  if (t0 > t1 && t0 > t2) {
    if (t1 == t2) xx = x1, yy = x2;
    if (t1 < t2) xx = 0, yy = x2;
    if (t2 < t1) xx = x1, yy = 0;
    cout << xx << " " << yy << endl;
    return 0;
  }
  for (long long i = 0; i <= x1; ++i) {
    long long y = (t1 * i - t0 * i) / (t0 - t2);
    update(i, y);
    update(i, y - 1);
    update(i, y + 1);
  }
  swap(xx, yy);
  swap(x1, x2);
  swap(t1, t2);
  for (long long i = 0; i <= x1; ++i) {
    long long y = (t1 * i - t0 * i) / (t0 - t2);
    update(i, y);
    update(i, y - 1);
    update(i, y + 1);
  }
  swap(xx, yy);
  cout << xx << " " << yy << endl;
  return 0;
}
