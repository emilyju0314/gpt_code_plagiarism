#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i;
  for (i = 0; i < n; i++) cin >> a[i];
  long long dp[2][n];
  dp[0][0] = 0;
  dp[1][0] = a[0];
  string rev0;
  cin >> rev0;
  string non_rev0 = rev0;
  reverse(rev0.begin(), rev0.end());
  int flag = 1;
  for (i = 1; i < n; i++) {
    string rev1;
    cin >> rev1;
    if (flag) {
      int ch1 = 0, ch2 = 0;
      string non_rev1 = rev1;
      reverse(rev1.begin(), rev1.end());
      if (rev1.compare(rev0) >= 0 && rev1.compare(non_rev0) >= 0)
        dp[1][i] = min(dp[1][i - 1], dp[0][i - 1]) + a[i];
      else if (rev1.compare(rev0) >= 0)
        dp[1][i] = dp[1][i - 1] + a[i];
      else if (rev1.compare(non_rev0) >= 0)
        dp[1][i] = dp[0][i - 1] + a[i];
      else {
        ch1 = 1;
        dp[1][i] = 1000000000000000;
      }
      if (non_rev1.compare(rev0) >= 0 && non_rev1.compare(non_rev0) >= 0)
        dp[0][i] = min(dp[1][i - 1], dp[0][i - 1]);
      else if (non_rev1.compare(rev0) >= 0)
        dp[0][i] = dp[1][i - 1];
      else if (non_rev1.compare(non_rev0) >= 0)
        dp[0][i] = dp[0][i - 1];
      else {
        ch2 = 1;
        dp[0][i] = 1000000000000000;
      }
      if (ch1 && ch2) {
        flag = 0;
      }
      rev0 = rev1;
      non_rev0 = non_rev1;
    }
  }
  if (!flag || min(dp[0][n - 1], dp[1][n - 1]) >= 1000000000000000)
    cout << -1;
  else
    cout << min(dp[0][n - 1], dp[1][n - 1]);
}
