#include <bits/stdc++.h>
using namespace std;
long long dp[2][200005], mod = 1e9 + 7;
int add(int a, int b) {
  if (a + b > mod) {
    return a + b - mod;
  }
  return a + b;
}
int main() {
  int r, g;
  scanf("%d%d", &r, &g);
  int i, j;
  if (r < g) {
    swap(r, g);
  }
  dp[0][0] = 1;
  int h = 0;
  for (i = 1; i <= (r + g); i++) {
    int sum = i * (i + 1) / 2;
    if (sum <= (r + g)) {
      h = i;
    } else
      break;
  }
  for (i = 1; i <= h; i++) {
    for (j = 0; j <= r; j++) {
      dp[1][j] = add(dp[1][j], dp[0][j]);
      if (j + i <= r) {
        dp[1][j + i] = add(dp[1][j + i], dp[0][j]);
      }
    }
    for (j = 0; j <= r; j++) {
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }
  int sum = h * (h + 1) / 2;
  long long ans = 0;
  for (i = 0; i <= r; i++) {
    int b = sum - i;
    if (g - b < 0) {
      continue;
    }
    ans = add(ans, dp[0][i]);
  }
  printf("%lld", ans);
}
