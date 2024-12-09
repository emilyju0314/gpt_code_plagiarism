#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
long long mul(long long a, long long b) {
  a %= MOD;
  b %= MOD;
  return a * b % MOD;
}
long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
long long binpow(long long x, long long st) {
  long long ret = 1;
  while (st) {
    if (st & 1) ret = mul(ret, x);
    x = mul(x, x);
    st /= 2;
  }
  return ret;
}
long long inv(long long x) { return binpow(x, MOD - 2); }
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long inv2 = inv(2);
  long long n, m;
  cin >> n >> m;
  long long ans = mul(n, m);
  m = min(n, m);
  for (long long left = 1, right = 1; left <= m; left = right + 1) {
    long long d = n / left;
    right = n / d;
    right = min(right, m);
    long long len = right - left + 1;
    long long val = mul(d, (mul(mul(left + right, len), inv2)));
    ans = sub(ans, val);
  }
  cout << ans << '\n';
}
