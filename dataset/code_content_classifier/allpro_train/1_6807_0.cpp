#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const long long p = 1000000007;
long long qp(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long tmp = qp(a * a % p, b >> 1);
  if (b & 1) tmp *= a, tmp %= p;
  return tmp;
}
long long a[114514], f[114514];
long long n, tot, ans;
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) a[i] = read(), tot += a[i];
  f[1] = 1ll * (tot - 1) * (tot - 1) % p * qp(tot, p - 2) % p;
  for (long long i = 1; i <= 100000; ++i)
    f[i + 1] = (2ll * f[i] - f[i - 1] -
                1ll * (tot - 1) * qp(tot - i, p - 2) % p + p + p) %
               p;
  for (long long i = 1; i <= n; ++i) ans += f[a[i]], ans %= p;
  printf("%lld\n", ans);
  return 0;
}
