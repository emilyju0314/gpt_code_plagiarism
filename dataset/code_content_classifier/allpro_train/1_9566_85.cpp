#include <bits/stdc++.h>
using namespace std;
long long cost[5][5];
long long dp[45][3][3];
long long dfs(int x, int m, int n) {
  long long ans1, ans2;
  if (x == 0) return 0;
  if (dp[x][m][n] != -1) return dp[x][m][n];
  ans1 = dfs(x - 1, m, n) + cost[m][3 - m - n] + dfs(x - 1, n, m) +
         cost[3 - m - n][n] + dfs(x - 1, m, n);
  ans2 = dfs(x - 1, m, 3 - m - n) + cost[m][n] + dfs(x - 1, 3 - m - n, n);
  return dp[x][m][n] = min(ans1, ans2);
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
  cin >> n;
  cout << dfs(n, 0, 2) << endl;
  return 0;
}
