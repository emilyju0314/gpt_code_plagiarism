#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long MOD = 998244353;
long long n, fac[maxn], ifac[maxn], pw3[maxn], pw3n[maxn];
long long qpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD, b >>= 1;
  }
  return ret;
}
inline long long C(long long n, long long m) {
  return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
int main() {
  scanf("%lld", &n);
  fac[0] = ifac[0] = pw3[0] = pw3n[0] = 1;
  long long t = qpow(3, n);
  for (int i = 1; i <= n; i++)
    fac[i] = fac[i - 1] * i % MOD, pw3[i] = pw3[i - 1] * 3 % MOD,
    pw3n[i] = pw3n[i - 1] * t % MOD;
  ifac[n] = qpow(fac[n], MOD - 2);
  for (int i = n - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
  long long ans = (qpow(3, n * n) - qpow(pw3[n] - 3, n) + MOD) % MOD, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    long long v1 = C(n, i), v2 = 3 * qpow((pw3[n - i] - 1), n) % MOD,
              v3 = (pw3[i] - 3) * pw3n[n - i] % MOD;
    if (i & 1)
      ans2 = (ans2 - v1 * (v2 + v3) % MOD + MOD) % MOD;
    else
      ans2 = (ans2 + v1 * (v2 + v3) % MOD) % MOD;
  }
  ans = (ans - ans2 + MOD) % MOD;
  printf("%lld\n", ans);
  return 0;
}
