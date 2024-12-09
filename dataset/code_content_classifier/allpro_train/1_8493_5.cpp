#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 10, M = 110, mod = 998244353;
long long dp[N][M], ps[N][M], a[N];
vector<int> v[N];
int mx[M];
long long dp2[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, len;
  cin >> n >> k >> len;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != -1) v[a[i]].push_back(i);
  }
  for (int i = 1; i <= k; i++) mx[i] = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (a[i] != -1 && a[i] != j) {
        mx[j] = i;
        continue;
      }
      if (i + 1 < len && mx[j] == -1) dp[i][j] = 1;
      int st = max({i - len + 1, 0, mx[j]});
      dp[i][j] += ps[i][0] - ps[st][0] - ps[i][j] + ps[st][j];
      dp[i][j] %= mod;
      if (dp[i][j] < 0) dp[i][j] += mod;
      dp[i][0] += dp[i][j];
      if (dp[i][0] >= mod) dp[i][0] -= mod;
    }
    for (int j = 0; j <= k; j++) ps[i + 1][j] = (dp[i][j] + ps[i][j]) % mod;
  }
  cout << dp[n - 1][0] << endl;
}
