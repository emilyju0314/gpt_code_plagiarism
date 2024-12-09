#include <bits/stdc++.h>
using namespace std;
int dp[101];
int main() {
  int v1, v2;
  cin >> v1 >> v2;
  int t, d;
  cin >> t >> d;
  dp[1] = v1;
  for (int i = 2; i <= t; i++) {
    dp[i] = dp[i - 1] + d;
  }
  dp[t] = v2;
  for (int i = t - 1; i > 1; i--) {
    dp[i] = min(dp[i], dp[i + 1] + d);
  }
  long long ans = 0;
  for (int i = 1; i <= t; i++) {
    ans += dp[i];
  }
  printf("%lld\n", ans);
}
