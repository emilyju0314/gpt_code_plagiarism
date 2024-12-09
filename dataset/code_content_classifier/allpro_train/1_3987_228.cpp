#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int dp[5005][5005][2];
int vis[5005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, 0x3f3f3f3f, sizeof dp);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> vis[i];
  dp[1][0][1] = dp[1][0][0] = dp[0][0][1] = dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i / 2 + (i & 1); j++) {
      dp[i][j][0] = min(dp[i - 1][j][0],
                        dp[i - 1][j][1] + max(0, vis[i] - vis[i - 1] + 1));
      dp[i][j][1] = min(dp[i - 1][j - 1][0] + max(0, 1 + vis[i - 1] - vis[i]),
                        dp[i - 2][j - 1][1] +
                            max(0, 1 + vis[i - 1] - min(vis[i - 2], vis[i])));
    }
  }
  for (int i = 1; i <= n / 2 + (n & 1); i++) {
    cout << min(dp[n][i][1], dp[n][i][0]) << " ";
  }
}
