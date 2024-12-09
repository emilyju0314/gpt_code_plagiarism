#include <bits/stdc++.h>
using namespace std;
int i, j, k, m, n, z;
int g[16][16], ans, v[16], d[16], dp[1 << 16];
void dfs(int i) {
  v[i] = 0;
  for (int j = 1; j <= n; j++) {
    if (g[i][j] > 0 && v[j]) dfs(j);
  }
}
int main() {
  cin >> n;
  cin >> m;
  while (m--) {
    cin >> i >> j >> k;
    v[i] = v[j] = 1;
    d[i] ^= 1;
    d[j] ^= 1;
    ans += k;
    if (g[i][j] == 0 || g[i][j] > k) g[i][j] = g[j][i] = k;
  }
  dfs(1);
  for (i = 1; i <= n; i++)
    if (v[i]) {
      cout << -1 << endl;
      return 0;
    }
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (g[i][k] && g[k][j])
          if (g[i][j] == 0 || g[i][j] > g[i][k] + g[k][j])
            g[i][j] = g[i][k] + g[k][j];
  z = 0;
  for (i = 1; i <= n; i++)
    if (d[i]) z |= (1 << (i - 1));
  dp[0] = 0;
  for (i = 1; i <= z; i++) {
    dp[i] = 2000000001;
    for (j = 0; j < n; j++)
      if ((1 << j) & i)
        for (k = j + 1; k < n; k++)
          if ((1 << k) & i)
            if (g[j + 1][k + 1])
              dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + g[j + 1][k + 1]);
  }
  cout << ans + dp[z] << endl;
  return 0;
}
