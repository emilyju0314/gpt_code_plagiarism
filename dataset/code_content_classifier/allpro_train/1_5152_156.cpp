#include <bits/stdc++.h>
using namespace std;
const int maxN = 501;
int n, a[maxN], dp[maxN][maxN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int(i) = (0); (i) < (n); ++(i)) cin >> a[i];
  for (int Len = 1; Len <= n; Len++) {
    for (int l = 0; l <= n - Len; l++) {
      int r = l + Len - 1;
      if (l == r)
        dp[l][r] = 1;
      else {
        dp[l][r] = dp[l][r - 1] + 1;
        if (a[l] == a[r]) {
          if (r - l < 3) {
            dp[l][r] = 1;
            continue;
          } else
            dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
        }
        for (int k = l + 1; k < r; k++)
          if (a[k] == a[r]) dp[l][r] = min(dp[l][r], dp[k][r] + dp[l][k - 1]);
      }
    }
  }
  cout << dp[0][n - 1];
  return 0;
}
