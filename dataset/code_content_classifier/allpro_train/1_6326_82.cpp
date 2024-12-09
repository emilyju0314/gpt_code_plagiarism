#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 2;
const int INF = 0x3f3f3f3f;
int n;
char str[maxn];
int dp[maxn][maxn];
void DP() {
  for (int i = 1; i <= n; i++) dp[i][i] = 1;
  for (int len = 2; len <= n; len++)
    for (int l = 1; l <= n - len + 1; l++) {
      int r = l + len - 1;
      dp[l][r] = INF;
      for (int k = l; k < r; k++)
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] - (str[k] == str[r]));
    }
}
int main() {
  scanf("%d%s", &n, str + 1);
  DP();
  printf("%d", dp[1][n]);
  return 0;
}
