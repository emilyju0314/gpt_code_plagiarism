#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long inf = 1e18;
int a[3][maxn];
long long dp[3][maxn][2];
inline long long sum(int i, int f1, int f2, int f3) {
  return f1 * a[0][i] + 0ll + f2 * a[1][i] + 0ll + f3 * a[2][i];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  dp[0][0][0] = dp[0][0][1] = a[0][0];
  dp[1][0][0] = dp[0][0][0] + a[1][0];
  dp[2][0][0] = dp[1][0][0] + a[2][0];
  dp[2][0][1] = -inf;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      dp[0][i][0] = max(dp[0][i - 1][0] + sum(i, 1, 0, 0),
                        max(dp[1][i - 1][0] + sum(i, 1, 1, 0),
                            dp[2][i - 1][0] + sum(i, 1, 1, 1)));
      dp[0][i][0] = max(
          dp[0][i][0], dp[2][i - 1][1] + sum(i, 1, 1, 1) + sum(i - 1, 1, 1, 0));
      dp[0][i][1] = dp[0][i - 1][0] + sum(i, 1, 0, 0);
      dp[1][i][0] = max(dp[0][i - 1][0] + sum(i, 1, 1, 0),
                        max(dp[1][i - 1][0] + sum(i, 0, 1, 0),
                            dp[2][i - 1][0] + sum(i, 0, 1, 1)));
      dp[2][i][0] = max(dp[2][i - 1][0] + sum(i, 0, 0, 1),
                        max(dp[1][i - 1][0] + sum(i, 0, 1, 1),
                            dp[0][i - 1][0] + sum(i, 1, 1, 1)));
      dp[2][i][0] = max(
          dp[2][i][0], dp[0][i - 1][1] + sum(i, 1, 1, 1) + sum(i - 1, 0, 1, 1));
      dp[2][i][1] = dp[2][i - 1][0] + sum(i, 0, 0, 1);
    }
  }
  cout << dp[2][n - 1][0] << endl;
  return 0;
}
