#include <bits/stdc++.h>
using namespace std;
int a[2005];
int dp[2005], n, k;
int check(long long max) {
  for (int i = 1; i <= n; i++) {
    dp[i] = i - 1;
    for (int j = 1; j < i; j++) {
      if (abs(a[i] - a[j]) <= (i - j) * max) {
        dp[i] = min(dp[i], dp[j] + (i - j - 1));
      }
    }
    if (dp[i] + n - i <= k) {
      return 1;
    }
  }
  return 0;
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int i;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    long long l = 0, r = 2e9;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    printf("%lld\n", l);
  }
  return 0;
}
