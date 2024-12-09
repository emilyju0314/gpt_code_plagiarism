#include <bits/stdc++.h>
using namespace std;
const long long N = 500005, M = 998244353;
long long a[N], p[N], n, m, fac[N], inv[N];
long long ksm(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % M)
    if (y & 1) (ans *= x) %= M;
  return ans;
}
inline void init(long long y[], long long len) {
  for (long long i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    long long k = len / 2;
    while (j >= k) {
      j -= k;
      k /= 2;
    }
    j += k;
  }
}
inline void ntt(long long y[], long long len, long long opt) {
  init(y, len);
  for (long long h = 2; h <= len; h <<= 1) {
    long long wn = ksm(3, (M - 1) / h);
    if (opt == -1) wn = ksm(wn, M - 2);
    for (long long j = 0; j < len; j += h) {
      long long w = 1;
      for (long long k = j; k < j + h / 2; k++) {
        long long u = y[k], v = w * y[k + h / 2] % M;
        y[k] = (u + v) % M;
        y[k + h / 2] = (u - v + M) % M;
        w = w * wn % M;
      }
    }
  }
  if (opt == 1) return;
  long long temp = ksm(len, M - 2);
  for (long long i = 0; i < len; i++) (y[i] *= temp) %= M;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  fac[0] = inv[0] = 1;
  for (long long i = 1; i <= n; i++)
    fac[i] = fac[i - 1] * i % M, inv[i] = ksm(fac[i], M - 2);
  for (long long i = 0; i <= n; i++)
    scanf("%lld", &p[i]), (p[i] *= fac[i]) %= M;
  reverse(p, p + n + 1);
  for (long long i = 0; i <= n; i++) a[i] = inv[i];
  long long len = 1;
  while (len < 2 * n + 5) len <<= 1;
  ntt(a, len, 1);
  ntt(p, len, 1);
  for (long long i = 0; i < len; i++) (a[i] *= p[i]) %= M;
  ntt(a, len, -1);
  for (long long i = n + 1; i < len; i++) a[i] = 0;
  reverse(a, a + n + 1);
  for (long long i = 0; i <= n; i++) (a[i] *= ksm(ksm(i + 1, m), M - 2)) %= M;
  reverse(a, a + n + 1);
  for (long long i = 0; i <= n; i++) p[i] = ksm(M - 1, i) * inv[i] % M;
  for (long long i = n + 1; i < len; i++) p[i] = 0;
  ntt(a, len, 1);
  ntt(p, len, 1);
  for (long long i = 0; i < len; i++) (a[i] *= p[i]) %= M;
  ntt(a, len, -1);
  reverse(a, a + n + 1);
  for (long long i = 0; i <= n; i++) printf("%lld ", a[i] * inv[i] % M);
}
