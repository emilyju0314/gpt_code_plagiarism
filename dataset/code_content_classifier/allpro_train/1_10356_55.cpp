#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long& x, long long& y) {
  long long d = a;
  if (b != 0) {
    d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
int main() {
  long long a1, b1, a2, b2, L, R;
  cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
  long long x, y;
  long long d = exgcd(a1, a2, x, y);
  if ((b2 - b1) % d != 0) {
    cout << 0 << endl;
    return 0;
  }
  x *= (b2 - b1) / d;
  long long t = a2 / d;
  x = (x % t + t) % t;
  long long cnt = a1 * x + b1;
  long long lcm = a1 / d * a2;
  long long ans = 0;
  L = max(L, max(b1, b2));
  if (L > R) {
    cout << 0 << endl;
    return 0;
  }
  if (cnt <= R) ans += (R - cnt) / lcm + 1;
  if (cnt < L) ans -= (L - cnt - 1) / lcm + 1;
  cout << ans << endl;
  return 0;
}
