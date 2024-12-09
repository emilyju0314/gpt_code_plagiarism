#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 65, inf = 1e15;
long long dis[N][N][N], dp[N][N][N];
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  memset(dp, 31, sizeof dp);
  for (long long a = 1; a <= m; a++)
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= n; j++) cin >> dis[a][i][j];
  for (long long a = 1; a <= m; a++)
    for (long long k = 1; k <= n; k++)
      for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= n; j++)
          dis[a][i][j] = min(dis[a][i][j], dis[a][i][k] + dis[a][k][j]);
  for (long long a = 1; a <= m; a++)
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= n; j++)
        dp[0][i][j] = min(dp[0][i][j], dis[a][i][j]);
  for (long long t = 1; t <= n; t++)
    for (long long k = 1; k <= n; k++)
      for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= n; j++)
          dp[t][i][j] = min(dp[t][i][j], dp[t - 1][i][k] + dp[0][k][j]);
  while (q--) {
    long long u, v, t;
    cin >> u >> v >> t;
    t = min(n, t);
    cout << dp[t][u][v] << "\n";
  }
}
