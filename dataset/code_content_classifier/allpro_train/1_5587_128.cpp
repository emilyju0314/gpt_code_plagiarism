#include <bits/stdc++.h>
using namespace std;
long long a[1010000], b[1010000], tms[1010000], C[1010000];
const long long mod = 1000000007;
long long qpow(long long x, long long y, const long long& k) {
  long long t = 1;
  while (y) {
    if (y & 1) {
      t = t * x % k;
    }
    x = x * x % k;
    y >>= 1;
  }
  return t;
}
long long inv(long long x) { return qpow(x, mod - 2, mod); }
signed main() {
  std::ios::sync_with_stdio(false);
  long long n, l, k;
  cin >> n >> l >> k;
  long long tk = l / n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  long long h = 0;
  sort(b + 1, b + n + 1);
  for (long long i = 1; i <= n; ++i) {
    if (b[i] != b[i - 1]) b[++h] = b[i];
    ++tms[h];
  }
  for (long long i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + h + 1, a[i]) - b;
  vector<vector<long long>> f(k + 5);
  for (auto& i : f) i = vector<long long>(h + 5);
  vector<vector<long long>> lst(k + 5);
  for (auto& i : lst) i = vector<long long>(h + 5);
  C[0] = 1;
  for (long long j = 0; j <= h; ++j) lst[0][j] = 1;
  for (long long i = 1; i <= min(k, tk); ++i) {
    for (long long j = 1; j <= h; ++j) {
      f[i][j] = lst[i - 1][j] * tms[j] % mod;
      lst[i][j] = (lst[i][j - 1] + f[i][j]) % mod;
      (f[i][j] *= (tk - i + 1) % mod) %= mod;
    }
  }
  long long rem = l % n;
  if (rem) {
    f[k + 1] = vector<long long>(rem + 5);
    for (long long j = 1; j <= rem; ++j) {
      for (long long r = 0; r < k; ++r) (f[k + 1][j] += lst[r][a[j]]) %= mod;
    }
  }
  long long ans = 0;
  for (auto& p : f) {
    for (auto& q : p) {
      ans = (ans + q) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}
