#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
const long long INF = numeric_limits<long long>::max() / 2;
const long double PI = 3.1415926535898;
const long long MOD = 1e9 + 7;
const long long LIM = 1e5 + 5;
long long fpow(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = fpow(x, y / 2);
  if (y % 2 == 0)
    return (temp * temp) % MOD;
  else
    return (x * ((temp * temp) % MOD)) % MOD;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long v[6][LIM], loge[LIM], dp[6][LIM][20];
void solve() {
  long long n, m, K;
  cin >> n >> m >> K;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) cin >> v[j][i];
  loge[1] = 0;
  for (long long i = 2; i < LIM; i++) loge[i] = loge[i / 2] + 1;
  long long k = log2(n);
  for (long long mask = 0; mask < m; ++mask)
    for (long long i = 0; i < n; ++i) dp[mask][i][0] = v[mask][i];
  for (long long mask = 0; mask < m; ++mask)
    for (long long j = 1; j <= k; ++j)
      for (long long i = 0; i + (1 << j) <= n; i++)
        dp[mask][i][j] =
            max(dp[mask][i][j - 1], dp[mask][i + (1 << (j - 1))][j - 1]);
  long long maxi = 0, ans[m];
  memset(ans, 0, sizeof(ans));
  for (long long i = 0; i < n; ++i) {
    long long l = 0, r = n - i;
    while (l < r) {
      long long mid = (l + r + 1) / 2, cnt = 0;
      long long L = i, R = i + mid - 1;
      long long ele = loge[R - L + 1];
      for (long long j = 0; j < m; ++j) {
        long long x = max(dp[j][L][ele], dp[j][R - (1 << ele) + 1][ele]);
        cnt += x;
      }
      if (cnt <= K)
        l = mid;
      else
        r = mid - 1;
    }
    if (l > maxi) {
      maxi = l;
      long long L = i, R = i + l - 1;
      long long ele = loge[R - L + 1];
      for (long long j = 0; j < m; ++j)
        ans[j] = max(dp[j][i][ele], dp[j][R - (1 << ele) + 1][ele]);
    }
  }
  for (long long i = 0; i < m; ++i) cout << ans[i] << " ";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
