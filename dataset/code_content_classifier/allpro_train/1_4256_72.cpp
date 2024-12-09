#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  cin >> n >> r;
  int a, b;
  int cnt = 0;
  vector<pair<int, int>> pos, neg;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (b >= 0)
      pos.push_back({a, b});
    else
      neg.push_back({a, b});
  }
  sort(pos.begin(), pos.end());
  for (int i = 0; i < pos.size(); ++i) {
    if (r >= pos[i].first) {
      r += pos[i].second;
      cnt++;
    }
  }
  sort(neg.begin(), neg.end(), [&](pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first + p1.second > p2.first + p2.second;
  });
  vector<vector<int>> dp(n + 3, vector<int>(r + 3, 0));
  dp[0][r] = cnt;
  int ans = 0;
  for (int i = 0; i < neg.size(); ++i) {
    for (int j = 0; j <= r; ++j) {
      if (j >= neg[i].first && j + neg[i].second >= 0) {
        dp[i + 1][j + neg[i].second] =
            max(dp[i + 1][j + neg[i].second], 1 + dp[i][j]);
      }
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
    }
  }
  for (int i = 0; i <= r; ++i) ans = max(ans, dp[neg.size()][i]);
  cout << ans << endl;
}
