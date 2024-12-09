#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 9;
const long long MAX_SIZE = 1e7 + 1;
long long _t = 1, _T, csn;
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long mmi(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long nxor(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
long long sum(long long n) { return ((n * (n + 1)) / 2); }
long long modsum(long long n, long long m) {
  long long ans = n % m;
  ans *= (n + 1) % m;
  ans %= m;
  ans *= mmi(2, m);
  return ans % m;
}
long long leap(long long y) {
  if (y % 400 == 0)
    return 1;
  else if (y % 100 == 0)
    return 0;
  else if (y % 4 == 0)
    return 1;
  else
    return 0;
}
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  bool multicases = 0;
  if (multicases) cin >> _t;
  _T = _t;
  while (_t--) solve();
  return 0;
}
void solve() {
  csn = _T - _t;
  cout << "INTERCAL";
  return;
}
