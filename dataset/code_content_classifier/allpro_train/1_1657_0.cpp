#include <bits/stdc++.h>
using namespace std;
const long long N = 200010, Mod = 1000000007;
long long n, T, M, res, ans;
long long a[N], inv[N], fac[N];
long long Inv[N], pow_2[N];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long C(long long n, long long m) {
  if (n < m) return 0;
  return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}
inline long long Power(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) result = result * base % Mod;
    power >>= 1;
    base = (base * base) % Mod;
  }
  return result;
}
inline void Pre() {
  fac[0] = inv[0] = pow_2[0] = Inv[0] = 1;
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) a[i] += a[i - 1];
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % Mod;
  for (long long i = 1; i <= n; i++) inv[i] = Power(fac[i], Mod - 2);
  for (long long i = 1; i <= n; i++) {
    pow_2[i] = pow_2[i - 1] * 2 % Mod;
    Inv[i] = Power(pow_2[i], Mod - 2);
  }
}
signed main() {
  n = read(), T = read();
  Pre();
  M = n, res = 1;
  for (long long i = 1; i <= n; i++) {
    long long s = min(n, T - a[i]);
    if (s < 0) continue;
    res = ((2 * res - C(i - 1, M)) % Mod + Mod) % Mod;
    while (M > s) {
      res = ((res - C(i, M)) % Mod + Mod) % Mod;
      M--;
    }
    ans = (ans + res * Inv[i] % Mod) % Mod;
  }
  printf("%lld\n", ans % Mod);
  return 0;
}
