#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1e6;
const long long MOD = 1e9 + 9;
const long long ep = 1e9 + 5;
const int INF = 1e9;
const double PI = acos(-1);
long long n, a, b, k;
char s[MAXM + 10];
long long acce(long long x, long long y) {
  long long ans = 1;
  long long powe = x;
  long long sum = x;
  long long mul = 1;
  while (y) {
    if (y & 1) {
      ans += mul * sum % MOD;
      ans %= MOD;
      mul *= powe;
      mul %= MOD;
    }
    sum *= (powe + 1);
    sum %= MOD;
    powe *= powe;
    powe %= MOD;
    y /= 2;
  }
  return ans;
}
long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    y = y >> 1;
  }
  return res;
}
long long T(long long m, long long n) {
  if (n <= 1) return 1;
  long long TN2 = T(m, n / 2);
  if (n % 2 == 0) {
    return (TN2 + qpow(m, n / 2) * TN2 % MOD) % MOD;
  } else {
    return (TN2 + qpow(m, n / 2) * TN2 % MOD + qpow(m, n - 1)) % MOD;
  }
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
  scanf("%s", s);
  long long i = 0;
  long long tp = 0;
  long long tx;
  while (i < k) {
    tx = qpow(a, n - i) * qpow(b, i) % MOD;
    if (s[i] == '+')
      tp = (tp + tx) % MOD;
    else
      tp = (tp - tx + MOD) % MOD;
    i++;
  }
  long long xl = (n + 1) / k;
  long long inv = qpow(a, MOD - 2);
  inv = qpow(inv, k);
  long long ce = qpow(b, k) * inv % MOD;
  long long ans = T(ce, xl);
  ans = (ans * tp) % MOD;
  printf("%lld\n", ans);
  return 0;
}
