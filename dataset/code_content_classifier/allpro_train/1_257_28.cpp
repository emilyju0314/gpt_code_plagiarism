#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAXN = 5555;
long long fac[MAXN], ifac[MAXN];
long long binom(long long n, long long k) {
  if (k > n || k < 0) return 0;
  long long ans = (ifac[k] * ifac[n - k]) % MOD;
  return (ans * fac[n]) % MOD;
}
long long inv(long long b) {
  long long e = MOD - 2, res = 1;
  for (long long k = 1; k <= e; k *= 2) {
    if (k & e) res = (res * b) % MOD;
    b = (b * b) % MOD;
  }
  return res;
}
long long awoo(long long p, long long ts, long long bn) {
  if (p == 0) {
    if (ts == 0)
      return 1;
    else
      return 0;
  }
  long long res = 0;
  for (long long meanies = 0; meanies * bn <= ts; meanies++) {
    if (meanies > p) break;
    long long cnt =
        (binom(p, meanies) * binom(ts - meanies * bn + p - 1, p - 1)) % MOD;
    if (meanies % 2)
      res = (res - cnt) % MOD;
    else
      res = (res + cnt) % MOD;
  }
  return (res + MOD) % MOD;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) fac[i] = (i * fac[i - 1]) % MOD;
  ifac[MAXN - 1] = inv(fac[MAXN - 1]);
  for (int i = MAXN - 1; i >= 1; i--) ifac[i - 1] = (i * ifac[i]) % MOD;
  long long p, s, r, ans = 0, ways = 0;
  cin >> p >> s >> r;
  if (p == 1) {
    cout << "1\n";
    return 0;
  }
  if (r == 0) {
    cout << inv(p) << '\n';
    return 0;
  }
  for (long long sc = r; sc <= s; sc++) {
    ways = (ways + binom(s - sc + p - 2, p - 2)) % MOD;
    for (long long np = 1; np * sc <= s; np++) {
      if (np > p) break;
      long long res = (awoo(p - np, s - np * sc, sc) * inv(np)) % MOD;
      res = (res * binom(p - 1, np - 1)) % MOD;
      ans += res;
      if (ans >= MOD) ans -= MOD;
    }
  }
  cout << (ans * inv(ways)) % MOD << '\n';
}
