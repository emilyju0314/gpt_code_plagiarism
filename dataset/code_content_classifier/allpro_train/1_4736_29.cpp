#include <bits/stdc++.h>
using namespace std;
long long n;
long long k;
long long a[200005];
long long s1;
long long s2;
long long inv[200005];
long long p;
long long ans;
long long quick_pow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    n >>= 1;
  }
  return res;
}
int main() {
  scanf("%lld %lld", &n, &k);
  inv[1] = inv[0] = 1LL;
  for (long long i = 2; i <= n; i++)
    inv[i] = (1000000007 - 1000000007 / i) * inv[1000000007 % i] % 1000000007;
  for (long long i = 1; i <= n; ++i) inv[i] = inv[i - 1] * inv[i] % 1000000007;
  for (long long i = 1; i <= n; ++i) scanf("%lld", a + i);
  for (long long i = 0; i <= k; ++i) {
    long long fg = 1;
    if (i & 1) fg = -1;
    (s1 += fg * inv[i] * inv[k - i] % 1000000007 * quick_pow(k - i, n) %
           1000000007) %= 1000000007;
    (s2 += fg * inv[i] * inv[k - i] % 1000000007 * quick_pow(k - i, n - 1) %
           1000000007) %= 1000000007;
  }
  p = (s1 + s2 * (n - 1) % 1000000007) % 1000000007;
  p = (p + 1000000007) % 1000000007;
  for (long long i = 1; i <= n; ++i)
    ans = (ans + a[i] * p % 1000000007) % 1000000007;
  printf("%lld\n", ans);
  return 0;
}
