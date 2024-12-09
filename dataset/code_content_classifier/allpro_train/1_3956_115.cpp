#include <bits/stdc++.h>
using namespace std;
long long a, b, p, n;
long long ksm(long long x, long long t, long long mo) {
  if (mo == 1) return 0;
  long long base = x, ret = 1;
  for (; t;) {
    if (t & 1) {
      ret = ret * base % mo;
    }
    base = base * base % mo;
    t >>= 1;
  }
  return ret;
}
long long Pow[1000007];
void work() {
  long long ans = 0;
  long long now = (long long)1 * p * (p - 1);
  Pow[0] = 1;
  for (long long t = 1; t < p - 1; t++) Pow[t] = Pow[t - 1] * a % p;
  for (long long t = 0; t < p - 1; t++) {
    long long r = (long long)1 * b * ksm(Pow[t], p - 2, p) % p;
    long long mn = (t * p + r * (p - 1) * (p - 1)) % (p * (p - 1));
    if (mn <= n) {
      ans += (n - mn) / now + 1;
    }
  }
  printf("%I64d", ans);
}
int main() {
  scanf("%I64d%I64d%I64d%I64d", &a, &b, &p, &n);
  work();
  return 0;
}
