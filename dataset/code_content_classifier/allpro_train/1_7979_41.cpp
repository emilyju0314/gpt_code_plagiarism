#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long oo = 1e18 + 7, mod = 1e9 + 7;
const long long N = 2e3 + 5;
long long n, m, dp[N][N][2], pref[N][N][2];
long long posu[N][N], posl[N][N];
char c[N][N];
vector<long long> vc1[N], vc2[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 1;
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> c[i][j];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++)
      if (c[i][j] == 'R') vc2[i].push_back(j);
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++)
      if (c[j][i] == 'R') vc1[i].push_back(j);
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      if (j <= (n - vc1[i].size()))
        posu[j][i] = 1;
      else
        posu[j][i] = vc1[i][vc1[i].size() - (n - j) - 1];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (j <= (m - vc2[i].size()))
        posl[i][j] = 1;
      else
        posl[i][j] = vc2[i][vc2[i].size() - (m - j) - 1];
    }
  }
  dp[1][1][0] = dp[1][1][1] = 1;
  pref[1][1][0] = pref[1][1][1] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (i == 1 && j == 1) continue;
      dp[i][j][0] =
          (pref[i - 1][j][0] - pref[posu[i][j] - 1][j][0] + mod) % mod;
      dp[i][j][1] =
          (pref[i][j - 1][1] - pref[i][posl[i][j] - 1][1] + mod) % mod;
      pref[i][j][0] = (pref[i - 1][j][0] + dp[i][j][1]) % mod;
      pref[i][j][1] = (pref[i][j - 1][1] + dp[i][j][0]) % mod;
    }
  }
  cout << (dp[n][m][0] + dp[n][m][1]) % mod;
}
