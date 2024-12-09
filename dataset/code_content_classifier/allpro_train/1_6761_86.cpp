#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 200010;
long long arr[maxn], sum[maxn], dp[2010], x[maxn], y[maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) scanf("%I64d", arr + i);
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= k; i++) sum[i] = arr[i] + sum[i - 1];
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  x[m] = 1, y[m] = 0;
  for (int j = 0; j <= k; j++) {
    for (int i = 0; i <= m; i++) {
      if (j - x[i] >= 0) {
        dp[j] = min(dp[j], dp[j - x[i]] + sum[j] - sum[j - x[i] + y[i]]);
      }
    }
  }
  cout << dp[k];
  return 0;
}
