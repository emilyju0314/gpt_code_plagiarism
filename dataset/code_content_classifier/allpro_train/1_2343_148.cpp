#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
const long long MOD = 998244353;
long long n;
long long a[N], cache[N][N];
long long dp(long long i, long long prev) {
  if (i == n + 1) return prev == 0;
  long long &ans = cache[i][prev];
  if (ans != -1) return ans;
  ans = dp(i + 1, prev);
  if (prev > 0)
    ans += dp(i + 1, prev - 1);
  else {
    if (a[i] >= 1 && a[i] + prev <= n) ans += dp(i + 1, a[i] + prev);
  }
  ans %= MOD;
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(cache, -1, sizeof(cache));
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = dp(1, 0);
  ans = (ans - 1 + MOD) % MOD;
  cout << ans;
  return 0;
}
