#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, c;
  cin >> n >> c;
  vector<int> a(n - 1), b(n - 1);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  long long dp[n][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = c;
  for (int i = 0; i < n - 1; i++) {
    dp[i + 1][0] = min(dp[i][0] + a[i], dp[i][1] + a[i]);
    dp[i + 1][1] = min(dp[i][0] + b[i] + c, dp[i][1] + b[i]);
  }
  for (int i = 0; i < n; i++) cout << min(dp[i][0], dp[i][1]) << " ";
  return 0;
}
