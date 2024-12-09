#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &num) {
  T x = 0, ff = 1;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') ff = -1;
  for (; ch <= '9' && ch >= '0'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ '0');
  num = x * ff;
}
int n, q;
const long long mod = 1000000007;
long long k, fac[200005], Inv[200005], a[200005], cnt[1000005], f[1000005],
    pr[1000005], phi[1000005], ans, tot;
bool np[1000005];
inline long long fpow(long long x, long long t) {
  long long ret = 1;
  for (; t; t >>= 1, x = x * x % mod)
    if (t & 1) ret = ret * x % mod;
  return ret;
}
inline long long C(long long _n, long long _m) {
  if (_n < _m) return 0ll;
  return fac[_n] * Inv[_m] % mod * Inv[_n - _m] % mod;
}
void init() {
  fac[0] = Inv[0] = 1;
  for (int i = 1; i <= 200005 - 5; i++) fac[i] = fac[i - 1] * i % mod;
  Inv[200005 - 5] = fpow(fac[200005 - 5], mod - 2);
  for (int i = 200005 - 6; i; i--) Inv[i] = Inv[i + 1] * (i + 1) % mod;
  phi[1] = 1;
  for (int i = 2; i <= 1000005 - 5; i++) {
    if (!np[i]) {
      pr[++tot] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= tot && i * pr[j] <= 1000005 - 5; j++) {
      np[i * pr[j]] = 1;
      if (i % pr[j] == 0) {
        phi[i * pr[j]] = phi[i] * pr[j];
      } else
        phi[i * pr[j]] = phi[i] * (pr[j] - 1);
    }
  }
}
inline void Add(long long x) {
  ans = (ans + mod - C(f[x], k) * phi[x] % mod) % mod;
  f[x]++;
  ans = (ans + C(f[x], k) * phi[x] % mod) % mod;
}
int main() {
  read(n);
  read(k);
  read(q);
  init();
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= 1000005 - 5; i++) {
    for (int j = i; j <= 1000005 - 5; j += i) f[i] += cnt[j];
    ans = (ans + C(f[i], k) * phi[i] % mod) % mod;
  }
  for (int i = 1; i <= q; i++) {
    long long x;
    read(x);
    for (int j = 1; j * j <= x; j++) {
      if (x % j) continue;
      Add(j);
      if (j * j != x) Add(x / j);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
