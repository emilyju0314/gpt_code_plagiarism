#include <bits/stdc++.h>
long long get() {
  long long x = 0;
  char s = getchar();
  while (s < '0' || s > '9') s = getchar();
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  return x;
}
long long Max(const long long x, const long long y) {
  if (x > y) return x;
  return y;
}
long long Min(const long long x, const long long y) {
  if (x < y) return x;
  return y;
}
long long a[205], b[205], dp[205][10005], n, m, ans;
signed main() {
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  n = get(), m = get();
  for (long long i = 1, t; i <= n; ++i) {
    t = get();
    while (t % 2 == 0) t >>= 1, ++a[i];
    while (t % 5 == 0) t /= 5, ++b[i];
  }
  for (long long i = 1; i <= n; ++i)
    for (long long j = m; j >= 0; --j)
      for (long long k = 10000; k >= 0; --k)
        if (j && k >= b[i] && ~dp[j - 1][k - b[i]])
          dp[j][k] = Max(dp[j][k], dp[j - 1][k - b[i]] + a[i]);
  for (long long i = 0; i <= 10000; ++i) ans = Max(ans, Min(i, dp[m][i]));
  printf("%lld", ans);
  return 0;
}
