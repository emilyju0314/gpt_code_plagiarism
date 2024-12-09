#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-6;
int dp[2005][2005], sdp[2005];
char s[2005];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  sdp[0] = dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 1LL * sdp[j] * (s[i] - 'a') % 1000000007;
      for (int pref = 1; pref <= i; pref++) {
        int pk = pref * (n - i + 1);
        if (pk > j) break;
        dp[i][j] =
            (dp[i][j] + 1LL * dp[i - pref][j - pk] * ('z' - s[i])) % 1000000007;
      }
      sdp[j] = (sdp[j] + dp[i][j]) % 1000000007;
    }
  }
  printf("%d\n", sdp[k]);
  return 0;
}
