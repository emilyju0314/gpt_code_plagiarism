#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
vector<pair<int, int>> A[101];
int dp[101][101][26];
void dfs(int i, int j, int ch) {
  if (dp[i][j][ch] != -1) return;
  int temp = 0;
  for (int k = 0; k < A[i].size(); k++) {
    if (A[i][k].second >= ch) {
      dfs(j, A[i][k].first, A[i][k].second);
      temp |= !dp[j][A[i][k].first][A[i][k].second];
    }
  }
  dp[i][j][ch] = temp;
}
signed main() {
  ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < 26; k++) dp[i][j][k] = -1;
  for (int i = 0; i < m; i++) {
    int x, y;
    char z;
    cin >> x >> y >> z;
    int a = (int)z;
    a -= 'a';
    A[x].push_back({y, a});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dfs(i, j, 0);
      cout << (dp[i][j][0] ? 'A' : 'B');
    }
    cout << '\n';
  }
  return 0;
}
