#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  string t;
  cin >> s >> t;
  long int n = s.length();
  long int m = t.length();
  long int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      dp[i][j] = dp[i][j + 1] + (s[i] == t[j]) * (dp[i + 1][j + 1] + 1);
      dp[i][j] = dp[i][j] % 1000000007;
    }
  }
  long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i][0];
    ans = ans % 1000000007;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long int t = 1;
  while (t > 0) {
    solve();
    t--;
  }
}
