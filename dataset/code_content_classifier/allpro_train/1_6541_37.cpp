#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int dp[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = a[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    if (dp[i] == 0) {
      continue;
    } else {
      if (dp[i] == dp[i + 1] && dp[i] != 3) {
        dp[i] = 0;
      } else {
        if (dp[i] != dp[i + 1] && dp[i] != 3) {
          dp[i] = dp[i];
        } else if (dp[i] != dp[i + 1] && dp[i] == 3) {
          if (dp[i + 1] != 0) {
            dp[i] = 3 - dp[i + 1];
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == 0) ans++;
  }
  cout << ans << endl;
}
