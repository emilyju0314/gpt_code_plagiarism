#include <bits/stdc++.h>
using namespace std;
long long sb[5050], dp[5050][5050], sum[5050], num[5050];
int n, i, j, k;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &sb[i]);
  }
  sort(sb + 1, sb + n + 1);
  for (i = n, j = n; i >= 1; i--) {
    dp[1][i] = 1;
    for (; j >= 1; j--) {
      if (sb[j] * 2 <= sb[i]) {
        num[i] = j;
        break;
      }
    }
    num[i] += 2;
  }
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j] * max(num[j] - i, 0ll) % 998244353;
      dp[i][j] = (dp[i][j] + sum[num[j] - 2]) % 998244353;
      sum[j] = sum[j - 1] + dp[i - 1][j];
    }
  }
  printf("%lld", dp[n][n]);
}
