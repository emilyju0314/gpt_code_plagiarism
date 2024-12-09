#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N], dp[55][105], pre[55], maxn[55][105];
int main() {
  int n, k, p;
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 0; i < n; i++) scanf("%d", a + i), a[i] %= p;
  memset(dp, -1, sizeof(dp));
  memset(maxn, -1, sizeof(maxn));
  maxn[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int x = 0; x < p; x++) {
        if (maxn[j][x] == -1) continue;
        if (j != 0)
          dp[j][(x + a[i]) % p] = max(maxn[j][x], dp[j][(x + a[i]) % p]);
        dp[j + 1][a[i]] = max(dp[j + 1][a[i]], maxn[j][x] + x);
      }
    }
    for (int j = 0; j <= k; j++) {
      for (int x = 0; x < p; x++) {
        maxn[j][x] = dp[j][x];
        dp[j][x] = -1;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < p; i++)
    if (maxn[k][i] != -1) res = max(res, maxn[k][i] + i);
  printf("%d\n", res);
}
