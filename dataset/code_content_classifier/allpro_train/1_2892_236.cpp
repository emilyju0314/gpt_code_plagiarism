#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long Pot(long long p, long long w) {
  if (w == 0) return 1;
  if (w % 2 == 0) {
    long long pol = Pot(p, w / 2);
    return (pol * pol) % MOD;
  } else
    return (Pot(p, w - 1) * p) % MOD;
}
long long Inv(long long x) { return Pot(x, MOD - 2); }
long long C(long long n, long long k) {
  long long licz = 1;
  for (long long i = n - k + 1; i <= n; ++i) licz = (licz * (i % MOD)) % MOD;
  long long mian = 1;
  for (long long i = 2; i <= k; ++i) mian = (mian * i) % MOD;
  return (licz * Inv(mian)) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n, s;
  cin >> n >> s;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long wsz = C(s + n - 1, n - 1);
  long long zle = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    long long odj = 0;
    for (int i = 0; i < n; ++i)
      if ((mask & (1 << i)) > 0) odj += a[i] + 1;
    if (s - odj >= 0) {
      s -= odj;
      long long il = C(s + n - 1, n - 1);
      if (__builtin_popcount(mask) % 2 == 1)
        zle += il;
      else
        zle -= il;
      if (zle < 0) zle += MOD;
      zle %= MOD;
      s += odj;
    }
  }
  long long odp = wsz - zle;
  if (odp < 0) odp += MOD;
  odp %= MOD;
  cout << odp;
  return 0;
}
