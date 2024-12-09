#include <bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
const long long N = 500005;
long long b[N], a[N], flag[N], n, m;
char s1[N], s2[N];
inline long long ksm(long long x, long long y, long long M) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % M)
    if (y & 1) (ans *= x) %= M;
  return ans;
}
void pd(long long d, long long x, long long p) {
  long long s = 0;
  for (long long i = 0, v = 1; i < d; i++, (v *= x) %= p) (s += v * b[i]) %= p;
  if (s == 0) {
    printf("%lld %lld\n", p, x);
    exit(0);
  }
}
void check(long long d) {
  for (long long i = 0; i < n; i++) b[i % d] += a[i];
  for (long long p = d + 1; p < N; p += d)
    if (!flag[p] && p > m) {
      while (1) {
        long long x = rd() % (p - 2) + 1;
        if (ksm(x, (p - 1) / d, p) != 1) {
          x = ksm(x, (p - 1) / d, p);
          for (long long s = x, i = 1; i <= d; i++, (s *= x) %= p) pd(d, s, p);
          break;
        }
      }
    }
  for (long long i = 0; i < d; i++) b[i] = 0;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  scanf("%s%s", s1, s2);
  for (long long i = 0; i < n; i++) a[i] = s1[i] - s2[i];
  for (long long i = 2; i < N; i++)
    if (!flag[i])
      for (long long j = 2 * i; j < N; j += i) flag[j] = 1;
  for (long long i = 3; i < N; i++)
    if (!flag[i]) check(i);
  puts("-1");
}
