#include <bits/stdc++.h>
using namespace std;
int N, K, dp[2][511][511], cum[511];
int main() {
  scanf("%d", &N);
  scanf("%d", &K);
  if (K == 1) {
    cout << 0 << endl;
    return 0;
  }
  dp[0][1][1] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = i; j >= 1; j--) {
      for (int k = j; k >= 1; k--) {
        if (!dp[j][k]) continue;
        dp[1][max(j, k + 1)][k + 1] =
            (1LL * dp[1][max(j, k + 1)][k + 1] + dp[0][j][k]) % 998244353;
        dp[1][j][1] = (1LL * dp[1][j][1] + dp[0][j][k]) % 998244353;
      }
    }
    memcpy(dp[0], dp[1], sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++) cum[i] = (cum[i] + dp[0][i][j]) % 998244353;
  int ans = 0;
  for (int i = 1; i < K && i <= N; i++) {
    for (int j = 1; j <= N && 1LL * i * j < K; j++) {
      ans = (ans + (2LL * cum[i] * cum[j]) % 998244353) % 998244353;
    }
  }
  printf("%d\n", ans);
}
