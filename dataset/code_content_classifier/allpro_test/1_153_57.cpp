#include <bits/stdc++.h>
using namespace std;
long long cnt[23][26], mod = 998244353;
long long p[26];
long long dp[1 << 23];
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto u : s) cnt[i][u - 'a']++;
  }
  for (long long mask = 1; mask < 1 << n; mask++) {
    for (long long i = 0; i < 26; i++) p[i] = 1e9;
    for (long long i = 0; i < n; i++)
      if (mask & (1 << i)) {
        for (long long j = 0; j < 26; j++) p[j] = min(p[j], cnt[i][j]);
      }
    dp[mask] = 1;
    for (long long i = 0; i < 26; i++) {
      dp[mask] = dp[mask] * (p[i] + 1) % mod;
    }
  }
  for (long long i = 0; i < n; i++)
    for (long long mask = 0; mask < 1 << n; mask++)
      if (mask & (1 << i)) {
        add(dp[mask], mod - dp[mask - (1 << i)]);
      }
  long long ans = 0;
  for (long long mask = 1; mask < 1 << n; mask++) {
    long long k = __builtin_popcount(mask);
    long long sum = 0;
    for (long long i = 0; i < n; i++)
      if (mask & (1 << i)) {
        sum = sum + k * (i + 1);
      }
    if (k & 1)
      ans ^= (sum * dp[mask]);
    else
      ans ^= (sum * (mod - dp[mask]));
  }
  cout << ans;
  return 0;
}
