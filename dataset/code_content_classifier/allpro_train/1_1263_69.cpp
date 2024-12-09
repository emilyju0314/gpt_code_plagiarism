#include <bits/stdc++.h>
using namespace std;
const int maxv = 2045;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 40;
long long fac[maxn], inv[maxn];
long long qpow(long long a, long long p) {
  long long ans = 1;
  long long xx = a;
  while (p > 0) {
    if (p & 1) ans = (xx * ans) % mod;
    xx = (xx * xx) % mod;
    p >>= 1;
  }
  return ans;
}
void init() {
  fac[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i < maxn; ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = inv[i - 1] * qpow(i, mod - 2) % mod;
  }
}
int h, w, n;
pair<long long, long long> a[maxv];
long long dp[maxv];
long long culC(long long a, long long b) {
  return fac[a] * inv[a - b] % mod * inv[b] % mod;
}
long long path(long long sx, long long sy, long long tx, long long ty) {
  return culC(ty - sy + tx - sx, tx - sx);
}
void solve() {
  for (int i = 0; i <= n; ++i) {
    long long ans = 0;
    for (int j = 0; j < i; ++j) {
      if (a[j].second <= a[i].second)
        ans += path(a[j].first, a[j].second, a[i].first, a[i].second) * dp[j] %
               mod,
            ans %= mod;
    }
    dp[i] = (path(1, 1, a[i].first, a[i].second) - ans) % mod + mod,
    dp[i] %= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  init();
  cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    int c, r;
    cin >> r >> c;
    a[i].first = r;
    a[i].second = c;
  }
  sort(a, a + n);
  a[n] = pair<long long, long long>(h, w);
  solve();
  cout << dp[n] << endl;
  return 0;
}
