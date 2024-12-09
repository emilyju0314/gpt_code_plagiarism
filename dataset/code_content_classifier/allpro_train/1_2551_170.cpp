#include <bits/stdc++.h>
using namespace std;
int n, m, s, e, dp[100005][305];
int a[100005];
vector<int> b[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> s >> e;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1, x; i <= m; i++) {
    cin >> x;
    b[x].push_back(i);
  }
  for (int i = 1; i <= 300; i++) dp[0][i] = INT_MAX;
  for (int i = 1; i <= n; i++) dp[i][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 300; j++) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i - 1][j - 1] != INT_MAX) {
        int pos = (int)(upper_bound(b[a[i]].begin(), b[a[i]].end(),
                                    dp[i - 1][j - 1]) -
                        b[a[i]].begin());
        if (pos != b[a[i]].size()) {
          dp[i][j] = min(dp[i][j], b[a[i]][pos]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 300; j++) {
      if (dp[i][j] != INT_MAX) {
        int amt = dp[i][j] + i + j * e;
        if (amt <= s) ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
