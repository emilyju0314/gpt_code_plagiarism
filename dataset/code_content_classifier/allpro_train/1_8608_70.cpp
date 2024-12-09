#include <bits/stdc++.h>
using namespace std;
long long dp[21][2];
int a[1 << 21];
void dfs(int l, int r, int dep) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  dfs(l, mid, dep - 1);
  dfs(mid + 1, r, dep - 1);
  for (int i = l; i <= mid; i++) {
    dp[dep][0] += lower_bound(a + mid + 1, a + r + 1, a[i]) - (a + mid + 1);
    dp[dep][1] +=
        r - mid - (upper_bound(a + mid + 1, a + r + 1, a[i]) - (a + mid + 1));
  }
  sort(a + l, a + r + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= (1 << n); i++) scanf("%d", &a[i]);
  dfs(1, (1 << n), n);
  int m;
  scanf("%d", &m);
  while (m--) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) swap(dp[i][0], dp[i][1]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[i][0];
    printf("%I64d\n", ans);
  }
}
