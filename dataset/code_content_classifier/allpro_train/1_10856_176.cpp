#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long N, K, dp[1010][1010][4];
int main() {
  cin >> N >> K;
  dp[1][0][3] = 1;
  long long i, j;
  for (i = 2; i <= N; i++)
    for (j = 0; j <= i; j++) {
      dp[i][j][0] = (max(i - 3 - j, 0LL) * dp[i - 1][j][0] +
                     (j + 1) * dp[i - 1][j + 1][0]) %
                    mod;
      dp[i][j][0] = (dp[i][j][0] + max(i - 2 - j, 0LL) * dp[i - 1][j][1] +
                     j * dp[i - 1][j + 1][1]) %
                    mod;
      dp[i][j][0] = (dp[i][j][0] + max(i - 1 - j, 0LL) * dp[i - 1][j][2] +
                     max(j - 1, 0LL) * dp[i - 1][j + 1][2]) %
                    mod;
      dp[i][j][0] = (dp[i][j][0] + max(0LL, i - 2 - j) * dp[i - 1][j][3] +
                     (j + 1) * dp[i - 1][j + 1][3]) %
                    mod;
      dp[i][j][1] = (dp[i - 1][j][1] + 2 * dp[i - 1][j][2]) % mod;
      if (j > 0)
        dp[i][j][1] =
            (dp[i][j][1] + 2 * dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % mod;
      if (j > 1) dp[i][j][2] = dp[i - 1][j - 2][3];
      dp[i][j][3] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                     dp[i - 1][j][3]) %
                    mod;
    }
  cout << (dp[N][K][0] + dp[N][K][1] + dp[N][K][2] + dp[N][K][3]) % mod << "\n";
  return 0;
}
