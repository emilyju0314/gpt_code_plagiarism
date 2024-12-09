#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n;
long long d, r1, r2, r3;
long long a[N];
long long dp[N][2];
long long ans;
inline long long Min(long long x, long long y) { return x > y ? y : x; }
inline long long read() {
  long long a = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    a = (a << 1) + (a << 3) + ch - 48, ch = getchar();
  return a;
}
signed main() {
  n = read(), r1 = read(), r2 = read(), r3 = read(), d = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  dp[1][1] = a[1] * r1 + r3, dp[1][0] = Min((a[1] + 1) * r1, r2) + d + d;
  for (long long i = 2; i <= n; ++i) {
    dp[i][0] = 3 * d + dp[i - 1][1] + Min((a[i] + 1) * r1, r2);
    dp[i][0] =
        Min(dp[i][0], dp[i - 1][0] + r1 + 3 * d + Min((a[i] + 1) * r1, r2));
    dp[i][1] = d + dp[i - 1][1] + a[i] * r1 + r3;
    dp[i][1] = Min(dp[i][1], d + r1 + dp[i - 1][0] + a[i] * r1 + r3);
    dp[i][1] =
        Min(dp[i][1], d + r1 + dp[i - 1][0] + Min((a[i] + 1) * r1, r2) + r1);
  }
  ans = dp[n][1];
  ans = Min(ans, dp[n - 1][0] + a[n] * r1 + r3 + r1);
  ans = Min(ans, dp[n - 1][0] + Min((a[n] + 1) * r1, r2) + r1 + d + r1);
  printf("%lld", ans);
}
