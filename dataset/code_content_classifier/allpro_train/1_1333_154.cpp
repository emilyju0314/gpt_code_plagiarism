#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 5;
inline long long add(long long x, long long y) { return (x + y) % mod; }
inline long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
long long dp[2][N];
inline void solve() {
  long long n;
  bool f = 1;
  cin >> n;
  dp[0][1] = 1;
  for (long long i = 2; i < N; ++i) {
    dp[f][i] = add(dp[f ^ 1][i - 1], 1);
    dp[f][i] = add(dp[f][i - 2], dp[f][i]);
    f ^= 1;
    dp[f][i] = dp[f][i - 1];
  }
  cout << add(dp[0][n], dp[1][n]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  solve();
  return 0;
}
