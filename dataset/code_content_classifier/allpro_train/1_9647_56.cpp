#include <bits/stdc++.h>
const long long mo1 = 10000000000ll;
const long long mo2 = 10000000009ll;
using namespace std;
long long mul(long long x, long long y, long long mo) {
  long long ans = (long long)(1.0 * x / mo * y);
  ans = (x * y - ans * mo);
  return (ans % mo + mo) % mo;
}
long long S1(long long x, long long y, long long mo) {
  long long v1 = x + y, v2 = y - x + 1, v3 = 1;
  (v1 % 2 == 0 ? v1 /= 2 : (v2 % 2 == 0 ? v2 /= 2 : v3 /= 2));
  return mul(v1 % mo, v2 % mo, mo);
}
long long S2(long long x, long long mo) {
  long long v1 = x, v2 = x + 1, v3 = 2 * x + 1;
  (v1 % 2 == 0 ? v1 /= 2 : (v2 % 2 == 0 ? v2 /= 2 : v3 /= 2));
  (v1 % 3 == 0 ? v1 /= 3 : (v2 % 3 == 0 ? v2 /= 3 : v3 /= 3));
  return mul(mul(v1 % mo, v2 % mo, mo), v3 % mo, mo);
}
long long S2(long long x, long long y, long long mo) {
  return (S2(y, mo) + mo - S2(x - 1, mo)) % mo;
}
long long calc(long long x, long long y, long long mo) {
  if (!x || !y) return 0;
  long long ans = 0;
  if (x > y) {
    ans += S1(1, y * y, mo);
    ans += mul(S1(y * y + y + 2, y * y + 2 * y + 1, mo), x - y, mo);
    ans += mul(S2(y + 1, x, mo) - mul(x - y, mul(y + 1, y + 1, mo), mo) + mo, y,
               mo);
  } else {
    ans += S1(1, x * x, mo);
    ans += mul(S1(x * x + 1, x * x + x, mo), y - x, mo);
    ans += mul(S2(x, y - 1, mo) - mul(y - x, mul(x, x, mo), mo) + mo, x, mo);
  }
  return ans % mo;
}
void solve() {
  int x, y, X, Y;
  scanf("%d%d%d%d", &x, &y, &X, &Y);
  long long ans1 = calc(X, Y, mo1) - calc(X, y - 1, mo1) - calc(x - 1, Y, mo1) +
                   calc(x - 1, y - 1, mo1);
  long long ans2 = calc(X, Y, mo2) - calc(X, y - 1, mo2) - calc(x - 1, Y, mo2) +
                   calc(x - 1, y - 1, mo2);
  ans1 = (ans1 % mo1 + mo1) % mo1;
  ans2 = (ans2 % mo2 + mo2) % mo2;
  if (ans1 == ans2)
    printf("%lld\n", ans1);
  else if (ans1 >= 1000000000)
    printf("...%lld\n", ans1);
  else
    printf("...0%09lld\n", ans1);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
