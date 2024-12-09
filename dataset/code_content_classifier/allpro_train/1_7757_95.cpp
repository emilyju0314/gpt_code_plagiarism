#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
const long long N = 100100;
long long n;
long long a[N];
long long bit[N];
long long sum(long long x) {
  long long r = 0;
  while (x > 0) {
    r += bit[x];
    x -= (x & -x);
  }
  return r;
}
void upd(long long x, long long v) {
  while (x < N) {
    bit[x] += v;
    x += (x & -x);
  }
}
double pre[N];
int32_t main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  double den = (double)1.0 * n * (n + 1) / 2.0;
  for (long long i = 1; i < N; i++) {
    pre[i] = pre[i - 1] + (double)(1.0 * i * (i - 1)) / 4.0;
  }
  double ans = 0;
  long long tot = 0;
  for (long long i = n; i >= 1; i--) {
    tot += sum(a[i]);
    ans -= tot;
    ans += pre[n - i + 1];
    upd(a[i], n - i + 1);
  }
  ans = (1.0 * ans) / (1.0 * den);
  for (long long i = 1; i < N; i++) bit[i] = 0;
  tot = 0;
  for (long long i = n; i >= 1; i--) {
    tot += sum(a[i]);
    upd(a[i], 1);
  }
  ans += tot;
  printf("%.13lf\n", ans);
}
