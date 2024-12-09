#include <bits/stdc++.h>
using namespace std;
long long gt[900], u, dp[900][2], f[900], n, ans;
int main() {
  f[0] = f[1] = 1;
  cin >> n;
  for (int i = 2; i <= 88; i++) f[i] = f[i - 1] + f[i - 2];
  while (cin >> n) {
    u = 0;
    for (int i = 88; i >= 1; i--)
      if (f[i] <= n) {
        u++;
        gt[u] = (long long)i;
        n -= f[i];
      }
    dp[u][1] = 1;
    dp[u][0] = (gt[u] - 1) / 2;
    for (int i = u - 1; i >= 1; i--)
      dp[i][1] = dp[i + 1][1] + dp[i + 1][0],
      dp[i][0] = ((gt[i] - gt[i + 1] - 1) / 2) * (dp[i + 1][1]) +
                 ((gt[i] - gt[i + 1]) / 2) * dp[i + 1][0];
    cout << dp[1][0] + dp[1][1] << endl;
  }
}
