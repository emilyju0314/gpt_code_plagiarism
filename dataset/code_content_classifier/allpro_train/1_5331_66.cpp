#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, a[100010], dp[100010];
bool check(int x) {
  for (int sta = 0; sta < 2 && sta < n; sta++) {
    dp[sta] = sta ? max(a[0] + x, a[1]) : a[0];
    for (int i = sta + 1; i < n; i++) {
      dp[i] = dp[i - 1];
      if (dp[i - 1] >= a[i] - x - 1) dp[i] = max(dp[i], a[i]);
      if (dp[i - 1] >= a[i] - 1) dp[i] = max(dp[i], a[i] + x);
      if (i >= 2 && dp[i - 2] >= a[i] - x - 1) dp[i] = max(dp[i], a[i - 1] + x);
    }
    if (dp[n - 1] >= min(m - 1, m + a[sta] - x - 1)) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  pair<int, int> best(a[0] + m - a[n - 1], 0);
  for (int i = 1; i < n; i++) best = max(best, make_pair(a[i] - a[i - 1], i));
  rotate(a, a + best.second, a + n);
  for (int i = n - 1; i >= 0; i--) {
    a[i] -= a[0];
    if (a[i] < 0) a[i] += m;
  }
  int l = 0, r = a[0] + m - a[n - 1] - 1;
  int ans = r;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
