#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const long long MOD = 1000000007;
long long dp[N][N];
int a[N], n, h;
int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n >> h) {
    for (int i = (1); i <= (n); i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = (a[1] == h || a[1] + 1 == h);
    dp[1][1] = (a[1] + 1 == h);
    for (int i = (2); i <= (n + 1); i++) {
      for (int open = (max(0, h - a[i] - 1)); open <= (min(i, h - a[i]));
           open++) {
        if (a[i] + open == h) {
          (dp[i][open]) = ((dp[i][open]) + (dp[i - 1][open])) % MOD;
          if (open > 0)
            (dp[i][open]) = ((dp[i][open]) + (dp[i - 1][open - 1])) % MOD;
        }
        if (a[i] + open + 1 == h) {
          (dp[i][open]) = ((dp[i][open]) + (dp[i - 1][open])) % MOD;
          (dp[i][open]) =
              ((dp[i][open]) + (dp[i - 1][open + 1] * (open + 1))) % MOD;
          (dp[i][open]) = ((dp[i][open]) + (dp[i - 1][open] * open)) % MOD;
        }
      }
    }
    cout << dp[n][0] << endl;
  }
  return 0;
}
