#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  const int INF = 1e9;
  vector<vector<int> > a(n, vector<int>(m + 2, 0));
  vector<vector<int> > dp(n, vector<int>(2, INF));
  int firstOne = n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m + 2; ++j) {
      a[i][j] = s[j] - '0';
      if (a[i][j] == 1) {
        firstOne = min(firstOne, i);
      }
    }
  }
  if (firstOne == n) {
    cout << 0 << endl;
    return;
  }
  int leftmostOne = m + 2;
  int rightmostOne = 0;
  for (int j = 0; j < m + 2; ++j)
    if (a[firstOne][j] == 1) {
      leftmostOne = min(leftmostOne, j);
      rightmostOne = max(rightmostOne, j);
    }
  if (leftmostOne == m + 2) {
    dp[firstOne][0] = 0;
    dp[firstOne][1] = 0;
  } else {
    dp[firstOne][0] = rightmostOne;
    dp[firstOne][1] = m + 1 - leftmostOne;
  }
  for (int i = firstOne + 1; i < n; ++i) {
    int leftmostOne = m + 2;
    int rightmostOne = 0;
    for (int j = 0; j < m + 2; ++j)
      if (a[i][j] == 1) {
        leftmostOne = min(leftmostOne, j);
        rightmostOne = max(rightmostOne, j);
      }
    if (leftmostOne == m + 2) {
      dp[i][0] = min(1 + dp[i - 1][0], m + 2 + dp[i - 1][1]);
      dp[i][1] = min(1 + dp[i - 1][1], m + 2 + dp[i - 1][0]);
    } else {
      dp[i][0] = min(2 * rightmostOne + 1 + dp[i - 1][0], m + 2 + dp[i - 1][1]);
      dp[i][1] = min(2 * (m + 1 - leftmostOne) + 1 + dp[i - 1][1],
                     m + 2 + dp[i - 1][0]);
    }
  }
  cout << dp[n - 1][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
