#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  long long x = t1 * (a1 - b1);
  long long y = t2 * (a2 - b2);
  if (x + y == 0) {
    cout << "infinity\n";
    return 0;
  }
  if ((__int128) x * (x + y) >= 0) {
    cout << 0 << '\n';
    return 0;
  }
  __int128 p = abs(x);
  __int128 q = abs(x + y);
  cout << (long long) (p / q * 2) + (p % q != 0) << '\n';
  return 0;
}