#include <bits/stdc++.h>
using namespace std;
int C[1003];
long long cost[1003], dp[1003][10004];
int main() {
  int N;
  long long w, b, x;
  cin >> N >> w >> b >> x;
  for (int i = 1; i <= N; i++) cin >> C[i];
  for (int i = 1; i <= N; i++) cin >> cost[i];
  for (int i = 0; i <= 10000; i++) {
    if (i > C[1]) {
      dp[1][i] = -1;
      continue;
    }
    dp[1][i] = max(-1LL, w - cost[1] * i);
    if (dp[1][i] >= 0) {
      dp[1][i] += x;
      dp[1][i] = min(dp[1][i], w + b * i);
    }
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 10000; j++) {
      dp[i][j] = -1;
      for (int k = 0; k <= min(C[i], j); k++) {
        long long bestSave = dp[i - 1][j - k];
        if (bestSave < 0) continue;
        dp[i][j] = max(dp[i][j], bestSave - cost[i] * k);
      }
      if (dp[i][j] >= 0) {
        dp[i][j] += x;
        dp[i][j] = min(dp[i][j], w + b * j);
      }
    }
  }
  for (int i = 10000; i >= 0; i--) {
    if (dp[N][i] >= 0) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
