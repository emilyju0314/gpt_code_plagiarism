#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long N = 200010;
const long long LG = 20;
long long n;
string s;
long long dp[(1 << LG)];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  n = s.size();
  for (long long i = 0; i < n; i++) {
    long long mask = 0, count = 0;
    for (long long j = 0; j < LG && i + j < n; j++) {
      long long num = s[i + j] - 'a';
      if (mask & (1ll << num)) {
        break;
      }
      mask |= (1ll << num);
      count = __builtin_popcountll(mask);
      dp[mask] = max(dp[mask], count);
    }
    count = __builtin_popcountll(mask);
    dp[mask] = max(dp[mask], count);
  }
  for (long long mask = 0; mask < (1ll << LG); mask++) {
    for (long long i = 0; i < LG; i++) {
      if ((1ll << i) & mask) dp[mask] = max(dp[mask], dp[mask ^ (1ll << i)]);
    }
  }
  long long ans = 0;
  for (long long mask = 0; mask < (1ll << LG); mask++) {
    long long maxx = (1ll << LG) - 1;
    ans = max(ans, dp[mask] + dp[maxx ^ mask]);
  }
  cout << ans << "\n";
  return 0;
}
