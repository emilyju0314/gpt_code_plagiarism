#include <bits/stdc++.h>
using namespace std;
int const M = 5e5 + 10, N = 1e7 + 10;
long long const mod = 998244353;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long T, n, m, x, y, dp[3][M], ans;
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    ans = 0;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> x;
      ++x;
      dp[1][x + 1] += dp[1][x + 1];
      dp[1][x + 1] %= mod;
      dp[1][x + 1] += dp[1][x];
      dp[1][x + 1] %= mod;
      dp[2][x + 1] += dp[2][x + 1];
      dp[2][x + 1] %= mod;
      dp[2][x - 1] += dp[2][x - 1];
      dp[2][x - 1] %= mod;
      dp[2][x - 1] += dp[1][x - 1];
      dp[2][x - 1] %= mod;
    }
    for (int i = 0; i <= n + 2; ++i) {
      ans += dp[1][i];
      dp[1][i] = 0;
      ans %= mod;
      ans += dp[2][i];
      dp[2][i] = 0;
      ans %= mod;
    }
    ans += mod;
    ans -= 1;
    ans %= mod;
    cout << ans << "\n";
  }
  return 0;
}
