#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  string s;
  getline(cin, s);
  for (int i = 0; i < (n); i++) {
    getline(cin, s);
    for (int j = 0; j < m; j++) {
      a[i][j] = (s[j] == '#');
    }
  }
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--;
  y1--;
  x2--;
  y2--;
  vector<vector<int>> dp(n, vector<int>(m, -1));
  queue<pair<pair<int, int>, int>> q;
  q.push({{x1, y1}, 0});
  dp[x1][y1] = 0;
  while (!q.empty()) {
    auto z = q.front();
    q.pop();
    int x = z.first.first;
    int y = z.first.second;
    int steps = z.second;
    for (int i = x + 1, j = 0; i < n && j < k; i++, j++) {
      if (a[i][y]) break;
      if (dp[i][y] != -1) {
        if (dp[i][y] < steps + 1)
          break;
        else
          continue;
      }
      dp[i][y] = steps + 1;
      q.push({{i, y}, steps + 1});
    }
    for (int i = x - 1, j = 0; i >= 0 && j < k; i--, j++) {
      if (a[i][y]) break;
      if (dp[i][y] != -1) {
        if (dp[i][y] < steps + 1)
          break;
        else
          continue;
      }
      dp[i][y] = steps + 1;
      q.push({{i, y}, steps + 1});
    }
    for (int i = y + 1, j = 0; i < m && j < k; i++, j++) {
      if (a[x][i]) break;
      if (dp[x][i] != -1) {
        if (dp[x][i] < steps + 1)
          break;
        else
          continue;
      }
      dp[x][i] = steps + 1;
      q.push({{x, i}, steps + 1});
    }
    for (int i = y - 1, j = 0; i >= 0 && j < k; i--, j++) {
      if (a[x][i]) break;
      if (dp[x][i] != -1) {
        if (dp[x][i] < steps + 1)
          break;
        else
          continue;
      }
      dp[x][i] = steps + 1;
      q.push({{x, i}, steps + 1});
    }
  }
  cout << dp[x2][y2];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  Solve();
  return 0;
}
