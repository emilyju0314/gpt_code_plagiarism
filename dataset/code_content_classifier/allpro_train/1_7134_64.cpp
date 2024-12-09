#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3e3 + 5;
int dp[maxn][2];
int n, a[maxn], b[maxn], c[maxn];
int main() {
  while (~scanf("%d", &n)) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    dp[1][0] = -inf;
    dp[1][1] = 0;
    for (int i = 2; i <= n + 1; ++i) {
      dp[i][0] = max(dp[i - 1][0] + b[i - 1], dp[i - 1][1] + a[i - 1]);
      dp[i][1] = max(dp[i - 1][1] + b[i - 1], dp[i - 1][0] + c[i - 1]);
    }
    printf("%d\n", dp[n + 1][0]);
  }
  return 0;
}
