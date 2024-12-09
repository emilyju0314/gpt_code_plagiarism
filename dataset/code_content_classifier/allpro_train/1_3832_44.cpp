#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 998244353;
template <typename T>
inline T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
inline T q_pow(T a, T x) {
  T ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
int m, n, t = 1, st, en;
long long mul[N], inv[N];
inline long long C(int m, int n) {
  if (m > n || m < 0) return 0;
  return mul[n] * inv[m] % mod * inv[n - m] % mod;
}
inline long long P(int m, int n) {
  if (m > n || m < 0) return 0;
  return mul[n] * inv[n - m] % mod;
}
long long a[N], l[N], r[N];
int main() {
  mul[0] = 1;
  for (int i = 1; i < N; i++) mul[i] = mul[i - 1] * i % mod;
  inv[N - 1] = q_pow(mul[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) (inv[i] = inv[i + 1] * (i + 1)) %= mod;
  re(n);
  re(m);
  for (int i = 1; i <= n; i++) re(a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) l[i] = (a[i] + l[i - 1]) % mod;
  for (int i = n; i >= 1; i--) r[i] = (a[i] + r[i + 1]) % mod;
  for (int i = 1; i <= m; i++) {
    long long x;
    int y;
    re(y);
    re(x);
    int pos = lower_bound(a + 1, a + n + 1, x) - a;
    if (pos <= n) {
      long long ans = 0;
      (ans += r[pos] * C(y, n - pos) % mod * P(y, y) % mod *
              P(n - pos - y + 1, n - pos - y + 1) % mod * C(pos - 1, n) % mod *
              P(pos - 1, pos - 1) % mod) %= mod;
      if (pos > 1)
        (ans += l[pos - 1] * C(y, n - pos + 1) % mod * P(y, y) % mod *
                P(n - pos - y + 1 + 1, n - pos - y + 1 + 1) % mod *
                C(pos - 2, n) % mod * P(pos - 2, pos - 2) % mod) %= mod;
      (ans *= inv[n]) %= mod;
      printf("%lld\n", (ans + mod) % mod);
    } else
      puts("0");
  }
}
